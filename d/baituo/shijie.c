//shijie.c
inherit ROOM;

void create()
{
	set("short","石阶");
	set("long",@TEXT
你走在青石板铺成的石阶上。这里就是传说中神秘的白驼山。远远
望去，两座白沙堆积形成的山峰好像一只骆驼的脊背。一座山门立在你
的眼前。
TEXT );
	set("exits",([
		"east" : __DIR__"caoping",
		"northup" : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
