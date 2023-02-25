// green_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("翠绿绸衫", ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件翠绿色的绸衫上面绣着几只黄鹊，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
