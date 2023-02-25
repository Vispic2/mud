#include <ansi.h>

int update_condition(object me, int duration)
{
	int dam;
	if (me->query("neili") >= 4000) dam = random(50);
	else if (me->query("neili") > 3000) dam = random(200);
	else if (me->query("neili") > 2000) dam = random(500);
	else if (me->query("neili") > 1000) dam = random(1500);
	else if (me->query("neili") > 500) dam = random(2000);
	else dam = random(3000);

	me->receive_wound("qi", dam);
	me->receive_wound("jing", dam);
	me->apply_condition("nishui", duration-1);
	
	if( duration < 1 )
	tell_object(me, HIW "你抹去糊在嘴上的泥巴，只感到空气是多么的清新！"NOR"\n" );
	else
	tell_object(me, HIW "你感到一阵气闷！"NOR"\n" );
	if( duration < 1 ) 
		return 0;
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
