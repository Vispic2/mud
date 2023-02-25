// jinsha.c

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
	set_name(HIY "抽奖券" NOR, ({ "cjj" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一张抽奖券。\n");
		set("unit", "张");
		set("base_unit", "张");
		set("base_value", 500);
		set("yuanbao", 200);
 
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
		set("base_weight", 1);
	}
	setup();
}

int do_effect(object me)
{
    me->add("cjj",1);
	message_vision(CYN "$N" CYN "使用了一"+query("unit") + name() + CYN "，获得了一次抽奖机会!"NOR"\n", me);	
	add_amount(-1);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
