// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "见性峰山道");
	set("long", @LONG
你走在见性峰山脊小路上，听着山下庙宇的钟鼓，眼前白云漂
荡，远远看到前面就是峰顶了。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"beiyuedian",
	   "eastup"     : __DIR__"square",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
