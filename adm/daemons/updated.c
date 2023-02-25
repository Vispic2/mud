// updated.c

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <room.h>
#include <login.h>

inherit F_SAVE;

// data need save
mixed title_base;

string query_save_file() { return DATA_DIR "pinfo"; }

void remove_title(object ob);
void set_title(object ob);
object global_find_player(string user);
void global_destruct_player(object ob, int raw);

void create()
{
	seteuid(ROOT_UID);
	restore();

	if (arrayp(title_base))
		title_base = filter_array(title_base, (: arrayp($1) && sizeof($1) == 2 :));
	else
		title_base = 0;
}

#define LUBAN	   "/adm/npc/luban"
#define RING_DIR	"/data/item/ring/"

// check the user's data when login
void check_user(object ob)
{
	mapping my;
	mapping skill_status;
	string *sname;
	int combat_exp;
	int level;
	int i;
	mapping party;

	my = ob->query_entire_dbase();

	if (ob->query("family/generation") == 0)
		ob->delete("family");

	if (ob->query("gender") == "无性")
		ob->set("class", "eunach");

	if ((int)ob->query("combat/today/which_day") != time() / 86400)
		ob->delete("combat/today");

	if (ob->query("couple") && ! ob->query("static/marry"))
		ob->set("static/marry", 1);

	if (mapp(party = my["party"]) && stringp(party["party_name"]))
		party["party_name"] = filter_color(party["party_name"]);

	// 记录名字
	NAME_D->map_name(ob->query("name"), ob->query("id"));

	// 重新设置运行计时器
	reset_eval_cost();

	// 赋予称号
	set_title(ob);

	// 更新数据
	if (arrayp(my["channels"]))
	{
		for (i = 0; i < sizeof(my["channels"]); i++)
			if (my["channels"][i] == "sing") my["channels"][i] = "sos";
	}

	if (undefinedp(my["eff_jing"]))  my["eff_jing"] = my["max_jing"];
	if (undefinedp(my["eff_qi"])) my["eff_qi"] = my["max_qi"];
	if (my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
	if (my["eff_qi"] > (my["max_qi"]+ob->query_gain_qi())) my["eff_qi"] = my["max_qi"]+ob->query_gain_qi();
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["neili"] > my["max_neili"] * 2) my["neili"] = my["max_neili"] * 2;

	combat_exp = (int)ob->query("combat_exp");
	if (! mapp(skill_status = ob->query_skills()))
	return;
	sname  = keys(skill_status);


}



// clear the user's data
// when catalog parameter equal to "all", I will remove all
// the informatino of this user. This may be used when the
// user was purged.
string clear_user_data(string user, string cat)
{
	object login_ob;
	object ob;
	string couple_id;
	string path, file_name;
	string *dirs;
	object temp;
	string brothers;
	string bro_id;
	string *ks;
	mapping bro;
	int flag;
	int i;

	// only root uid can does it
	if (previous_object() &&
	    getuid(previous_object()) != ROOT_UID &&
	    geteuid(previous_object()) != user)
		return "你无权清除该玩家的数据。\n";

	// find the user's body
	seteuid(getuid());
	login_ob = 0;
	ob = find_player(user);
	if (! ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return "暂时无法生成玩家对象。\n";
		}

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return "没有这个玩家。\n";
		}

		ob->setup();
	}

	// no catalog? treat it as "all"
	if (! cat) cat = "all";
	flag = 0;

	// remove name information
	if (cat == "name" || cat == "all")
		NAME_D->remove_name(ob->query("name"), ob->query("id"));

	// remove room information
	if ((cat == "room" || cat == "all") &&
	    mapp(ob->query("private_room")))
	{
		// Demolish the room of the user
		LUBAN->demolish_room(ob);
		flag++;
	}

	// remove balance information
	if (cat == "balance" || cat == "all")
		ob->set("balance", 0);

	// remove marriage information
	if ((cat == "couple" || cat == "all") &&
	    mapp(ob->query("couple")))
	{
		// clear the couple infomation

		// remove the ring
		file_name = RING_DIR + ob->query("id");
		if (file_size(file_name + ".c") > 0)
		{
			if (temp = find_object(file_name))
			{
				if (environment(temp))
				{
					message("vision", HIM + temp->name() +
						HIM "忽然化作一缕清烟，不见了！"NOR"\n",
						environment(temp));
				}
			}
			DBASE_D->clear_object(file_name);
		}

		couple_id = ob->query("couple/id");
		ob->delete("couple");
		ob->delete("can_summon/wedding ring");
		if (! sizeof(ob->query("can_summon")))
			ob->delete("can_summon");
		flag++;
		if (couple_id) clear_user_data(couple_id, "couple");
	}

	// remove item information
	if (cat == "item" || cat == "all")
	{
		object item;
		mapping sum;

		// clear the all item
		path = ITEM_DIR + ob->query("id")[0..0] + "/";
		dirs = get_dir(path + ob->query("id") + "-*");
		for (i = 0; i < sizeof(dirs); i++)
		{
			file_name = path + dirs[i];
			if ((item = find_object(file_name)) &&
			    environment(item))
			{
				message("vision", HIM + item->name() +
					"忽然化作一股轻烟，不见了！"NOR"\n",
					environment(item));
			}

			// rememberd by doing, for keep the item'sdata in dbased
			// DBASE_D->clear_object(file_name);
			rm(file_name);
		}

		if (mapp(sum = ob->query("can_summon")))
		{
			// clear summon information
			ks = keys(sum);
			for (i = 0; i < sizeof(ks); i++)
				if (sscanf(sum[ks[i]], path + ob->query("id") + "-%*s") == 1)
					map_delete(sum, ks[i]);

			if (! sizeof(sum))
				ob->delete("can_summon");
		}
	}

	// remove board information
	if (cat == "board" || cat == "all")
	{
		object *rooms;
		rooms = filter_array(children(CHAT_ROOM),
				     (: clonep($1) && $1->query("owner_id") == $(user) :));
		for (i = 0; i < sizeof(rooms); i++)
			destruct(rooms[i]);
		file_name = DATA_DIR + "board/chatroom_" + user + __SAVE_EXTENSION__;
		rm(file_name);
	}

	if (cat == "hatred" || cat == "all")
	{
		FAMILY_D->remove_hatred(ob->query("id"));
		LEAGUE_D->remove_hatred(ob->query("id"));
	}

	if (mapp(bro = ob->query("brothers")) &&
	    (sscanf(cat, "brothers:%s", brothers) == 1 || cat == "all"))
	{
		if (cat == "all") brothers = "all";

		if (brothers == "all")
		{
			foreach (bro_id in keys(bro))
				clear_user_data(bro_id, "brothers:" + ob->query("id"));

			ob->delete("brothers");
		} else
		if (! undefinedp(bro[brothers]) != -1)
		{
			map_delete(bro, brothers);
			if (sizeof(bro) < 1)
				ob->delete("brothers");
			else
				ob->set("brothers", bro);
		}
		flag++;
	}

	if (cat == "league" || cat == "all")
	{
		LEAGUE_D->remove_member_from_league(ob);
		ob->delete("league");
	}

	if (cat == "title" || cat == "all")
		remove_title(ob);

	// remove granted information
	if (cat == "grant" || cat == "all")
		SECURITY_D->remove_grant(ob, "*");

	// save the data of the user
	if (flag) ob->save();

	// Destrut the object if create temporate
	if (login_ob)
	{
		catch(destruct(login_ob));
		catch(destruct(ob));
	}

	return "成功。\n";
}

// remove an user
string remove_user(string user)
{
	object ob;
	string result;

	// destruct the user object
	if (ob = find_player(user))
	{
		if (ob->query_temp("link_ob"))
			catch(destruct(ob->query_temp("link_ob")));
		catch(destruct(ob));
	}  

	// Remove the user from wizlist if the user was wizard
	SECURITY_D->set_status(user, "(player)");

	// Remove the user's grant inforamtion
	SECURITY_D->remove_grant(user, "*");

	// clear the data of user first
	result = clear_user_data(user, "all");

	// remove the file of the user
	rm(DATA_DIR + "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "baibao/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "sc/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "pet/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
}

void init_player(object me)
{
	string *dbs;
	int i;
	object *inv;
	mapping my;
	mapping db = ([
		"str":10,
		"dex":10,
		"con":10,
		"int":10,
		"kar":10,
		"per":10,
		"gender":me->query("gender"),
		"id":me->query("id"),
		"surname":me->query("surname"),
		"purename":me->query("purename"),
		"name":me->query("name"),
		"title":"普通百姓",
		"birthday":time(),
		"potential":99,
		"food":200,
		"water":200,
		"channels":({ "chat", "rumor", "party","bill", "sos", "family","ic", "rultra" }),
		"env/wimpy":60,
		"zjvip":me->query("zjvip"),
		"yuanbao":me->query("yuanbao"),
	]);
	my = me->query_entire_dbase();
	dbs = keys(my);
	for(i=0;i<sizeof(dbs);i++)
	{
		if(db[dbs[i]])
			me->set(dbs[i],db[dbs[i]]);
		else
			me->delete(dbs[i]);
	}
	me->clear_all_skill();
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("equipped"))
			inv[i]->unequip();
		destruct(inv[i]);
	}
	me->set("startroom", REGISTER_ROOM);
	me->move(REGISTER_ROOM);
	me->save();
}

// user born
void born_player(object me)
{
	mixed files;
	int i;
	string special;
	string msg;

	msg = HIG "你的天赋技能有：" NOR;

	// 查看所有的特殊技能文件
	files = get_dir("/kungfu/special/");
	me->delete("special_skill");

	if (sizeof(files))
	{
		// 整理所有的技能文件
		for (i = 0; i < sizeof(files); i++)
			sscanf(files[i], "%s.c", files[i]);

		// 先天容貌 < 20 不会驻颜
		if (me->query("per") < 20)
			files -= ({ "youth" });

		  //女性不会鬼脉
		  if(me->query("gender") == "女性")
			   files -= ({ "ghost" });

		// 获得第一项技能
		special = files[random(sizeof(files))];
		me->set("special_skill/" + special, 1);
		msg += SPECIAL_D(special)->name();

		files -= ({ special });
		if ((sizeof(files) && random(30) == 1 && me->query("combat_exp") > 1)|| me->query_temp("born_skill2"))
		{
			// 获得第二项技能
                        me->delete_temp("born_skill2");
			special = files[random(sizeof(files))];
			me->set("special_skill/" + special, 1);
			msg += HIG "、" NOR + SPECIAL_D(special)->name();
			files -= ({ special });
			if ((sizeof(files) && random(10) == 1)|| me->query_temp("born_skill3"))
			{
				// 获得第三项技能
                                me->delete_temp("born_skill3");
				special = files[random(sizeof(files))];
				me->set("special_skill/" + special, 1);
				msg += HIG "、" NOR + SPECIAL_D(special)->name();
			}
		}
		msg += HIG " 。"NOR"\n";
		tell_object(me, msg);
//		me->start_call_out((: call_other, __FILE__,"notice_player", me, msg :), 0);
	}
}

// notice user a piece of message, delay call by born user
void notice_player(object me, string msg)
{
	tell_object(me, msg);
}

// query title dbase
mixed query_title_base()
{
	if (! is_root(previous_object()))
		return 0;

	return title_base;
}

// set title dbase
mixed set_title_base(mixed ts)
{
	if (! is_root(previous_object()))
		return 0;

	title_base = ts;
}
//test eval
// 清除某个玩家的 title
void remove_title(object ob)
{
	int i;

	if (! arrayp(title_base) || ! ob->query("granted_title"))
		return;

	ob->delete_temp("title");
	ob->delete("granted_title");

	for (i = 0; i < sizeof(title_base); i++)
	{
		// 搜索所有的 title
		if (title_base[i][1] == ob->query("id"))
			// 去掉title
			title_base[i][1] = 0;
	}
	save();
	return;
}

// 设置某个玩家的 title
void set_title(object ob)
{
	string id;
	int i;

	if (! arrayp(title_base) || ! ob->query("granted_title"))
		return;

	id = ob->query("id");
	for (i = 0; i < sizeof(title_base); i++)
		if (title_base[i][1] == id)
		{
			// 加上title
			ob->set_temp("title", title_base[i][0]);
			return;
		}

	// 这个用户并没有分配的称号
	ob->delete("granted_title");
}

// 寻找或调入某一个玩家
// 如果程序处理中需要更新那些不在线的玩家，则可以使用该函数
// 将这个玩家调入并且进行修改，请注意：修改完毕以后程序必须
// 保存玩家，并且使用 global_destruct_player 将玩家析构，如
// 果没有调用这个函数，则赋予玩家的定时器会自动析构玩家。
object global_find_player(string user)
{
	object ob;
	object login_ob;

	ob = find_player(user);
	if (! ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return 0;
		}

		evaluate(bind((: seteuid(getuid()) :), ob));

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return 0;
		}

		ob->set_temp("temp_loaded", 1);
		ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
		catch(destruct(login_ob));
	}

	return ob;
}

// 析构一个被 UPDATE_D 调入的玩家
void global_destruct_player(object ob, int raw)
{
	if (objectp(ob) && ob->query_temp("temp_loaded"))
	{
		if (raw) ob->save();
		destruct(ob);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
