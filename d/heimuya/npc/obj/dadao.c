#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("大刀", ({ "da dao", "dao" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 200);
		set("material", "iron");
		set("long", "这是一柄铁打的大刀。\n");
	      set("icon", "05038");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(10);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
