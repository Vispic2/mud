// boots.c 皮靴
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("皮靴", ({ "boots", "pi xue", "xue" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("long", "这是一双用上好牛皮作的皮靴，据说由上海进口。用以保护足部。\n");
		set("value", 1000);
	      set("icon", "05004");
		set("armor_prop/dodge", 8);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
