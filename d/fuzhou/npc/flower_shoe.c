// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "绣花小鞋", ({ "flower shoes", "shoes"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
	      set("icon","05048");
		set("unit", "双");
		set("value", 300);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
