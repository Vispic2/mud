// minju3.c 民居
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一所乡间民居，桌椅都很旧了，而且看得出来是自己敲敲打打
给拼补下来的，不过擦拭得很干净。墙壁上斜倚着一支猎叉，也许这家
的主人还是个捕猎高手。
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"guchang",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
