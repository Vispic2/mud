// 豆浆

inherit ITEM;
inherit F_LIQUID;

void init();

void create()
{
	set_name("杯子",({ "cup", "beizi" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个磁杯子。\n");
		set("unit", "个");
    	}
	
	set("liquid", ([
		"name": "豆浆",
		"remaining": 7,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
