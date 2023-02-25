//cedong.c

inherit ROOM;

void create()
{
	set("short", "侧洞");
	set("long",
	     "这里是一个小小的侧洞，里面有张梳妆台，上边摆放着一些女人的用品。\n"
	);
	set("exits", ([
		"east" : __DIR__"dongnei",
	]));
	set("objects",([
		__DIR__"npc/jinhua" : 1,
	]));
//	set("no_clean_up", 0);

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
