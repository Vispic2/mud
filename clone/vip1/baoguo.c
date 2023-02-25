inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"包裹增容卡"NOR, ({"zengrong card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbaos", 650);
		set("unit", "张");
		     set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1);
		set("only_do_effect", 1);
		set("long","这是一张包裹增容卡，"ZJURL("cmds:use zengrong card")ZJSIZE(20)"使用"NOR"之后包裹容量可以扩大二十格!\n");
		set("spectxt", "使用后包裹容量可以扩大二十格。\n");
	}
}

int do_effect(object me)
{
	me=this_player();


	if ( me->query("zengrong"))
      		return notify_fail("你已经使用过包裹增容卡啦!\n");  

        me->set("zengrong",20);
	write(YEL"使用成功！你的包裹容量扩大了二十格。"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
