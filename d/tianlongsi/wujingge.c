inherit ROOM;

void create()
{
	set("short", "无净阁");
	set("long",@LONG
这是历代大理王侯前来进香还愿时休息的地方。阁内檀象宝炉，软榻
矮几，一应俱全，清静之中隐然透出一丝富贵之象。
LONG );
	set("exits", ([
		"south": __DIR__"xianghemen",    			
		"east" : __DIR__"ta1",
	]));
	set("objects",([
		__DIR__"npc/xiaoshami" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
