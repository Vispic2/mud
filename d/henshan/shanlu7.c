// Room: /d/henshan/shanlu7.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。山路东西通向磨镜台和天柱峰。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "westup"    : __DIR__"tianzhu",
	   "eastdown"  : __DIR__"mojingtai",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
