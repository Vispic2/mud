// huxin-dan.c 天王护心丹

#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIM"野果"NOR, ({"ye guo"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一枚不知道从哪掉下来的野果，可以用来"+HIM+ZJSIZE(25)+ZJURL("cmds:fuyongsss")+"裹腹"NOR"。\n");
		set("value", 100);
		set("unit", "个");
	  }
   	setup();
}
void init()
{
    if (environment()==this_player()){
	add_action("do_eatsss", "fuyongsss");
	}
}
int do_eatsss(string arg)
{
    int q, j;
	string *enemy;

       object me, ob;      
       me=this_player();
       ob=this_object();
       ob= present("ye guo",me);
        if (!objectp(ob))
	    return notify_fail("你身上没有这野果！\n");
    	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
     	if(me->query("chusheng"))
    	return notify_fail("你已经完成新手任务了，不能再使用这个了。\n");
     	me->set("food", me->max_food_capacity());
		message_vision("你拿出"+name()+"咬了几口。"NOR"\n" , me);
		message_vision("你拿出"+name()+"咬了几口。"NOR"\n" , me);
		message_vision("你拿出"+name()+"咬了几口。"NOR"\n" , me);
		message_vision("你拿出"+name()+"咬了几口。"NOR"\n" , me);
		message_vision("你拿出"+name()+"咬了几口。"NOR"\n" , me);
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
