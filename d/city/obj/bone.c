// jitui.c 鸡腿

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鸡腿骨头", ({ "jitui gu" }));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一根啃得精光的鸡腿骨头。\n");
		set("unit", "根");
		set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	init_hammer(1);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
