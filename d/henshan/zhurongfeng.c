// Room: /d/henshan/zhurongfeng.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "祝融峰");
	set("long", @LONG
 "祝融峰之高" 为衡山大四绝之首。在此俯瞰群峰，尽收眼底。东
望湘江，南及五岭，北瞰洞庭，西视雪山。杜甫望岳诗中有 "祝融五峰
尊，峰峰次低昂。" 韩愈亦以 "祝融万丈拔地起，欲见不见轻烟里" 极
言其高。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "eastdown"   : __DIR__"zhurongdian",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
