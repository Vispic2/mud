// renshen.c

inherit ITEM;

void create()
{
	set_name("人参", ({"renshen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵初具人形的老山参。\n");
		set("value", 10000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->improve_neili(3);

	message_vision("$N吃下一棵老山参，顿时间觉得全身充满了活力！\n", me);
	destruct(this_object());
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
