// stone.c
inherit ITEM;

void create()
{
	set_name("石块", ({ "stone" }));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块小石子。\n");
		set("unit", "块");
		set("value", 0);
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
