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
	set_name(HIR"毁容丹"NOR, ({"huirong dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 100);
               
		set("unit", "粒");
		set("long","这是一粒毁容丹，服下之后将有损容颜!\n");

		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 

		set("base_unit", "粒");
		set("base_weight", 10);
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

	if (me->query("per")<11) return notify_fail("你的容貌已经极丑了。\n");

	me->add("per",-1-random(3));

        if (me->query("per")<11) me->set("per",10);

	write(YEL"你服下了一粒"HIR"毁容丹"YEL"，你的容颜大损！"NOR"\n你现在的容貌是："+me->query("per")+"。"NOR"\n");
	me->save();
	add_amount(-1);
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
