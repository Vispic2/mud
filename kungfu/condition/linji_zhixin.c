// linji_zhixin.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "忽然你头脑里感到一阵空白，原来你的之心庄收功了，你顿时
觉得自己还是个大笨木瓜！\n" NOR );
//		me->add("int", 0 - me->query("linji/int"));
        me->delete_temp("apply/intelligence");
		me->delete("linji/int");
		return 0;
	}
	me->apply_condition("linji_zhixin", duration - 1);

	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
