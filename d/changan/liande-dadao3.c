//Room: liande-dadao3.c

inherit ROOM;

void create ()
{
	set ("short", "连德大道");
	set ("long", @LONG
城内街道，以南北三条并行的大街，和东西的二条主街互相交错而
成。五条大街在这清朗的夜初，却见人来车往，灯火通明，别有一番热
闹。其他小街横巷，则依这些主街交错布置，井然有序。
LONG);
	set("exits",([//sizeof() == 2
		"south" : __DIR__"dongan-daokou",
		"north" : __DIR__"liande-dadao2",
	]));

	set("outdoors", "changan");
	setup();
}
	
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
