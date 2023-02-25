// xilang.c 西厢走廊
// by Xiang

inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
你走在一条走廊上，东边是大殿，北边是一座楼阁。西面楼上传来
阵阵打斗声。
LONG );
	set("exits", ([
		"northup" : __DIR__"cangjingge",
		"east"    : __DIR__"sanqingdian",
		"westup"  : __DIR__"caolianfang",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
