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
	set_name(HIM"小还丹"NOR, ({"xiaohuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
	
	
	    set("value", 20000);
	    set("base_value", 2000);
		set("yuanbaos", 25);            
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);		
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1);
		set("long","这是一颗小还丹，"ZJSIZE(22)"服用"NOR"之后能增加100点内力修为！注：可以连续服用，不能超出人物的内力上限。\n");	
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
    if (me->query("max_neili") > me->query_neili_limit())
    return notify_fail("你已经不能使用小还丹来提升内力修为了。\n");  
    
    
	me->add("max_neili", 100);
    write(me->query("name")+"服下一颗"HIM"小还丹"NOR"，顿觉内力大增！"NOR"\n");
	add_amount(-1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
