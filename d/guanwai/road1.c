// /guanwai/road1.c
inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这里是通往关外的官道，几米宽的大道，全部由黄土铺成，可并行三四
辆马车而不显拥挤。这里是进出关口的必经之路，路上三俩成群的行人都是
往来贩运皮货，药材的生意人。偶尔有身着官兵骑马飞驰而过。
LONG );
	set("exits", ([
		"northeast" : __DIR__"road2",
		"southwest" : __DIR__"shanhaiguan",
	]));
	set("objects",([
		__DIR__"npc/xiaoyuanshan" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
