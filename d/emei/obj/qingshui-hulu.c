// qingshui-hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("清水葫芦", ({"qingshui hulu", "hulu", "bottle"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用葫芦制成的水壶。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 10,
		"drunk_supply": 10,
	]));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
