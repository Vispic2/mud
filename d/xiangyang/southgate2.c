// Room: /d/xiangyang/southgate2.c
inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "朱雀外门");
	set("long", 
"这里是襄阳城的南城门，只见城门上方是三个大字。"HIR"

		      朱雀门
"NOR"\n"
"近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵
们正在盘查要离襄阳城的人。两边是很大的草地。\n"
 );
	set("outdoors", "xiangyang");

	set("exits", ([
		"east"   : __DIR__"caodi4",
		"west"   : __DIR__"caodi5",
		"south"  : __DIR__"caodi6",
		"north"  : __DIR__"southgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
