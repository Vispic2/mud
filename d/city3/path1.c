// Room: path1.c
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "浣花溪");
	set("long", @LONG
你走在浣花溪岸的小路上，浣花溪水晶莹剔透，岸草如茵，远远
就能闻到水气的清香。许多睡莲散布在溪岸附近，水面飘著数不尽的
浮萍，浮萍下有不少艳红锦鲤穿梭来去。溪岸小路随溪流曲折盘绕，
芳草没足，花飘似海，使人不饮自醉。古人所谓 "如行春郊" ，诚不
我欺。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"path2",
		"east"   : __DIR__"nanheqiaow",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
