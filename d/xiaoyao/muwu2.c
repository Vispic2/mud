// muwu2.c
inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
这是一间不是很大的木头屋子，这里看起来象个药室，室中摆放着各种
不同的配药的用具和一些已经配好了的药。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		CLASS_D("xiaoyao") + "/xuemuh" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
