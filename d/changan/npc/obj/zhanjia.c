//zhanjia.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("战甲", ({"zhan armor","zhanjia","jia","armor"}));
      	set_weight(40000);
      	if (clonep())
      		set_default_object(__FILE__);
      	else 
	{
	      set("icon","05045");
      		set("unit", "件");
      		set("long", "一件精钢造就的战甲。\n");
      		set("value", 3000);
      		set("material", "steel");
      		set("armor_prop/armor", 40);
      		set("armor_prop/dodge", -10);
	}

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
