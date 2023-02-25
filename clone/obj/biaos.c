
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
	set_name("暗器盒子", ({"an qi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "内含各种暗器！\n");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 10);
		set("yuanbao", 20);		

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
		"/clone/obj/hua":999,	
	"/clone/obj/biao":999,
	"/clone/obj/jie":999,									
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
	add_amount(-1);

	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
