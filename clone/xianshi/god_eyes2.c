#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "炎帝神农之" + HIM + "眼" NOR, ({ "god eyes","eyes" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM"五方上帝掌管诸天万界之内的五方天地，代表五德始终，关系人间历代的命数。"HIR"炎帝神农代表火德"HIM"，据说他的眼睛具有伤气和吸内的功效。"NOR"\n");
		set("base_value", 2000000);
		set("base_weight", 1);
		set("base_unit", "颗");
     	set("yuanbao",3000);
     	set("max_buy",1);
		set("can_be_enchased", 1);
		set("magic/type", "fire");
		set("magic/power", 200);
	}
	set_amount(1);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
