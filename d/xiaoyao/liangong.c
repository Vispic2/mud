// liangong.c
inherit ROOM;
void create()
{
	set("short", "石屋");
	set("long", @LONG
这是树林中的一间石屋，屋内显得什么清净和简朴，房间中并没有什么
特别的摆设在这里，不会受到任何东西的骚扰，是个修炼内功的好地方。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
