//ROOM: /d/yanziwu/shuiyun.c

inherit ROOM;

void create()
{
	set("short", "水云轩");
	set("long",@LONG
湖心的一座小小的亭台，四面环水，只有西侧有一条曲桥与岸上相
连。轩中清风拂面，水波微扬，一群群游鱼清晰可见，别有一番诗情画
意。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
	    "west" : __DIR__"jiashan",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
