// b_jiasha.c 黑色袈裟
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( BLK "黑色袈裟"NOR,({"jiasha","jia sha","cloth"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 20);
		set("value",100);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
