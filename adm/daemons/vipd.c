// usersd.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping vips;
mapping qiandao;
mapping paym;
mapping gift_payrec;
mapping vdata;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() )
	{
		vips= ([]);
		qiandao = ([]);
		vdata = ([]);
	}
	if( !mapp(vips) )
		vips = ([]);
	if( !mapp(qiandao) )
		qiandao = ([]);
	if( !mapp(vdata) )
		vdata = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "vipd"; }

int add_order(string name)
{
	if( undefinedp(vips["order"]) ) vips["order"]=({});
	vips["order"] += ({name});
	save();
	return 1;
}

int delete_order(string name)
{
	vips["order"] -= ({name});
	save();
	return 1;
}

mixed set_vips(string prop, mixed data)
{
	if( !mapp(vips ) ) vips = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( vips , explode(prop, "/"), data );

	return vips[prop] = data;
}

mixed query_vips(string prop)
{
	mixed data;

	if( !mapp(vips) ) return 0;

	if( undefinedp(vips[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(vips, explode(prop, "/"));
	else
		data = vips[prop];

	return data;
}
mixed set_qian(string prop, mixed data)
{
	if( !mapp(qiandao ) ) qiandao = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( qiandao , explode(prop, "/"), data );

	return qiandao[prop] = data;
}

mixed query_qian(string prop)
{
	mixed data;

	if( !mapp(qiandao) ) return 0;

	if( undefinedp(qiandao[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(qiandao, explode(prop, "/"));
	else
		data = qiandao[prop];

	return data;
}
mixed set_gift_payrec(string prop, mixed data)
{
	if( !mapp(gift_payrec) ) gift_payrec = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( gift_payrec , explode(prop, "/"), data );

	return gift_payrec[prop] = data;
}

mixed query_gift_payrec(string prop)
{
	mixed data;

	if( !mapp(gift_payrec) ) return 0;

	if( undefinedp(gift_payrec[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(gift_payrec, explode(prop, "/"));
	else
		data = gift_payrec[prop];

	return data;
}

mixed set_paym(string prop, mixed data)
{
	if( !mapp(paym) ) paym = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( paym , explode(prop, "/"), data );

	return paym[prop] = data;
}

mixed query_paym(string prop)
{
	mixed data;

	if( !mapp(paym) ) return 0;

	if( undefinedp(paym[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(paym, explode(prop, "/"));
	else
		data = paym[prop];

	return data;
}

int add_paym(string t,mapping paym)
{
	set_paym(t,paym);
	save();
	return 1;
}

int save_vdata(object me)
{
	vdata[me->query("id")] = ([]);
	vdata[me->query("id")]["yuanbao"] = me->query("yuanbao");
	vdata[me->query("id")]["vtime"] = me->query("zjvip/times");
	vdata[me->query("id")]["all_pay"] = me->query("zjvip/all_pay");
	save();
	return 1;
}

int restore_vdata(object me)
{
	if(undefinedp(vdata[me->query("id")])) return 1;

	me->set("yuanbao",vdata[me->query("id")]["yuanbao"]);
	me->set("zjvip/times",vdata[me->query("id")]["vtime"]);
	me->set("zjvip/all_pay",vdata[me->query("id")]["all_pay"]);
	map_delete(vdata,me->query("id"));
	save();
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
