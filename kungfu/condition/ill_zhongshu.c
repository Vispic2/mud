// ill_zhongshu.c

#include <ansi.h>
#include <condition.h>

inherit ILLNESS;

string name() { return "ill_zhongshu"; }

int min_qi_needed() { return 15; }

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;

	message("vision", HIG + me->name() + "头重脚轻，晕晕乎乎抬不"
			  "起头来，看来是中暑了。"NOR"\n",
		environment(me), me);

	if( !living(me) && me->query("qi") < 2 ) {
		me->set_temp("die_reason", "中暑太深，暴毙身亡了");
		me->die();
		return 0;
	}
	else
	tell_object(me, HIB "你觉得胸臆之间一阵翻腾，头重脚轻，脑门发热，看来是中暑了。"NOR"\n" );

	if(me->query("qi")>2)
		me->receive_damage("qi", 2);
	if(me->query("eff_qi")>2)
		me->receive_wound("qi", 2);
	me->apply_condition(name(), duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
