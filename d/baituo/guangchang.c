//ROM

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long",
	     "这里是一块不小的广场，上面堆着农家晒的谷物。北上是\n"
	 "『白驼山庄』。东面有间小农舍，西边有块菜地，东南方是一\n"
	 "座小桥。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"east" : __DIR__"nongshe",
		"south" : __DIR__"jingji/enter",
		"northup" : __DIR__"shijie",
		"northwest" : __DIR__"shanlu",
		"southeast" : __DIR__"bridge",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
