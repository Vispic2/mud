// Room: /d/pk/turen3.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "渡劫入口" NOR);
	set("long", @LONG
前面就是通往渡劫谷的密路了。
LONG
	);
	set("exits", ([
		"north"  : __DIR__"dujie1",
		
	]));	
	setup();
}
/*
int valid_leave(object me, string dir)
{
	if (! playerp(me))
		return ::valid_leave(me, dir);

	if (random(2))
	{
	   // me->add("max_qi",-1000);
	    me->add("qi",-1000);
	    me->add("eff_qi",-1000);
		write("每走一般身上就痛苦至极，仿佛随时都会爆体而亡。\n");
		return -1;
	}
	
	
	return ::valid_leave(me, dir);
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
