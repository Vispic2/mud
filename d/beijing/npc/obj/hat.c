#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "帽子", ({ "hat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 500);
		set("material", "hat");
		set("armor_prop/armor", 2);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
