// finger.c

#include <armor.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void setup()
{
	if (! clonep(this_object()))
		set("armor_type", TYPE_FINGER);
set("armor_buwei", "手指");
 if( !query("armor_apply/dodge") &&	 weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );

	::setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
