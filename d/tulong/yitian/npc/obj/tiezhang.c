#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(WHT "精铁杖" NOR,  ({ "tie zhang", "tie", "zhang" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("icon", "05042");
		set("long", "一柄用镔铁打造的杖。\n");
		set("value", 2000);
		set("material", "gold");
	}
	init_staff(20);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
