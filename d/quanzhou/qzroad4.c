// Room: /d/quanzhou/qzroad4.c
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
北面是江南名城嘉兴。向南则进入福建武夷山区。东面有一个供路人休息的
小茶亭。
LONG );
	set("exits", ([
		"north"   : __DIR__"jxnanmen",
		"west"    : __DIR__"qzroad3",
		"southup" : "/d/fuzhou/fzroad1",
		"east"    : __DIR__"chating",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
