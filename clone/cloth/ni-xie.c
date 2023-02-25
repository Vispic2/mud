// nixie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "青布尼鞋" NOR, ({ "ni xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
	      set("icon", "05048");
		set("long", "一双青布尼鞋。\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 5);
		set("female_only", 1);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
