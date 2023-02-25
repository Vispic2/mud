// Room: /d/pk/turen3.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "山径" NOR);
	set("long", @LONG
这是山径了，四周都是大树与小花。
LONG
	);
	set("exits", ([
		"south"  : __DIR__"dujie8",
	   "north"  : __DIR__"dujie10",
		
	]));	
	setup();
}
int valid_leave(object me, string dir)
{

    int i;
   i=random(3); 
   if(i==1)
{
	    me->add("qi",-1000);
	    me->add("eff_qi",-1000);
	//me->start_busy(1 + random(5));
                  write("每走一步身上就痛苦至极，仿佛随时都会爆体而亡1。\n");
}else
  if(i==2)
{
	    me->add("qi",-2000);
	    me->add("eff_qi",-2000);
	//me->start_busy(1 + random(5));
                  write("每走一步身上就痛苦至极，仿佛随时都会爆体而亡2。\n");
}
else  if(i==0)
{
	    me->add("qi",-3000);
	    me->add("eff_qi",-3000);
	//me->start_busy(1 + random(5));
                  write("每走一步身上就痛苦至极，仿佛随时都会爆体而亡3。\n");
}
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
