// sroad1.c
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
川西多是崇山峻岭，交通不便。一条山路蜿蜒在山间，连接着
藏边和中原。
LONG );
	set("exits", ([
		"north"  : "/d/city3/nanheqiaos",

     //   "south" : "/d/tangmen/bdajie2",
		"westup" : __DIR__"sroad2",
	]));
	set("outdoors", "xuedao");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
