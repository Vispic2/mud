//key.c
#include <armor.h>
inherit ITEM;
void create()
{
	set_name( "绣花鞋", ({ "shoe"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long","这是一只漂亮的绣花鞋。\n");
			set("icon","05048");
		set("value", 50);
		set("material", "cloth");
		set("female_only", 1);
		set("armor_prop/armor", 3);
	      }
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
