// Room: /d/xiangyang/caodi3.c

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进
城了，虽然蒙古兵没来到南门，但肃杀氛围丝毫不减。
LONG );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
