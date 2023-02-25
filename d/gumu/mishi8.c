// mishi8.c 密室
inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯
光来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，
你难以从中找出一丝缝隙。密室中摆放着一些简单的家居用具，原来
这是古墓派祖师林朝英的居室。
LONG
	);

	set("exits", ([
		"west" : __DIR__"mishi7",
		"out" : "/d/city/guangchang",
	]));

	set("objects", ([
		CLASS_D("gumu") + "/lin" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
