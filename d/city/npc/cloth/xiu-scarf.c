// xiu-scarf.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIY "绣花小方巾" NOR, ({ "scarf" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 300);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/per", 1);
		set("armor_prop/armor", 4);
		set("armor_prop/dodge", -1);
		set("female_only", 1);
		set("wear_msg","$N戴上一条$n。\n");
		set("remove_msg","$N将$n解了下来。\n");
	}

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
