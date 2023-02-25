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
	set_name(HIM"经验葡萄"NOR, ({"putao3"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 20000);
		set("yuanbao", 200);
         
		set("unit", "串");
		set("base_unit", "串");
		set("base_weight", 10);
		set("base_value", 20000);
		set("long","这是一串由吐蕃传入中原的"HIM"神奇葡萄"NOR"，吃下它会发生奇怪的事情！(经验+40000)\n");
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

	me->add("combat_exp",40000);
	write(YEL"你吃下一串"HIM"神奇葡萄"YEL"发现自己的经验大增!"NOR"\n");

        if (random(50)==1) {
            me->add("per",1);
            message_vision(HIW"只见$N身上发出一道耀眼的白光，似乎发生了什么神奇的事情。"NOR"\n", me);
            write(HIM"恭喜：你的先天容貌提升了!"NOR"\n");
            }
	add_amount(-1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
