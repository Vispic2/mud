#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("影鞭", ({ "whip" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "无数邪气凝聚而成的一把长鞭。\n");
		set("no_get", 1);
		set("material", "邪气");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_whip(10);
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
