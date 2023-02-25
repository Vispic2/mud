#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIY "锦团官服" NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "上品官兵所穿戴的制服。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
