// xuantie.c 玄铁石

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "玄铁石" NOR, ({"xuan tie", "tie"}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块黑黝黝有些泛光石头，掂在手中感到极为沉重，远胜铜铁。\n");
		set("spectxt", "制造装备的材料。\n");
		set("unit", "块");
		set("value", 2000000);	
	//	set("base_value", 10000);
		set("item_origin", 1);
		set("material_attrib", "steel");
		set("material_name", CYN "玄铁" NOR);
		set("can_make", "all");
		set("not_make", ({ "鞭", "战衣", "锤", "腰带", "裤子" }));
		set("power_point", 70);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
