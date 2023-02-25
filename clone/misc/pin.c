// pin.c 钢针

#include <weapon.h>
#include <ansi.h>

inherit PIN;

void create()
{
	set_name("钢针", ({ "pin", "zhen" }));
	set_weight(15);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一用来缝制衣服的针，颇为粗长。\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", YEL "$N手一抖，亮出一根$n" YEL "。\n");
		set("unwield_msg", YEL "$N收起了$n" YEL "。\n");
	}

	init_pin(10);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
