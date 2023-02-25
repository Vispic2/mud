// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "副本入口");
	set("long", @LONG
这里就是十三黄陵副本了。
LONG
	);
	set("exits", ([
		"east" : __DIR__"h2",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	string fb_id;
	
	if (userp(me) && dir == "out") {
		me->delete_temp("zxt_again");
		if (fb_id = me->query_temp("fuben_path"))
			FUBEN_D->des_fuben(fb_id, 1);
	}
	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
