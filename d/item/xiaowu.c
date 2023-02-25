// xiaoyuan.c

inherit ROOM;

#define GANJIANG	"/adm/npc/ganjiang"
#define MOYE	    "/adm/npc/moye"

void create()
{
	object ob;

	set("short", "铸剑室");
	set("long", @LONG
你一走进这个屋子，就感觉到有一股热浪扑面而来。屋角有一个炉子，
里面燃着熊熊火光，似乎无数的金蛇在你面前晃动。屋角堆放着一堆堆黑
乎乎的东西，不知道是什么。
LONG );

	GANJIANG->come_here();
	MOYE->come_here();

	set("no_fight", 1);
	set("no_sleep_room", 1);

	set("exits", ([
		"west" : __DIR__"road5",
	]));
	set("action_list", ([
		HIC"武器命名"NOR:"name",
		HIG"设定描述"NOR:"desc",
		HIY"装上描述"NOR:"wieldmsg",
		HIY"放下描述"NOR:"removemsg",
		HIM"结束设定"NOR:"finish",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
