// fake-gold.c

inherit ITEM;

void create()
{
	set_name("黄金", ({"gold", "ingot", "gold_money"}));
	set_weight(150000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "黄澄澄的金子，人见人爱的金子，不过 ...颜色有点不对。\n");
		set("unit", "块");
		set("material", "lead");
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
