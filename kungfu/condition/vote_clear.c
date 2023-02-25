// vote_clear.c
// by Marz 04/21/96

#include <ansi.h>
#include <login.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
	if (duration < 1) {
		if (duration > -5)
			tell_object(me, HIM "因为响应的人不多，对你的投票取消了。"NOR"\n");
		me->delete("vote/reason");
		me->delete("vote/juror");
		me->delete("vote/count");

		return 0;
	}

	me->apply_condition("vote_clear", duration - 1);
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
