// autosave.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration == 1)
	{
		tell_object(me, HIG"【存盘】您的档案已经自动存盘。\n"NOR);
		me->save();
		me->apply_condition("autosave", duration + 1);
	}
	else
	if (duration == 4)
	{
		if (me->query("food") <= 10)
			tell_object(me, HIY"你饿得头晕眼花，看来要赶快找点吃的了。\n"NOR);
		if (me->query("age") < 18 && (int)me->query("combat_exp") < 1000000 )
			tell_object(me,ZJFORCECMD("ci beg"));
		me->apply_condition("autosave", duration + 1);
	}
	else
	if (duration == 7)
	{
		if (me->query("water") <= 10)
			tell_object(me, HIY"你渴得喉咙冒烟，看来要赶快喝点什么了。\n"NOR);
		if (me->query("age") < 18 && (int)me->query("combat_exp") < 1000000 )
			tell_object(me,ZJFORCECMD("ci beg"));
		me->apply_condition("autosave", duration + 1);
	}
	else
	{
		if (duration == 13)  me->apply_condition("autosave", 1);
		else me->apply_condition("autosave", duration + 1);
	}
	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
