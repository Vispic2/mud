//      zoulang3.c 走廊
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是雪山寺内的走廊。这里有点幽暗，天花板上有
一些不知道确切含义的雕刻，墙壁上则是很通俗的佛经故
事壁画了。壁上点着几碗大海灯照明。
LONG );
	set("exits", ([
		"north"    : __DIR__"neidian",
		"eastdown" : __DIR__"zoulang1",
		"westdown" : __DIR__"zoulang2",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
