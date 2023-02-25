// wolfarrow.c
 
#include <weapon.h>
 
inherit THROWING;

int is_arrow() { return 1; }
 
void create()
{
	set_name(HIY"狼牙箭"NOR, ({ "arrow", "jian" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根细长的箭，簇失略弯，如同狼牙一般阴森森的。\n");
		set("unit", "把");
		set("base_unit", "根");
		set("base_weight", 1);
		set("wound_percent", 100);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}

	set_amount(1);
	init_throwing(500);
	setup();

	set("no_wield", "这不是用来装备的。\n");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
