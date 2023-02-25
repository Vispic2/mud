// ansuan.c 暗算
//by King 97.05

#include <ansi.h>

mapping default_where = ([
	"n":	"north",
	"s":	"south",
	"e":	"east",
	"w":	"west",
	"nu":	"northup",
	"su":	"southup",
	"eu":	"eastup",
	"wu":	"westup",
	"nd":	"northdown",
	"sd":	"southdown",
	"ed":	"eastdown",
	"wd":	"westdown",
	"ne":	"northeast",
	"nw":	"northwest",
	"se":	"southeast",
	"sw":	"southwest",
	"u":	"up",
	"d":	"down",
]);

mapping default_dirs = ([
	"north":		"北边",
	"south":		"南边",
	"east":			"东边",
	"west":			"西边",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":		"北边",
	"southdown":		"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":		"东北",
	"northwest":		"西北",
	"southeast":		"东南",
	"southwest":		"西南",
	"up":			"上面",
	"down":			"下面",
	"enter":		"里面",
	"out":			"外面",
]);

mapping default_undirs = ([
	"south":		"北边",
	"north":		"南边",
	"west":			"东边",
	"east":			"西边",
	"southup":		"北边",
	"northup":		"南边",
	"westup":		"东边",
	"eastup":		"西边",
	"southdown":		"北边",
	"northdown":		"南边",
	"westdown":		"东边",
	"eastdown":		"西边",
	"southwest":		"东北",
	"southeast":		"西北",
	"northwest":		"东南",
	"northeast":		"西南",
	"down":			"上面",
	"up":			"下面",
	"out":			"里面",
	"enter":		"外面",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp;
	object env, old_env;
	mapping exits;
	object target;
	int count;
	string gen;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
		return notify_fail("指令格式：ansuan <人物> at <方向>\n");

	env = environment(me);
	old_env = env;
	if( where_temp == "leitai" )
		return notify_fail("那里禁止暗算。\n");


	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else
		where = where_temp;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
        return notify_fail("由于你没有心跳，请重新登陆!!\n");
//         write("由于你没有心跳，请重新登陆!!\n");
        }

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("没有这个方向。\n");

	if( !objectp(env = find_object(exits[where])) )
	{	call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if( env->query("no_fight") )
		return notify_fail("那里禁止战斗。\n");

	if( env->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用暗算。\n");


	if( !objectp(target = present(who, env)) )
		return notify_fail("这个方向没有此人。\n");

	if( !target->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

        if (userp(target) && !query_heart_beat(target))
        {
         write("你想做什么！\n");
        return notify_fail("此人无心跳！\n");
//         write("此人不能beg！\n");
        }

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能暗算。\n");

	if( me->is_fighting() )
		return notify_fail("你正忙着战斗呢，还有心思暗算别人？\n");

	if( !living(target) )
		return notify_fail(target->name() + "都已经这样了，你还用得着暗算吗？\n"); 

	if((int)target->query("age") <= 17 && userp(target))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");

	if(target->query_temp("no_kill"))
		return notify_fail("你不能杀这个人。\n");

	if( (int)me->query("jing", 1) < 100 )
		return notify_fail("你无法集中精力，暗算不了别人。\n");

	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where];
	else
		dir = where;

	if( !undefinedp(default_undirs[where]) )
		undir = default_undirs[where];
	else
		undir = where;

	if(me->query("gender") == "女性")
		gen = "倩影";
	else
		gen = "人影";

	write( CYN"你摒息静气，纵身而起，向" + dir + "的" + target->name() + "扑去！\n"NOR);
	message("vision", CYN"\n一条" + gen + "忽然向" + dir + "扑去，转眼间又回到原处！\n\n"NOR, environment(me), me);
	tell_object(target, CYN"\n一条" + gen + "忽然从" + undir + "向你扑来！\n\n"NOR);
	message("vision", CYN"\n一条" + gen + "忽然从" + undir + "向" + target->name() + "扑来！\n\n"NOR, environment(target), target);

	count = me->query_str();

//	me->set_temp("apply/name", ({gen}));
//	me->set_temp("apply/id", ({"none"}));
//	me->set_temp("apply/short", ({gen}));
//	me->set_temp("apply/long", ({gen}));

	me->move(environment(target));
        me->add_temp("str", count);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
        me->kill_ob(target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		message_vision(CYN"$N一时没有防范，被$n攻了个措手不及！\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
	}
	else
	{
		message_vision(CYN"$N经验丰富，不及细看，立刻向$n反击！\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon") );
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
	}

	me->add_temp("str", - count);

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/5 )
	{
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"你一定神，原来是" + me->name() + "在暗算我！\n"NOR);
		write( CYN "不好，被" + target->name() + "发觉了！\n"NOR);
		message_vision(CYN"$N喝道：$n！你敢暗算我，我跟你没完！\n"NOR, target, me);
		if( !target->is_killing(me) ) target->kill_ob(me);
		me->start_busy(3);
	}

	else
	{
		message("vision", CYN"\n" + gen + "转瞬不见！\n\n"NOR, environment(target), me);
		tell_object(me, CYN"\n你立刻退回原处！\n\n"NOR);

		me->move(old_env);

		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"你一定神，可是什么都没看见。\n"NOR);
		message("vision", CYN"" + target->name() + "一脸惶恐，竟不知道谁在暗算他！\n"NOR, environment(target), target);
		write( CYN "哈哈，" + target->name() + "居然没看出来。\n"NOR);
		write( CYN"你措了措手，一脸无辜的样子。\n"NOR);
	}

	me->start_busy(3);
	me->add("jing", -50);
	/*
        if( userp(me) )
                //log_files("ansuan_player", sprintf("[%s] %s ansuan %s\n",
                        ctime(time()), geteuid(me), target->query("id")));
//                        ctime(time()), geteuid(me), geteuid(target)));
*/
        return 1;
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

}

int help(object me)
{
write(@HELP
指令格式 : ansuan <人物> at <方向>

这个指令让你暗算位于<方向>的<人物>。
如果暗算成功，则敌人发现不了你。否则...:)
HELP
    );
    return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
