// dispel.c

#include <ansi.h>

int exert(object me, object target)
{
	int i;
	int still_ill;
	string force_name;
	string *cnds;
	mapping conditions;

	if (me->query("neili") < 300)
	{
		write("你的内力不足，无法运满一个周天。\n");
		return 1;
	}

	force_name = to_chinese(me->query_skill_mapped("force"));

	if (me == target)
	{
		message_vision(HIW "$N" HIW "深吸一口气，又缓缓的吐了出来。"NOR"\n", me);
		tell_object(me, YEL "你默运" + force_name +
			    "，开始排除身体中的异常症状。"NOR"\n");
		 me->add("neili", -100);
	} else
	{
		message_vision(HIW "$N" HIW "深吸一口气，将手掌粘到$n"
			       HIW "的背后。"NOR"\n",
			       me, target);
		tell_object(me, YEL "你默运" + force_name + "，开始帮助" +
			    target->name() + "排除身体中的异常症状。"NOR"\n");
		tell_object(target, YEL + me->name() +
			    "正在运功帮助你排除身体中的异常症状。"NOR"\n");
		me->add("neili", -250);
	}

	still_ill = 0;
	conditions = target->query_condition(); 
	if (conditions)
	{
		cnds = keys(conditions);
		for (i = 0; i < sizeof(cnds); i++)
		{
			switch(target->dispel_condition(me, cnds[i]))
			{
			case 0:
				continue;
			case -1:
				still_ill = 1;
				continue;
			}
	
			if (me == target)
			{
				tell_object(me, WHT "你调息完毕，将内力收回丹田。"NOR"\n");
				me->start_busy(1 + random(2));
			} else
			{
				tell_object(me, WHT "你调息完毕，将内力收回丹田。"NOR"\n");
				tell_object(target, WHT "你觉得内息一畅，看来是" +  me->name() + "收功了。\n");
				me->start_busy(2 + random(3));
				if (! target->is_busy())
					target->start_busy(1 + random(2));
				message_vision(WHT "$N将手掌从$n背后收了回来。"NOR"\n", me, target);
			}
			return 1;
		}
	}

	if (still_ill)
	{
		if (me == target)
		{
			tell_object(me, MAG "你调息良久，没有一点效果。"NOR"\n");
			message_vision(HIG "$N" HIG "脸色变了变，有些不太自然。"NOR"\n", me);
			me->start_busy(3 + random(3));
		} else
		{
			tell_object(me, MAG "你运功良久，没能发挥半点作用。"NOR"\n");
			tell_object(target, MAG "你觉得内息一阵紊乱，说不出的难受。看来" + me->name() + "是不能给予你帮助了。"NOR"\n");
			message_vision(HIG "$N将手掌从$n背后收了回来，脸色说不出的难看。"NOR"\n",
					   me, target);
			me->start_busy(6 + random(6));
			if (! target->is_busy())
				target->start_busy(4 + random(4));
		}
	} else
	{
		if (me == target)
		{
			tell_object(me, "结果你没发现自己有任何异常。\n");
			message_vision(WHT "$N" WHT "眉角微微一动，随即恢复正常。"NOR"\n", me);
			me->start_busy(1);
		} else
		{
			tell_object(me, "结果你没发现" + target->name() + "有任何异常。\n");
			tell_object(target, "你觉得内息一畅，看来是" +  me->name() + "收功了，大概你本来没有什么异常吧。\n");
			message_vision(WHT "$N" WHT "将手掌从$n背后收了回来。"NOR"\n", me, target);
			me->start_busy(2);
			if (! target->is_busy())
				target->start_busy(1);
		}
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
