#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "集镇广场");
	set("long", @LONG
这里是个并不繁荣，却显得极为安详的小镇，每个人脸上都是没有忧愁的笑脸，小道边时常有剑士侠客经过，快进去看看吧。
LONG );
	set("exits",([
		"north":__DIR__"jizhen1",
		"west":__DIR__"xinglin1",
		"east":__DIR__"za",
			"south":__DIR__"huanpo",
	]));
	set("action_list",([
//		"查看窗户":"look window",
	]));
	setup();
}




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
