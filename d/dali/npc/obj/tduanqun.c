// tduanqun.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("台夷短裙", ({ "duan qun" }));
	set("long", "这是一件台夷短裙。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 1);
	}
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
