#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
	set_name(HIW "镔铁长枪" NOR, ({ "chang qiang", "qiang", "spear"}) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("value", 300);
		set("material", "silk");
	}
	init_club(10);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
