// houhuayuan1.c 后花园
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这是一片荒废了的花园，本来这里有一片小池塘，养着一些
金鱼之类，现在池塘差不多也干涸了。池塘边立着一座假山，山
上长满了青苔，看来已经很久没有人来过了。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"west" : __DIR__"houhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/wugui" : 1,
	] ));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
