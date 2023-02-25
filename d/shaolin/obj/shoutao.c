// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name("皮手套", ({ "pi shoutao", "shoutao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "双");
		set("long", "这是一双皮手套，上面有硬物刻勒的痕迹。\n");
		set("value", 3000);
		set("armor_prop/armor", 1);
		set("armor_prop/hand", 1);
		set("armor_prop/strike", 1);
		set("armor_prop/unarmed_damage", 3);
		set("shaolin",1);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
