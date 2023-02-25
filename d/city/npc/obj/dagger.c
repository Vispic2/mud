// dagger.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("普通匕首", ({ "dagger", "bishou" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把普通的小匕首。用来暗算别人比较合适。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N从兜里掏出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放回兜里。\n");
	}
	init_dagger(13, 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
