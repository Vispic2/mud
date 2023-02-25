// linji_fengyun.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "忽然你觉得一股浊气自腰间猛向下沉去，顿时双足如灌铅般沉
重，原来你的风云庄收功了！\n" NOR );
                me->delete_temp("apply/dexerity");
//		me->add("dex", 0 - me->query("linji/dex"));
		me->delete("linji/dex");
		return 0;
	}
	me->apply_condition("linji_fengyun", duration - 1);

	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
