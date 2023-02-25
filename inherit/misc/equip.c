// equip.c

inherit ITEM;
inherit F_EQUIP;

void setup()
{
	if (! query("armor_prop/dodge") && (weight() >= 3000))
		set("armor_prop/dodge", -weight() / 3000);
	if (! query("weapon_prop/dodge") && (weight() >= 3000))
		set("weapon_prop/dodge", -weight() / 3000);

	ITEM_D->equip_setup(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
