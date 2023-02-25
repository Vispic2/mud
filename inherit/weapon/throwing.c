// throwing.c
/*
#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int flag)
{
	if (clonep(this_object())) return;

	set("weapon_prop/damage", damage);
	set("flag", POINTED);
}

void setup()
{
	if (clonep(this_object())) return;

	set("no_wield", "暗器不是用来装备的。\n");
	set("skill_type", "throwing");
	set("consistence", 100);
	if (! query("actions"))
	{
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "throw" }) );
		set("stable", 0);
	}
}
*/

// throwing.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
}

void setup()
{
	// ::setup();
	seteuid(getuid());

	if( clonep(this_object()) ) return;

	set("skill_type", "throwing");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :));
		set("verbs", ({ "throw" }) );
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
