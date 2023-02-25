
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
	set_name(HIY"BUG回馈礼包"NOR, ({"BUG"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是测试期间回馈BUG的礼包，专门奖励给回馈BUG者！\n");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 10);
		set("yuanbao", 10);				
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
		"/clone/shizhe/cjj":5,
		"/clone/shizhe/putao1":5,
		"/clone/shizhe/book_wuliang":5,
		"/clone/shizhe/baguasss":50,
		"/clone/shizhe/tianling":1,
		"/clone/shizhe/tianling2":1,
		"/clone/shizhe/tianling3":1,
		"/clone/shizhe/tianling4":1,											
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
	}
	me->add("yuanbaos",1000);
	tell_object(me,"你额外获得了1000元宝票。\n");
	add_amount(-1);

	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
