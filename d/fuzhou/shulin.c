// Room: /d/fuzhou/shulin.c
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你走在福州东门外密林中。林中时时传来虫鸟的啼鸣。
北边林深处似乎有一小庙。东边一山，其形如鼓。卧在平坦
平原上。
LONG );
	set("exits", ([
		"north"  : __DIR__"wuxiang",
		"eastup" : __DIR__"gushan",
		"west"   : __DIR__"dongmen",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
