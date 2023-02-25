// linji_tiandi.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "忽然你心里头感到一阵失落，原来你的天地庄收功了，你顿时
倍感红颜老去之叹！\n" NOR );
        me->delete_temp("apply/percao");
//		me->add("per", 0 - me->query("linji/per"));
		me->delete("linji/per");
		return 0;
	}
	me->apply_condition("linji_tiandi", duration - 1);

	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
