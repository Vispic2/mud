// Room: /city/kedian3.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，
不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，
你蹑手蹑脚地走了过去。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
	set("hotel",1);
	set("no_clean_up", 0);
	set("item_desc", ([
		"【木床】" : "靠墙而放的一些小木床，有些客人正在床上休息。\n"
		ZJOBACTS"休息:sleep\n",
	]));
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
