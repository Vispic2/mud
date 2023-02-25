// mdiamond.c 神之钻石

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW "神之钻石" NOR, ({ "magic diamond" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "一颗焕发着奇异的光彩的钻石，给人以不同寻常的感觉。"NOR"\n");
		set("base_value", 200000);
		set("base_weight", 1);
		set("base_unit", "颗");
		set("can_be_enchased", __DIR__"god_eyes"+random(5));
		set("enchased_need", ({
			(["id":"magic agate","name":"神之玛瑙"]),
			(["id":"magic crystal","name":"神之水晶"]),
			(["id":"magic jade","name":"神之翡翠"]), 
		}));
		set("magic/type", "lighting");
		set("magic/power", 150);
	}
	set_amount(1);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
