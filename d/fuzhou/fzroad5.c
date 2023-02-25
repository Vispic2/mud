// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。
山中毒虫猛兽出没无常，行路艰辛。
LONG );
	set("exits", ([
		"westup"    : __DIR__"fzroad6",
		"northeast" : __DIR__"fzroad4",
	]));
	set("outdoors", "fuzhou");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
