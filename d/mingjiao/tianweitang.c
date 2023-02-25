//tianweitang.c
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "天微堂");
	set("long", @LONG
这里就是明教的天微堂，堂主就是威名远波的殷野王。他是白眉鹰
王的独子和教主张无忌的舅舅。堂内陈设鲜丽奢华，显然甚是兴旺，往
来教众进进出出，看他们各执兵刃，似乎是守总舵的卫士。
LONG );
	set("exits", ([
		"east"      : __DIR__"tianshitang",
		"west"      : __DIR__"ziweitang",
		"southdown" : __DIR__"zhandao2",
		"north"     : __DIR__"square",
	]));
	set("objects",([
	     __DIR__"npc/yinyewang":1,
	     __DIR__"npc/yinwufu":1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();
	if ((me->query("family/family_name")!= "明教" ) &&
	    (dir=="north") &&
	    (objectp(present("yin yewang", environment(me)))))
	return notify_fail("殷野王拦住你说：此处乃明教重地，请止步。\n");
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
