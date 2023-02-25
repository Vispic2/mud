// baimatang.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "白马潭");
	set("long", @LONG
这个潭为於终南山主峰一带，一条名叫库峪河的上游。潭边有一
块比三间房子还要大的白石头，这石头中间低两头高，石头的前半截
伸在水里，後半截留在岸上。由伸在水中的那半截石头下面还不时冒
出一串串白沫，老远看去活似一匹腾空欲飞的烈马，因此当地人都叫
此潭为白马潭。往北是一条崎岖的山路。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"northup" : __DIR__"shanlu6",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
