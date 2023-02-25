// god_eyes.c 上帝之眼

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "上帝之" + HIM + "眼" NOR, ({ "god eyes","eyes" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"一块闪烁着"HIY"夺目光芒"HIC"的"HIG"宝石"HIC"，据说此物并非来自人间，让人敬畏之心油然而生。"NOR"\n");
		set("base_value", 2000000);
		set("base_weight", 1);
		set("base_unit", "块");
  		set("no_get",1);
		set("no_give",1);
  		set("no_drop",1);
  		set("no_sell",1);
  		set("no_steal",1);
		set("can_be_enchased", 1);
		set("magic/type", "all");
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
