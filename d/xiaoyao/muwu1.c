// muwu1.c
inherit ROOM;

void create()
{
	set("short", "木屋");
	set("long", @LONG
这里是一间不大的木头屋子，但是麻雀虽小，五藏俱全，屋子中只是疏
疏落落地摆着几件家具，所以也不显得怎么小。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao5",
	]));
 	set("objects", ([
		CLASS_D("xiaoyao") + "/kanggl": 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
