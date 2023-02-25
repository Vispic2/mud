inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"福源丹"NOR, ({"fuyuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);         
		set("unit", "颗");
set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("long","这是一颗福源丹，使用之后可以增加福源！\n");
		set("only_do_effect", 1);
	}
}


int do_effect(object me)
{
      if (me->query("kar")>99) return notify_fail("你的运气已经很好了！\n");

	me->add("kar",1+random(3));

      if (me->query("kar")>100) me->set("kar",100);

	write(YEL"你服用了一"+ query("unit") + name() +YEL"，你的福源增加了！"NOR"\n你现在的福源是："+me->query("kar")+"。"NOR"\n");
	
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
