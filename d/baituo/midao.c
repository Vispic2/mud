//midao.c

inherit ROOM;

void create()
{
	set("short","密道");
	set("long","这里是漆黑的密道，当年白驼山弟子为了直达中原而挖凿的。\n"); 
	set("exits" , ([
		"east" : "/d/city/beidajie1",
	]));
	set("objects",([
		__DIR__"obj/shenshe" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
