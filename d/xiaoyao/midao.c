// midao1.c
inherit ROOM;
void create()
{
	set("short", "秘密通道");
	set("long", @LONG
这是一段又长又黑的秘密通道，隐约可以感觉到四周是冰冷而坚硬的石
壁，你什么了看不清楚，只可以靠摸索着前进。
LONG );
	set("exits", ([
		"out" : __DIR__"qingcaop",
		"down": __DIR__"shishi",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
