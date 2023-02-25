//zuanjie.c

#include <armor.h>

inherit FINGER;

void create()
{
	set_name("钻石戒指", ({ "zuan jie", "zuanjie", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("value", 12000);
		set("material", "diamond");
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
