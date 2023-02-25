// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIY"中级区入口");
	set("long", "经验限制300-800w");
	set("exits", ([
    "west" : "d/zhenhun/enter",
	"north" : __DIR__"zhongji1"
	]));
	set("objects", ([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" &&  me->query("combat_exp") < 3000000)
		return notify_fail(HIY"只有300w才可进入！！\n"NOR);
	return ::valid_leave(me, dir);
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
