// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object ob;
	if (duration < 1) {
		tell_object(me, "你的官府保护期过了！\n");
		return 0;
	}
	me->apply_condition("nokill", duration - 1);
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
