// by ranger_游侠
// wanan.c

inherit ROOM;

void create()
{
	set("short", "万安寺");
	set("long", "这里是万安寺。");
	set("exits", ([
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		"/clone/fuben/wanansi/npc/kutoutuo": 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
