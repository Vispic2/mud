// qin.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIW"白玉瑶琴"NOR, ({ "yao qin", "qin"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "这是一具用白玉做成的瑶琴。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N从背后将$n拿在手中。\n");
		set("unwield_msg", "$N将手中的$n放回背后。\n");
	}
	init_sword(30);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
