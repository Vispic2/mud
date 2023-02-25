//      hubian4.c 湖边小路
inherit ROOM;

void create()
{
	set("short", "湖边小路");
	set("long", @LONG
这是圣湖边的小路。路侧长草没足, 青绿可喜。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"north" : __DIR__"shanjiao",
		"south" : __DIR__"hubian3",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
