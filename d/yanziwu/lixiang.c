//ROOM: /d/yanziwu/lixiang.c

inherit ROOM;

void create()
{
	set("short", "梨香苑");
	set("long",@LONG
慕容家的后院也与众不同，圆形院门上刻有梨香苑三字，院中雪白
的梨花开满了枝头。西侧就是接待贵宾的龙凤厅了，东侧有一条精美的
长廊。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
	    "north" : __DIR__"chuantang",
	    "west"  : __DIR__"longfeng",
	    "east"  : __DIR__"changlang"
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
