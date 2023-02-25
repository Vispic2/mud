
inherit ROOM;

void create()
{
	set("short", "房舍");
	set("long", @LONG
这里是一间小屋，一个太监正在这里休息。
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang1",
	]));
	set("objects", ([
		"/d/huanggon/npc/taijian":1,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
