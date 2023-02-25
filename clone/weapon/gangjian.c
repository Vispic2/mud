// gangjian.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("钢剑", ({ "iron sword", "jian", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
	      set("icon","05035");
		set("long", "这是一柄精工制成的钢剑，这种剑在将领之间非常流行。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
