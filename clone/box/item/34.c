// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("免肉", ({"liewu1"}) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块免肉\n");
		set("unit", "块");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 60);

		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
