//      tulu1.c 土路
inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条不起眼的土路，不宽却也不窄，松散的浮尘
显露出来往行商的频繁。它是连接雪山寺与中原的必经之
路。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"east" : __DIR__"caoyuan",
		"west" : __DIR__"tulu2",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
