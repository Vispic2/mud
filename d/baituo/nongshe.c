//nongshe.c
inherit ROOM;

void create()
{
	set("short", "农舍");
	set("long",
	     "这里是一间小农舍，家具很新。看来主人比较富裕。\n"
	);
	set("exits", ([
		"west" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
