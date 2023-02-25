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
	set_name(HIW "福寿膏" NOR, ({"fushou gao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		    
		set("base_weight", 10);
		set("base_value", 20000);
		set("unit", "块");
		set("base_unit", "块");
		set("long", HIY "一块黑黑的药，来自西洋，据说吃完让人精神百倍。\n");
		set("value", 200000);
		set("yuanbao", 20);	
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
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

	message_vision(HIC"$N掏出一支烟枪，深深的吸了一口"+NOR+HIW+"福寿膏，"+NOR+HIC+"浑身上下飘飘欲仙，脸上露出满足的""表情。"NOR"\n", me);
	if (me->improve_jingli(100 + random(50)))
	me->set("jingli", me->query("max_jingli"));
	
	add_amount(-1);
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
