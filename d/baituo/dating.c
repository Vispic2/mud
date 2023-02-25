//ROM dating

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long",
	     "这是『白驼山庄』的大厅，内部摆设极尽豪华，当中一张黑色檀木\n"
	 "条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名家的字画。\n"
	);

	set("exits", ([
		"north" : __DIR__"liangong",
		"southdown" : __DIR__"yuanzi",
	]));
 
	set("objects",([
		CLASS_D("ouyang") + "/ouyangfeng" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	set("no_beg", 1);

	setup();

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
