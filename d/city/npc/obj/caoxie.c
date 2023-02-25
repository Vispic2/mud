// caoxie.c 草鞋
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("草鞋", ({ "sandals", "cao xie", "xie" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
	      set("icon", "05047");
		set("unit", "双");
		set("long", "这是一双草编的草鞋，用以保护足部。\n");
		set("value", 100);
		set("armor_prop/dodge", 2);
	}
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
