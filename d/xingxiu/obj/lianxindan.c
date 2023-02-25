// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(HIG"炼心弹"NOR, ({ "lianxin dan", "dan" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("value", 0);
		set("base_unit", "颗");
		set("base_weight", 300);
		set("base_value", 0);
		set("material", "iron");
		set("long", HIG"炼心弹是星宿派淬毒暗器，针长寸许，发出诡异的光。"NOR"\n");
		set("wield_msg", HIC"$N迅速地从鹿皮袋中摸出一些炼心弹，捏在手中就待发出！"NOR"\n");
		set("unwield_msg",HIC"$N将手里剩下的炼心弹收回鹿皮袋中。"NOR"\n");
	}
	set_amount(50);
	init_throwing(10);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
