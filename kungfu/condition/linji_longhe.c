// linji_longhe.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "忽然你觉得全身懒洋洋的，连个小指头也不想动了，原来你的
龙鹤庄收功了！\n" NOR );
                me->delete_temp("apply/constitution");
//		me->add("con", 0 - me->query("linji/con"));
		me->delete("linji/con");
		return 0;
	}
	me->apply_condition("linji_longhe", duration - 1);

	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
