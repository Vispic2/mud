
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
	set_name("重启奖励7.19", ({"wei hu1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "内含3888自动师门符，5w元宝票！\n");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 1000);
		set("yuanbao", 1120);		
	
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);		
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i;
	mapping gifts;
	string *list;
	object obj;

	gifts = ([
		"/clone/shizhe/baguasss":3888,
								
	]);

	list = keys(gifts);

		
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("战斗中，不能使用"+ name() +"。\n");

	message_vision("$N打开了一" + query("base_unit") + name() + "。\n", me);
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me,"你发现了"+obj->short()+"。\n");
		obj->move(me);
		me->add("yuanbaos",50000);
	}
	add_amount(-1);

	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
