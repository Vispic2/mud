// fu-zhangfang 帐房
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "帐房");
	set("long", @LONG
这里是侯员外家的帐房。屋内青砖铺地，进门处横摆着一张桌
子，一个管家正坐在桌后，小眼睛不住地跟着你转，好象又在打什
么坏主意。
LONG
	);
	set("exits", ([
		"east" : __DIR__"fu-datang",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
