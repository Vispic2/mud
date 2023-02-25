// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIR"高级区入口"NOR);
	set("long", "经验条件1000-3000w");
	set("exits", ([
	"south" : "d/zhenhun/enter",
	"north" : __DIR__"gaoji1",
	]));
	set("objects", ([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me-> query("combat_exp") < 10000000)
		return notify_fail(HIY"只有1000w才可进入！！\n"NOR);
	return ::valid_leave(me, dir);
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
