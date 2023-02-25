//hei-mudan.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(BLU "黑牡丹" NOR, ({ "hei mudan", "mudan" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long", "清高冷傲的黑牡丹。\n");
		set("unit", "朵");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);
	}

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
