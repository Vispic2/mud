// Room: /xiakedao/shidong5.c

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是一个石洞，四周点着八盏油灯，使得整个房间非常明亮。山
洞中支路甚多，你可要小心，别走错了路。
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"dating",
		"north" : __DIR__"yingbin",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
