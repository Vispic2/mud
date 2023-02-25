// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tmqidu_poison"; }

string chinese_name() { return "唐门催命散"; }

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;

	message("vision", me->name() + HIB"惨嚎一声，脸色铁青，全身经脉倒流，不住的颤抖。。\n"NOR, environment(me), me);
	tell_object(me, HIB "你只觉全身经脉倒流，全身肌肉快要坏死一般。！\n" NOR );
	if (random(3)==0 )
	{
		if (me->query("qi") > me->query("qi")/2)
			me->set("qi", me->query("qi")/2);
		tell_object(me,HIG"你的气力减低了!\n"NOR);
	}
	else if (random(3)==1 )
	{
		if (me->query("jing") > me->query("jing")/2)
			me->set("jing", me->query("jing")/2);
		tell_object(me,HIG"你的精力减低了!\n"NOR);
	}
	else
	{
		if (me->query("neili") > me->query("neili")/2 )
			me->set("neili", me->query("neili")/2);
		tell_object(me,HIG"你的内力减低了!\n"NOR);
	}
        if (!me->is_busy())
        me->start_busy(4);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
