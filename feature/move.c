// move.c
#include <tomud.h>
#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <dbase.h>
#include <command.h>

static int weight = 0;
static int encumb = 0, max_encumb = 0;
static int magic_move = 0;
static int in_temp =0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
	object env;
	encumb += w;
	/*
	if (encumb < 0)
		//log_files("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
		*/
	if (encumb > max_encumb) this_object()->over_encumbrance();
	if (env = environment()) env->add_encumbrance(w);
}
int info(object env)
{
	string *dirs,df;
	mapping exits;

	if( mapp(exits = env->query("exits")) )
		dirs = keys(exits);

	if(sizeof(dirs)==1 && sizeof(dirs)!=0)
		write(TMI("bnway "+dirs[0]+";"));
	else if(sizeof(dirs)!=0)
		write(TMI( sprintf("bnway "+"%s;",implode(dirs[0..sizeof(dirs)], ";")) ));
	return 1;
}
void over_encumbrance()
{
	if (! interactive(this_object())) return;
	tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
	if (! environment())
	{
		weight = w;
		return;
	}
	if (w != weight) environment()->add_encumbrance(w - weight);
	weight = w;
}

nomask int weight() { return weight + encumb; }
nomask int is_magic_move() { return magic_move; }
nomask int set_magic_move() { magic_move = 1; }

varargs int move(mixed dest, int raw)
{
	object ob,*inv,env;
	object me;
	int i,is_char;
	mixed old_target;
	mixed *guards;
	object user;
	object *users;
	mapping objects;

	me = this_object();

	if (! (is_char = me->is_character()) &&
	    query("equipped") && ! me->unequip())
		return notify_fail("你没有办法取下这样东西。\n");

	if (objectp(dest))
		ob = dest;
	else
	if (stringp(dest))
	{
		call_other(dest, "???");
		ob = find_object(dest);
		if (! ob) return notify_fail("move: destination unavailable.\n");
	} else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));

	// 检查目标是否能够包容住该物品
	// 在检查前，我们先检查是否目标OBJ是该物件的环境（或者是它的环境的环境），如果是，那就好象是
	// 从一个玩家身上背着的包里取出一个物品，既然玩家可以背起这个包，那么我们可以想当然的认为他也
	// 可以背起这个OBJ并且超重检查是不必要的。
	env = me;
	while (env = environment(env))
		if (env == ob) break;
	if (! env && (int) (ob->query_encumbrance() + weight()) > (int) ob->query_max_encumbrance())
	{
		if (environment(ob))
		{
			message_vision("由于$n对于$N而言是在是太重了，$N看起来移动都困难了。\n",ob, this_object());
		}
		else if(!playerp(ob))
		{
			return notify_fail(this_object()->name() + "对" + ob->name() + "而言太重了。\n");
		}
	}

	env = environment();
	if (env)
	{
		if (env != ob && magic_move && userp(env))
		{
			if (env->visible(me))
				tell_object(env, HIM "你忽然觉得身上好像轻了一些。"NOR"\n");

			if (userp(me))
			{
				env->add_temp("person_in_you", -1);
				if (env->query_temp("person_in_you") <= 0)
					env->delete_temp("person_in_you");
			}
		}

		if (! is_char && env->query_temp("handing") == me)
			env->delete_temp("handing");
	}

	old_target = query_temp("guardfor");

	if (objectp(old_target) && ! old_target->is_character())
	{
		if (arrayp(guards = old_target->query_temp("guarded")))
		{
			guards -= ({ me });
			if (! sizeof(guards))
			{
				old_target->delete_temp("guarded");
			} else
				old_target->set_temp("guarded", guards);
		}
		me->delete_temp("guardfor");
	} else
	if (stringp(old_target))
	{
		guards = env->query_temp("guarded/" + old_target);
		if (arrayp(guards))
		{
			guards -= ({ me });
			if (! sizeof(guards))
			{
				env->delete_temp("guarded/" + old_target);
			} else
				env->set_temp("guarded/" +old_target, guards);
		}
		me->delete_temp("guardfor");
	}

	if (is_char && interactive(me) && living(me) && !raw)
	{
		LOOK_CMD->look_room(me, ob, query("env/brief"));
	}

	if (magic_move && userp(ob))
	{
		if (ob->visible(this_object()))
			tell_object(ob, HIM "你忽然觉得身上好像重了一些。"NOR"\n");

		if (userp(this_object()))
			ob->add_temp("person_in_you", 1);
	}
	magic_move = 0;

	if(!wizardp(this_object())||!query("env/invisible"))
	{
		if (env)
		{
			env->add_encumbrance(-weight());
		}
		if (ob)
		{
			ob->add_encumbrance(weight());
		}
	}
	move_object(ob);

	if(ob->is_room()&&!this_object()->is_character())
	{
		objects = ob->query("objects");
		if(!mapp(objects)||!objects[base_name(this_object())])
		{
			remove_call_out("clean_me");
			call_out("clean_me",120);
		}
	}

	if(env)
	{
		inv = all_inventory(env);
		for(i=0;i<sizeof(inv);i++)
		{
			if(userp(inv[i]))
				tell_object(inv[i],ZJOBOUT"look "+file_name(this_object())+"\n");
		}
	}
	inv = all_inventory(ob);
	for(i=0;i<sizeof(inv);i++)
	{
		if(userp(inv[i])&&(inv[i]!=me))
		{
		
			if(playerp(me))
				tell_object(inv[i],ZJOBIN+HIC+me->name()+NOR":look "+file_name(this_object())+"\n");
			else
				tell_object(inv[i],ZJOBIN+me->name()+":look "+file_name(this_object())+"\n");
		
		}
	}
	return 1;
}

void remove(string euid)
{
	object me;
	object ob;
	object default_ob;
	object user;
	object *users;

	if (! previous_object() ||
	    base_name(previous_object()) != SIMUL_EFUN_OB)
		error("move: remove() can only be called by destruct() simul efun.\n");

	me = this_object();
	if (userp(me) && euid != ROOT_UID)
	{
	    	if (euid != getuid(me))
		{
			// Failed to destruct
			////log_files("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
				// euid, this_object()->query("id"),
				 //ctime(time())));
			error("你(" + euid + ")不能摧毁其他的使用者。\n");
		}
		////log_files("destruct", sprintf("%s in %O destruct on %s.\n",
					     //me->query("id"),
					   //  environment(me),
					//     ctime(time())));
		error("只有ROOT才能摧毁玩家。\n");
	} else
	if (me->query("equipped"))
	{
		// Failed to unequip, only log but continue
		//if (! me->unequip())
			////log_files("destruct", sprintf("Failed to unequip %s when destructed.\n",
						    // file_name(me)));
	}

	if (me->is_ob_saved())
		me->save();

	// Leave environment
	if (objectp(ob = environment()))
	{
		ob->add_encumbrance(-weight());

		if (ob->is_character() && ob->query_temp("handing") == me)
			// remove handing when destruct the object
			ob->delete_temp("handing");

		if (is_magic_move() && userp(ob))
		{
			if (ob->visible(this_object()))
				tell_object(ob, HIM "你忽然觉得身上好像轻了一些。"NOR"\n");

			if (userp(me))
			{
				// One user enter another user
				ob->add_temp("person_in_you", -1);
				if (ob->query_temp("person_in_you") <= 0)
					ob->delete_temp("person_in_you");
			}
		}
	}

	if (default_ob = me->query_default_object())
		default_ob->add("no_clean_up", -1);

	me->end_log();
}

void move_or_destruct(object dest)
{
	if (userp(this_object()))
	{
		tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
		move(VOID_OB);
	} else
	if (this_object()->is_ob_saved())
		this_object()->save();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
