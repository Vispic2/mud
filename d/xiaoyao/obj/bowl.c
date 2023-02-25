
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("牛皮酒袋", ({"jiudai", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装米酒的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 1);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "water",
		"name": "米酒",
		"remaining": 15,
		"drunk_supply": 10,
	]));
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
