// neck.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
		set("armor_type", TYPE_NECK);
set("armor_buwei", "颈部");
 if( !query("armor_apply/dodge") &&	 weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );

	::setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
