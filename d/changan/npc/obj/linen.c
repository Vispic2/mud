//linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布衣", ({ "linen" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("material", "cloth");
		set("unit", "件");
		set("value", 0);
		set("armor_prop/armor", 1);
	}

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
