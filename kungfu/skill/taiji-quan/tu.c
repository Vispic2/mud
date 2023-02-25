// tu.c 太极图

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "太极图"; }

int perform(object me)
{
	object *obs;
	string msg;
	int damage;
	int ap, dp;
	int flag;
	int i;

	if (userp(me) && me->query("can_perform/taiji-quan/tu") < 10)
		return notify_fail("你还不会运用「太极图」。\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能打架。\n");

	me->clean_up_enemy();
	if (! me->is_fighting())
		return notify_fail("「太极图」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("taiji-quan", 1) < 250)
		return notify_fail("你的太极拳不够娴熟，不会使用「太极图」。\n");

	if ((int)me->query_skill("taiji-shengong", 1) < 300)
		return notify_fail("你的太极神功修为还不够高，难以运用「太极图」。\n");

	if ((int)me->query_skill("taoism", 1) < 300)
		return notify_fail("你的道学心法修为还不够高，难以运用「太极图」。\n");

	if ((int)me->query("jingli") < 1000)
		return notify_fail("你现在精力不够，无法使用「太极图」。\n");

	if ((int)me->query("neili", 1) < 1000)
		return notify_fail("你现在真气不够，无法使用「太极图」。\n");
/*
	if (objectp(me->query_temp("weapon")) ||
	    objectp(me->query_temp("secondary_weapon")))
		return notify_fail("要施展绝技「太极图」必须空手。\n");
*/
	msg = HIM "$N" HIM "淡然一笑，双手轻轻划了数个圈子，顿时四周的气"
	      "流波动，源源不断的被牵引进来。"NOR"\n";
	message_combatd(msg, me);

	me->add("neili", -1000);
	me->add("jingli", -1000);
	me->start_busy(4);
	ap = me->query_skill("taoism", 1) +
	     me->query_skill("taiji-quan", 1) +
	     me->query_skill("taiji-shengong", 1);
	obs = me->query_enemy();
	for (flag = 0, i = 0; i < sizeof(obs); i++)
	{
		dp = obs[i]->query_skill("force") +
		     obs[i]->query_skill("taoism", 1);
		if (ap / 2 + random(ap) > dp)
		{
			switch (random(3))
			{
			case 0:
				tell_object(obs[i], HIY "恍惚之间你似乎回到了过去的世界，竟"
						    "然再无法控制自我，忽然眼前的一切\n"
						    "又全然不见，你心头一乱，浑身一阵剧"
						    "痛，内力紊乱难以控制！"NOR"\n");
				break;
			case 1:
				tell_object(obs[i], HIW "你眼前一切渐渐的模糊起来，好像是到"
						    "了仙境，然而你却觉得内息越来越乱，\n"
						    "四肢一阵酸痛，几乎要站立不住。"NOR"\n");
				break;
			default:
				tell_object(obs[i], HIR "你耳边忽然响起一个霹雳，眼见雷神挥"
						    "舞电锤向你打来，你不禁大吃一惊，\n"
						    "浑身上下都不听使唤，只有高声呼救。"NOR"\n");
				break;
			}
			// receive damage of qi
			//damage = obs[i]->query("max_qi");
			damage = me->query("max_qi");
			damage = damage * (15 + random(6)) / 100;
			obs[i]->receive_damage("qi", damage, me);
			obs[i]->receive_wound("qi", damage / 2, me);

			// receive damage of jing
			//damage = obs[i]->query("max_jing");
			damage = me->query("max_jing");
			damage = damage * (15 + random(6)) / 100;
			obs[i]->receive_damage("jing", damage, me);
			obs[i]->receive_wound("jing", damage / 3, me);

			switch (random(3))
			{
			case 0:
				msg = HIM "只见" + obs[i]->name() +
				      HIM "手舞足蹈，忘乎所以，忽"
				      "然大叫一声，吐血不止！"NOR"\n";
				break;
			case 1:
				msg = HIR "却见" + obs[i]->name() +
				      HIR "容貌哀戚，似乎想起了什"
				      "么伤心之事，身子一晃，呕出数口鲜血！"NOR"\n";
				break;
			default:
				msg = HIW + obs[i]->name() +
				      HIW "呆立当场，一动不动，有如中"
				      "邪，七窍都迸出鲜血来。"NOR"\n";
				break;
			}
			obs[i]->start_busy(3);
			message("vision", msg, environment(me), ({ obs[i] }));
			obs[i]->add("neili", -500);
			flag = 1;
		} else
		{
			tell_object(obs[i], HIG "你发现眼前的景物似幻似真，连忙"
					    "默运内功，不受困扰。"NOR"\n");
			obs[i]->add("neili", -200);
		}
		if (obs[i]->query("neili") < 0)
			obs[i]->set("neili", 0);
	}

	if (! flag) 
		message_vision(HIM "然而没有任何人受了$N"
			       HIM "的影响。"NOR"\n", me, 0, obs);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
