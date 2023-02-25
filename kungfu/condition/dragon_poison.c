// dragon_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_wound("jing", 20);
    me->receive_damage("qi", 20);
    me->start_busy(2);
    me->apply_condition("scorpion_poison", duration - 1);
    tell_object(me, MAG "你感到呼吸困难，四肢渐渐肿了起来。\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
