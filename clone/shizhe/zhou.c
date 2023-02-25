// zhou.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("腊八粥", ({ "zhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "碗");
		set("long", "这是一碗珍贵的补品腊八粥。\n");
		set("value", 20000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int neili_limit;
	int neili;
me->add("str",1);
me->add("int",1);
me->add("con",1);
me->add("dex",1);
	 
		message_vision(HIY "$N" HIY "吃下一碗腊八粥，顿然间"
			       "只觉一股热气直沁心肺..."NOR"\n", me);
	
	destruct(this_object());
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
