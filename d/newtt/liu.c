#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "柳秀山庄");
	set("long", @LONG
这里站着的人竟然是！！！！！！！
LONG );
	set("exits",([
		"north":__DIR__"wu",
		"south":__DIR__"chang",
			"west":__DIR__"xi1",
				"east":__DIR__"xi2",
	//	"east":__DIR__"za",
	]));
		set("objects", ([
	"/d/newtt/obj/you" :1,
//	"/d/newtt/obj/yeguo" :1,
//	"/d/newtt/obj/wizard" :1,
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
