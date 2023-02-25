// juyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "老妪岩");
	set("long", @LONG
一路过来，山路是越来越险。只见一块大岩石挡在路中，自空凭
临，宛似一个老妇弯腰俯视，但形状阴森可怖，令人望而生畏。不少
游客在此驻足观看，往南是一片茂密的松林。往北上是一条陡峭的山
路。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"northup"    : __DIR__"shanlu8",
		"southdown"  : __DIR__"shulin7",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/ji": 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
