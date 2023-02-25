#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIY "一品侍卫装" NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "御前侍卫的统一装束。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 25);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
