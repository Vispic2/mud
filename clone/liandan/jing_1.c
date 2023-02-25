// puti-zi.c 菩提子

#include <ansi.h>

inherit ITEM;

void setup()
{
}

void create()
{
	set_name(HIY "初·持续回精" NOR, ({"jing 1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
        set("base_unit", "颗");
		set("long", HIG "这是一颗来自东方的神药，可以持续恢复精神！\n");
		set("value", 10000);
        set("yuanbao",10);
		set("only_do_effect", 1);
              
	}
	setup();
}

int do_effect(object me)
{
	if ((int)me->query_condition("ahuifu_jing_1") > 0)
	{
		write("你觉得现在内息未定，经脉隐隐还能感到真气冲荡，不敢贸然服食。\n");
		return 1;
	} 
	
		message_vision(HIY "$N" HIY "吃下一颗"+name()+"，顿然间只觉一股浩荡无比的真气直冲顶门，连忙运功吸纳。"NOR"\n",me);
		me->apply_condition("ahuifu_jing_1", 300);


	me->start_busy(random(3) + 1);
	destruct(this_object());
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
