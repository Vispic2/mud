// goupi.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("狗皮", ({ "gou pi", "pi" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("material", "fur");
		set("value", 300);
		set("armor_prop/armor", 1);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
