// huxin-dan.c 天王护心丹

#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIY"葫芦"NOR, ({"hu lu"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一个"+name()+"，看起来可以"ZJURL("cmds:fuyong xishui")+ZJSIZE(20)+"盛溪水"+NOR+"和"ZJURL("cmds:fuyongs xishui")+ZJSIZE(20)+"饮用"+NOR+"。你仔细一看，葫芦底部还刻着"""HIY"柳秀山庄"NOR"""四个字。\n");
		set("value", 100);
		set("unit", "个");
	  }
   	setup();
}
void init()
{
    if (environment()==this_player()){
	add_action("do_eat", "fuyong");
	add_action("do_eats", "fuyongs");
	}
}
int do_eat(string arg)
{
    int q,j;
	string *enemy;

       object me, ob;      
       me=this_player();
       ob=this_object();

     ob= present("hu lu",me);
     if (!objectp(ob))
	 return notify_fail("你身上没有葫芦，不能盛水！\n");
    	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
     	me->set("xishuisss",1);
	
		message_vision(HIG"$N跑到小溪上拿着葫芦盛了满满一葫芦的清水。"NOR"\n" , me);
		me->start_busy(3);			   
}


int do_eats(string arg)
{
       int q, j;
	string *enemy;

       object me, ob;      
       me=this_player();
       ob=this_object();
       ob= present("hu lu",me);
        if (!objectp(ob))
        return notify_fail("你身上没有葫芦！\n");
     	if (!arg || arg!="xishui")
		return notify_fail("你要服什么?\n");
        if(!me->query("xishuisss"))
		return notify_fail("这里面还没有盛水呢。\n");
    	if(me->query("chusheng"))
    	return notify_fail("你已经完成新手任务了，不能再使用这个了。\n");
    	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	    me->set("xishuisss",0);	    
	    if(me->query("heshui") <1){
	    me->add("combat_exp",1000);
    	me->add("potential",1000);
	    write(HIC"干的不错，你被奖励了一千点经验，1千点潜能，然后去四周转转看看有没有别的出口，如果没有就回来！"NOR"\n");
	    }
	    me->set("heshui",1);
		me->set("water", me->max_water_capacity());
		message_vision(HIG"$N拿起葫芦咕噜咕噜得喝了几口水。"NOR"\n" , me);
		message_vision(HIG"$N拿起葫芦咕噜咕噜得喝了几口水。"NOR"\n" , me);
		message_vision(HIG"$N拿起葫芦咕噜咕噜得喝了几口水。"NOR"\n" , me);
		me->start_busy(3);			
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
