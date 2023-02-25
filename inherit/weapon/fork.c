// fork.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_fork(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | POINTED);
	set("skill_type", "fork");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "thrust" }) );
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
