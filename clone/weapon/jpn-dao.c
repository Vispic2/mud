// jpn-dao

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("东洋刀", ({ "blade", "dao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
	      set("icon","05038");
		set("long", "这是一柄细长略弯的东洋长刀，形状怪异，似剑似刀。\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(50);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
