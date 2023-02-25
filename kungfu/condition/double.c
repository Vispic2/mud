// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	if (duration < 1)
	{
		tell_object(me,HIG"你双倍时间已经结束。\n"NOR);
	}
	else if ( duration <= 10 )
	{
		tell_object(me,HIG"你双倍时间快要结束,别浪费时间到处玩耍了!\n"NOR);
	}


	me->apply_condition("double", duration - 1);

	if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
