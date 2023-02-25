// male7-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"明黄锦袍"NOR, ({ "cloth" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件明黄锦袍。\n");
		set("material", "cloth");
		set("value", 0);
		set("armor_prop/armor", 1);
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
