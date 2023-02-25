
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
	set_name(HIY"元宝票"NOR, ({"yuanbaos"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "金灿灿的元宝票。\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("yuanbao", 10);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int bo6,bo7,bo8,bo9,bo10;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

    me->add("yuanbaos",10);
	write(YEL"恭喜您：获得了10元宝票\n");
	add_amount(-1);
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
