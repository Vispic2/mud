// Room: /d/taishan/.c
inherit ROOM;

void create()
{
	set("short", "北天门");
	set("long", @LONG
这里位于石马山的北麓，是岱顶的北面出口，路口有一石坊，
上面写着「玄武」二字。
LONG );
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
