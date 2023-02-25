// zhitao.c 指套

#include <armor.h>

inherit HANDS;

void create()
{
	set_name( "指套", ({ "finger", "zhitao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long", "这是五个环环相链的铁指套，前端锋利如刃，既可暗藏掌中伤人，又可保护指关节。\n");
		set("value", 6000);
		set("material", "iron");
		set("armor_prop/armor", 5);
		set("armor_prop/finger", 5);
	      set("armor_prop/unarmed_damage", 20);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
