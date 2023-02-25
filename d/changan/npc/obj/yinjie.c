//yinjie.c

#include <armor.h>

inherit FINGER;

void create()
{
	set_name("银戒指", ({ "yin jie", "yinjie", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("value", 1000);
		set("material", "silver");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
	}

	setup();
}      

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
