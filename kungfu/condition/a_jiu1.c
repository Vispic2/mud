// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{



	if (duration == 1)
	{
		me->add_temp("apply/dex",-10);
		me->add_temp("apply/str",-10);
		me->delette("drunk");
		tell_object(me,HIG"你的醉意已经散尽。\n"NOR);
	}
	else if ( duration <= 10 )
	{
		tell_object(me,HIG"你醉意正在消散!\n"NOR);
	}


	me->apply_condition("a_jiu1", duration - 1);

	if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
