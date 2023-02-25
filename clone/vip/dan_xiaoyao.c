
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIG"逍遥丹"NOR, ({"xiaoyao dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗神奇的药丸，据说能洗去凡尘重新来过。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10); 
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob;
    int var;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

    if(  me->query_temp("pending/betrayer") == ob){
		return notify_fail("你没有判师过，为什么要使用它"+ name() +"。\n");
	}else{
		me->delete_temp("pending/betrayer");
        message_vision("$N小心服用了一" + query("unit") + name() + "，似乎有了一丝轻松的感觉。\n", me);
	    add_amount(-1);
        return 1; 
	}
      
		

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
