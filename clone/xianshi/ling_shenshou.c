
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
	set_name(HIY "神兽令牌" NOR, ({ "shenshou ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一块令牌，凭此令牌可以挑战四神兽一次！\n");
		set("base_unit", "块");
		set("base_value", 500000);
		set("yuanbao", 100);
        set("max_buy",1);
		set("value", 20000);
		set("base_weight", 1);
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
