// xiaocun.c 小村庄
// By Lgg,1998.10

inherit BUILD_ROOM;

void create()
{
	set("short", "小村庄");
	set("long", @LONG
这是一片小村庄，隐藏在一个小山坳里。这里的居民们都很少到
城里去，虽然离武功镇不过是五、六里的山路，他们宁愿秉承着男耕
女纺织、日出而作日落而歇的老传统。日子虽然清贫，却还算逍遥。
LONG
	);
	set("max_room", 3);
	set("outdoors", "wugong");
	set("exits", ([
		"northwest" : __DIR__"guchang",
		"southdown" : __DIR__"shanlu1",
	]));
	setup();
	replace_program(BUILD_ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
