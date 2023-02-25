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
	set_name(HIY"飞贼麻袋"NOR, ({"feizei dai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"从飞贼身上搜出来的一个麻袋，里面有什么呢？\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 1000);

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
    int i;

    if (me->is_busy())
     return notify_fail("你正忙着呢。\n");
i=random(30);
me->add("yuanbaos",i);
message_vision(HIR"$N获得了"+i+"个元宝票！"NOR"\n", me, this_object());
add_amount(-1);
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
