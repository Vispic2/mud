//ROOM: /d/yanziwu/zuijing2.c

inherit ROOM;

void create()
{
	set("short", "缀锦楼二层");
	set("long",@LONG
这是包不同爱女包不靓的卧室，小床，小桌上堆满了小孩子的玩艺
儿，透过南北两扇窗户可以看见太湖上烟波浩渺，白帆点点。
LONG );
	set("exits", ([
	     "down"   : __DIR__"zuijing",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
