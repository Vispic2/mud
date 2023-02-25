// nroad2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一山路上，四周有一座座小山丘。能遥望见西南方大雪山
的北麓。山前隐隐约约象是有一座寺院。
LONG );
	set("exits", ([
		"westup"    : __DIR__"nroad3",
		"eastdown"  : __DIR__"nroad1",
	]));
	set("objects", ([
		"/d/wudang/npc/guest" : 1,
	]));
	set("outdoors", "xuedao");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
