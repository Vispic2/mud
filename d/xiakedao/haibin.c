// Room: /d/xiakedao/hanbin.c

inherit BUILD_ROOM;

void create()
{
	set("short", "南海之滨");
	set("long", @LONG
这里就是大陆的南端，向南望去是一望无际的碧海，与辽阔的蓝
天相映，让人顿生渺小之感。湛蓝海水、岸边礁石、浪拍沙滩卷起层
层细沫，或有阳光绕出白云尽情笼照青草绿树，让人心生退隐江湖之
意，只想在此隐居修行，追求武道至高境界。
LONG );
	set("outdoors", "nanhai");
	set("exits", ([
		"north" : __DIR__"xkroad4",
		"west"  : __DIR__"zhuwu",
	]));
	set("max_room", 3);
	setup();
	replace_program(BUILD_ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
