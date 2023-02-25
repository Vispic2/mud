// shandao2.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边
必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然
一失足，就要掉进万丈深渊了。往东南是一块广大的空地。往北下通
往后山脚，远远可以望见一个较大的湖。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"southup"   : __DIR__"shandao1",
		"northdown" : __DIR__"shulin10",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
