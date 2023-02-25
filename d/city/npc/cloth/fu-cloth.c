// fu-cloth.c example cloth

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIY "富贵团金褂" NOR, ({ "cloth" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/per", 1);
		set("armor_prop/armor", 2);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$N将$n脱了下来。\n");
	}

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
