// jiulou2.c

inherit ROOM;

void create()
{
	set("short", "酒楼二楼");
	set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边
吃喝边作交易。这里也是城里举办喜宴的最佳场所。你站在楼上眺望，
只觉得心怀坦荡。四周全是漫漫的黄沙，比之江南的花香鸟语，气势更
是浩荡。酒楼的墙上挂着一块牌子。
LONG
	);
	set("item_desc", ([
		"【牌子】" : "本店出售烤鸭及上等花雕酒。\n",
	]));
	set("objects", ([
		__DIR__"npc/zhanggui" : 1,
	]));

	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
