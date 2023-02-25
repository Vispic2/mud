// yuxiao.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("玉萧", ({"yuxiao"}));
	set_weight(500);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一支白玉做成的长萧，看上去晶莹温润。武林中人经常以萧代剑。\n");
		 set("icon","05061");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N大袖一挥，手中已多了一支晶莹温润的玉萧。\n");
		set("unwield_msg", "$N手中玉萧一转，眨眼间玉萧已然不见影踪。\n");
	}
	init_sword(50);
	setup();
}	

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
