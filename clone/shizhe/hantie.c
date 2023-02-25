// hantie.c 玄冰寒铁

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "玄冰寒铁" NOR, ({"ice steel", "han tie", "tie"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块亮晶晶的金属，据说是在上古玄冰中孕育出的寒铁。可以制造装备。\n");
		set("spectxt", "制造装备的材料。\n");
		set("unit", "块");
		set("value", 20000);
		set("yuanbao", 300);
		set("item_origin", 1);
      
		set("material_attrib", "steel");
		set("material_name", WHT "上古寒铁" NOR);
		set("can_make", "all");
		set("not_make", ({ "鞭", "战衣","裤子", "腰带", "裤子" }));
		set("power_point", 70);
	}
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
