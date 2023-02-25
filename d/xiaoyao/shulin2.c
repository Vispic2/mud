// shulin2.c
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
LONG );
	set("exits", ([
	       "north" : __DIR__"shulin3",
	       "south" : __DIR__"shulin1",
	       "east" : __DIR__"shulin2",
	       "west" : __DIR__"shulin2",
	]));
	set("outdoors", "xiaoyao");
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
