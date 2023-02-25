// Room: /d/suzhou/wanjing.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "憨憨泉");
	set("long", @LONG
在山道西侧有一憨憨泉，系南朝梁代高僧憨憨尊者所开凿，
距今一千四百多年。据说泉眼通海，姑又名“海涌泉”。水甚
清冽为“天下第五泉”。石刻“憨憨泉”三字，系北宋吕升卿
所题。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"   : __DIR__"wanjing",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
