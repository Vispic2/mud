	//shawei.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("杀威棒", ({"shawei bang", "bang"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "把");
		set("value", 200);
		set("material", "wood");
	}

	init_staff(20);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
