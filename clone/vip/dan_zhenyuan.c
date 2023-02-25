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
	set_name(HIR"真元丹"NOR, ({"zhenyuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 20000);
		set("yuanbao", 200);
         
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","消失已久的神奇丹药，可以补充人物先天的真元！(5000点)\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->add("zhenyuan",5000);
	write(YEL"你吃下一颗"HIR"真元丹"YEL"发现自己的真元大增!"NOR"\n");
	add_amount(-1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
