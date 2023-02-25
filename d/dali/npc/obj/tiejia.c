// tiejia.c 铁甲
//

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("铁甲", ({ "tie armor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "steel");
		set("value", 2000);
		set("armor_prop/armor", 20);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
