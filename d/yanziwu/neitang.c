//room: neitang.c
inherit ROOM;

void create()
{
	set("short","内堂");
	set("long",@LONG
这是一间雅致的内堂，布置简单而典雅。里面站着个一身淡绿的女
郎，向着你似笑非笑。似乎是江南灵秀造了这样一个小美人。
LONG );
	set("exits",([
	    "north" : __DIR__"qinyun",
	]));
	set("objects",([
	     __DIR__"npc/abi" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
