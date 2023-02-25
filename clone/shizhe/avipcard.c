inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"VIP月卡"NOR, ({"month card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 20000);
		set("yuanbao", 200);
		set("unit", "张");
		set("long","这是一张VIP月卡，"ZJURL("cmds:use week card")ZJSIZE(20)"使用"NOR"之后增加30天会员时间!\n");
        set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 

	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
    int vip_time;
	object me=this_player();
	
    vip_time=30 * 24 * 3600;
	
	if (arg!="week card")
      	return notify_fail("你要用什么?\n");  

	write(YEL"你的会员时间增加30天！"NOR"\n");
	me->add("zjvip/times",vip_time);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
