// vote_suspension.c

#include <ansi.h>
#include <login.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, HIY "观察期已满，你又可以投票了！"NOR"\n");
		me->delete("vote/deprived");
		return 0;
	}
	me->apply_condition("vote_suspension", duration - 1);
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
