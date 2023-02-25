// butian.c 补天石

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "兵符" NOR, ({"bing fu"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "蒙古兵符，可以找郭靖兑换秘籍。\n");
		set("unit", "块");
		set("value", 1000);		        	
	}
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
