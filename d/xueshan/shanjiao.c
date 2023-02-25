//      shanjiao.c 山脚
inherit ROOM;

void create()
{
	set("short", "山脚");
	set("long", @LONG
这里是山脚下的一片平地，山上不远处，皑皑白雪映
照下的一大片红墙金瓦处，就是远近闻名的雪山寺。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"westup" : "/d/xuedao/nroad7",
		"south"  : __DIR__"hubian4",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
