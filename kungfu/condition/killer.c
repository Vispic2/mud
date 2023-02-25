// killer.c

//#include <ansi.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		tell_object(me, "官府不再通缉你了！\n");
		CHANNEL_D->do_channel(this_object(), "rumor",
			"因为" + me->name(1) + "一直没能被" +
			"缉拿归案，听说官府已经取消了通缉令。");
		return 0;
	}
	me->apply_condition("killer", duration - 1);
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
