
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
	set_name(HIY"开服礼包"NOR, ({"kflb"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"新MUD，持续更新，欢迎各位兄弟朋友们的支持谢谢！\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
//set("no_get",1);
		set("base_value", 10000);
		set("yuanbao", 1200);
        set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int d1,d2,d3,d4,d5,exp,pot,i,HJXDLB;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
	return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
    exp	= 10000 + random(10000);
    me->add("combat_exp",exp);
    write(YEL"恭喜你获得了"+exp+"点经验\n"NOR);
    pot = 10000 + random(5000);
	me->add("potential",pot);
	
	write(YEL"恭喜你获得了"+pot+"点潜能\n"NOR);
	

	add_amount(-1);
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
