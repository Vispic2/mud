//Room: xiaojia-sleep.c

inherit ROOM;

void create ()
{
	set ("short", "脦脭脢脪");
	set ("long", @LONG
脙禄脧毛潞脙脛脴!潞脟潞脟!
LONG);
	set("exits", 
	([ //sizeof() == 1
		"north" : __DIR__"xiaojiadt",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/yahuan" : 1,
	]));

	setup();

}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
