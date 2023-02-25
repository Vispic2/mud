//ROOM: /d/yanziwu/chuantang.c

inherit ROOM;

void create()
{
	set("short", "穿堂");
	set("long",@LONG
不知是什么能工巧匠设计了这条穿堂，九曲回折，雕梁画栋。再望
南就是后院了，向北则是一座大厅堂。
LONG );
	set("exits", ([
	    "south" : __DIR__"lixiang",
	    "north" : __DIR__"cuixia",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
