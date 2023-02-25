// Room: /d/henshan/jiayingmen.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "嘉应门");
	set("long", @LONG
这里是地方官迎接京师御史官来祭南岳的地方，是南岳大庙第五进
门了。门上雕塑也较精细些，悬彩灯笼时时换新。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "south"  : __DIR__"yubeiting",
	   "north"  : __DIR__"yushulou",
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
