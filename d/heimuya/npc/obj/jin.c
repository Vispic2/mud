// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("金丝甲", ({ "jin" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("icon","5046");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 8);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
