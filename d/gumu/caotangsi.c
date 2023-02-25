// caotangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "草堂寺");
	set("long", @LONG
这是一座位於终南山北麓的小寺。寺院中的一口古井，名为烟雾
井。因为每天清晨都会有一股巨大的烟雾，自井里袅袅升起，不少游
客来此，就是为了一观此奇景。往南上是一条崎岖的山道。往北是一
条阴森森的小径。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"southup"     : __DIR__"shanlu7",
//		"north"       : __DIR__"",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
