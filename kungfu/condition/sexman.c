// bonze_drug.c

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "武林同道不再通缉你了！\n");
		return 0;
	}
	me->apply_condition("sexman", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
