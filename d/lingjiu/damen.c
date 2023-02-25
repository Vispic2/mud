//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "独尊厅大门");
	set("long",@LONG
这就是通向『灵鹫宫』独尊厅的大门。大门左右各有一头石雕的猛鹫
，高达三丈有余，尖喙巨爪，神骏非凡，栩栩如生，似乎随时要腾空而去。
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
	]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		__DIR__"npc/lanjian" : 1,
	]));
	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir != "north")
		return 1;

	if (objectp(guarder = present("mei jian", environment(me))))
		return guarder->permit_pass(me, dir);

	if (objectp(guarder = present("lan jian", environment(me))))
		return guarder->permit_pass(me, dir);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
