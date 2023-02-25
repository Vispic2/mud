// kuihuazhen.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("葵花针", ({ "kuihuazhen" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",     "葵花针是一种专门打制的暗器，外形极薄。\n");
		set("unit", "把");
		set("base_unit", "把");
		set("base_weight", 1);
		set("base_value", 0);
		set("value", 0);
	}
	set_amount(200);
	init_throwing(10);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
