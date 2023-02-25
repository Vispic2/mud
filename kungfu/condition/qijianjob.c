// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		tell_object(me, HIY "你时间到你被传送出去。\n" NOR);

        me->move("d/city/guangchang");
        return 0;
	}

	if (!duration) return 0;
	me->apply_condition("qijianjob", duration - 1);
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
