// jingxiu.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if (me->query("family/family_name") != "少林派")
		return notify_fail("只有少林派弟子才会才能静修！\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里太纷杂，你没法安心静修。\n");

	if (me->query("jing") < 50)
		return notify_fail("你精神不济，无法定心静修。\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("战斗中怎么静修？\n");

	if (me->query_skill("buddhism", 1) < 200)
		return notify_fail("你的佛学还不够深厚，难以通过静修参悟禅理。\n");

	switch (random(3))
	{
	case 0:
		message_vision("$N盘膝坐下，冥思入定。\n", me);
		break;

	case 1:
		message_vision("$N缓缓坐下，魂游天外。\n", me);
		break;

	default:
		message_vision("$N安坐不动，整个人似梦似醒。\n", me);
	}

	me->receive_damage("jing", 50 + random(50));
	if(where->query("guibing_room",1)){
	me->improve_skill("buddhism", (100 + random(me->query_int()))*2);
	}else{
	me->improve_skill("buddhism", 100 + random(me->query_int()));
	}
	me->start_busy(1 + random(3));
	write(HIC "你对禅宗心法有所心得。"NOR"\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : jingxiu

这个指令是少林派弟子用以静修参禅的命令.

HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
