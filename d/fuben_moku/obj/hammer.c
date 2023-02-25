#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("影锤", ({ "hammer" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "无数邪气凝聚而成的一根锤子。\n");
		set("no_get", 1);
		set("material", "邪气");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_hammer(10);
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
