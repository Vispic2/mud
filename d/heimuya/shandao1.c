// shandao1.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
西面是一座高山，地势极之险峻，一条窄小陡峭的山道通往
山上，东边山脚是一片长滩。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"changtan",
	    "westup"   : __DIR__"shandao2",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
