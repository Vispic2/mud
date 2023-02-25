// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIG"初级区入口"NOR);
	set("long", "经验限制200w以下");
	set("exits", ([
	"east" : "d/zhenhun/enter",
	"north" : __DIR__"chuji1",
	]));
	set("objects", ([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me->query("combat_exp")<2000000)
		return notify_fail(HIY"200w经验才能进入！！！\n"NOR);
	return ::valid_leave(me, dir);
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
