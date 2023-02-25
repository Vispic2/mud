// shijie4.c 石阶
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条整齐的石板路，依山而建，随着山势的曲折蜿蜒曲折。
由于山势陡了，当初修建这条石阶时肯定费了不小的功夫。走到这
里，已经可以看见全真教重阳观的檐角了。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northup" : __DIR__"shijie5",
		"westdown" : __DIR__"shijie3",
		"southup" : __DIR__"shijianyan",
	]));

	set("objects",([
		__DIR__"npc/youke" : 1,
	//      __DIR__"npc/xiangke" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
