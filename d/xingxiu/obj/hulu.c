// hulu.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>;

void create()
{
	set_name(HIG"青葫芦"NOR, ({ "qing hulu", "hulu" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一个碧绿色的葫芦。\n"
);
		set("unit", "个");
		set("value", 80);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 60,
	]) );
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
