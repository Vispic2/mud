// dao-xie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIY "麻鞋" NOR, ({ "ma xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
	      set("icon", "05047");
		set("long", "一双青布麻鞋。\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 5);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
