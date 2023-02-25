// chanfang2.c 禅房
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是全真弟子修身养性、打熬气力的地方。为了方便练功，桌
椅都没有摆放，仅仅在地下丢了几个小蒲团。
LONG
	);
	set("exits", ([
		"east" : __DIR__"chanfang3",
		"west" : __DIR__"chanfang1",
		"south" : __DIR__"liangong",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
