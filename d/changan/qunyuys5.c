//Room: qunyuys5.c

inherit ROOM;

void create()
{
	set("short", "群玉楼雅室");
	set("long", @LONG
一间雅室。房中放着一张大床，床上铺着绣花的锦被和枕头。湘绣
驰名天下，大红锦被上绣的是一对戏水鸳鸯，颜色灿烂，栩栩欲活。几
上点着一根红烛，红烛旁是一面明镜，一只梳妆箱子。床前地下两对绣
花拖鞋，一对男的，一对女的，并排而置。
LONG);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"qunyulou3",
	]));
	set("objects", ([
		__DIR__"npc/baiyi" : 1,
	]) );

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
