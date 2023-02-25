// topd.c 保存所有玩家的排行数据

#include <ansi.h>

//#pragma optimize
//#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

nosave int ok = 0;

void clean_old()
{
	string *ids;
	int i;

	if(!dbase) return;
	ids = keys(dbase);
	for(i=0;i<sizeof(ids);i++)
	{
		if(time()-dbase[ids[i]]["last"] > 86400*30)
			delete(ids[i]);
	}
}

void create()
{
	seteuid(getuid());
	restore();
	set_heart_beat(30);
	clean_old();
}

void remove()
{
	save();
}

void mud_shutdown()
{
	save();
}

public string *all_users()
{
	if(!dbase)
		return 0;
	return keys(dbase);
}

public void map_user(object user)
{
	string name;
	mapping info;
	int i,zhan,armor,damage,zhuanshi,xian;
	object weapon;
	int attack_points,parry_points,dodge_points,party;
	mapping prepare;
	string skill_type;
	zhuanshi=0;
	if(!user)
	return;
	info = ([]);
	name = user->query("id");
	info["balance"] = user->query("balance");
	info["name"] = user->query("name");
	info["per"] = user->query("per");
	info["all_pay"] = user->query("zjvip/all_pay");
	info["tydbl"] = user->query("tydbl");
	info["PKS"] = user->query("combat/PKS");
	info["daoshi_exp"] = user->query("zjvip/daoshi_exp");
	info["dizi_fanli"] = user->query("zjvip/dizi_fanli");
	info["combat_exp"] = user->query("combat_exp");
	info["max_qi"] = user->query("max_qi")+user->query_gain_qi();
	info["max_neili"] = user->query("max_neili");
	info["max_jing"] = user->query("max_jing");
	info["max_jingli"] = user->query("max_jingli");
	info["yuanbao"] = user->query("yuanbao");
	info["jifeng"] = user->query("jifeng");
	info["lunjian"] = user->query("lunjian/pot");
	info["kssm"] = user->query("kssm");
	info["gold"] = MONEY_D->player_carry(user);
	info["last"] = time();
	info["s_last"] = user->query("shimen/last");
	

	
	if(same_week(user->query("shimen/last"),time())!=1)
	{
		if(user&&userp(user)&&user->query("shimen/today")>0)
		//log_files("shimentop",sprintf("记录2%s：(玩家)%s(%s)上次师门时间%d现在时间%d清空了%d次师门任务\n",ctime(time()),user->query("name"),user->query("id"),user->query("shimen/last"),time(),user->query("shimen/today")));
		user->set("shimen/today",0);
		user->set("shimen/last",time());
	}
	if(i=user->query("shimen/today"))
	info["shimen"]=i;
	else info["shimen"]=0;
	set(name,info);
}

public void add_shimen(object user)
{
	string name;
	mapping info;

	if( !mapp(dbase ) ) return;
	name = user->query("id");
	if(undefinedp(dbase[name])) return;
	info = dbase[name];
	if(undefinedp(info["shimen"])) info["shimen"]=1;
	else info["shimen"]+=1;
	set(name,info);
}

public void clear_shimen()
{
	string *names;
	int i;

	if( !mapp(dbase ) ) return;
	names = keys(dbase);
	for(i=0;i<sizeof(names);i++)
	{
		set(names[i]+"/shimen",0);
	}
}

mixed set_user(string prop, mixed data)
{
	if( !mapp(dbase ) ) dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( dbase , explode(prop, "/"), data );

	dbase[prop] = data;
	return 1;
}

mixed query_user(string prop)
{
	mixed data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(dbase, explode(prop, "/"));
	else
	{
		data = dbase[prop];
	}

	return data;
}

string get_name(string id)
{
	string data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[id]) )
		data = "无名氏";
	else
	{
		data = dbase[id]["name"];
	}

	return data;
}
void heart_beat()
{
	int GMT = time() + localtime(0)[8];
	string d, times;
	int h, s;

	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分

	if ((d == "Mon") &&(h == 0) &&(s == 0) && !ok) {
		clear_shimen();
		ok = 1;
	} else if (s!=0)
		ok = 0;
	if(s/10==0) save();
}

string query_save_file() { return DATA_DIR "topd"; }

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
