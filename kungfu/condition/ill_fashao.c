// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit ILLNESS;

string name() { return "ill_fashao"; }

int min_qi_needed() { return 10; }

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;

	message("vision", HIG + me->name() + "的脸蛋烧得通红，看来是发高烧了。"NOR"\n",
		environment(me), me);

	if( !living(me) && me->query("qi") < 1 ) {
		me->set_temp("die_reason", "发烧太重，活活被折磨死了");
		me->die();
		return 0;
	}
	else
		tell_object(me, HIB "你的脸蛋烧得通红，看来是发高烧了。"NOR"\n" );

	if(me->query("qi")>1)
		me->receive_damage("qi", 1);
	if(me->query("eff_qi")>1)
		me->receive_wound("qi", 1);
	me->apply_condition(name(), duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
