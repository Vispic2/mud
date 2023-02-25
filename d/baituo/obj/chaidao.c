#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("柴刀", ({ "cai dao", "dao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("value", 0);
	      set("icon", "05038");
		set("material", "iron");
		set("long", "这是一柄半新不旧的柴刀。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(5);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
