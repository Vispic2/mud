
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "僧鞋" NOR, ({ "seng xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双青布僧鞋");
		set("icon","05049");
		set("value", 6000);
		set("material", "boots");
		set("armor_prop/dodge", 5);
		set("shaolin",1);
	}
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
