// cimu.c  辟邪剑法「葵花三式」
// add by Chenzzz 2004-06-04
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "葵花三式"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon, weapon2;
	int lvl;
	int ap, dp;
	int busy_time;
	int cost_neili;
	int no_exert;
	int point;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「葵花三式」只能对战斗中的对手使用。\n");

	if (userp(me) && ! me->query("special_skill/ghost"))
		return notify_fail("你总是暗暗觉得这招运气方式怪异非常，不感贸然使用。\n");
		
	if (target->query_temp("block_msg/all"))
		return notify_fail("对方现在什么也看不见，你放心的继续攻击吧！\n");

	if ((int)me->query_skill("pixie-jian", 1) < 200 )
		return notify_fail("你辟邪剑法不够娴熟，使不出「葵花三式」。\n");

	/*if (me->query_skill_mapped("force") != "pixie-jian")
		return notify_fail("你没有激发辟邪剑法为内功，难以施展「葵花三式」。\n");*/
	if ((int)me->query("max_neili") < 2500)
		return notify_fail("你内力修为不足，无法运足内力。\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail(HIC"你现在真气不够，没能将「刺目」使完！"NOR"\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		msg = HIC "$N" HIC "一声冷笑，左手两指并拢，手臂暴长，迅捷异常分刺$n"
		      HIC "双目，"NOR"\n";
	else
		msg = HIC "$N" HIC "一声冷笑，手中" + weapon->name() +
		      HIC "一振，剑尖一点暴长，分刺$n"
		      HIC "左右双目，"NOR"\n";
		      
	ap = (int)me->query_skill("sword");
	dp = (int)target->query_skill("dodge");
	lvl = (int)me->query_skill("pixie-jian", 1);
	busy_time = 1;
	cost_neili = 100;
	
	if (random(ap) > dp / 2)
	{
		busy_time += 1;		
		cost_neili += 150;
		damage = lvl + (int)me->query_skill("sword", 1) / 2;
		damage = damage / 2 + random(damage);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage / 2, me);
		msg += HIC "$n" HIC "只看到寒尖一点，双目一阵剧痛，眼前一"
		       "黑，就什么也看不见了，顿时长声痛极而呼！"NOR"\n";
		msg += HIC "\n$N" HIC "一招得手，随即发出如鬼笑般的阴笑，$n"
		       HIC "不由觉得一阵透骨寒意。"NOR"\n";
		ap += ap * 3 / 10;
		message_combatd(msg, me, target);
		target->set_temp("block_msg/all", 1);
		call_out("cimu_end", (int) 5 + random(lvl / 25), me, target);
	} else
	{
		busy_time += random(3);
		cost_neili += 100;
		msg += HIY "$p" HIY "情急智生，抬手也向$P"
		       HIY "的右眼刺去，迫得$P" HIY "回剑跃开。"NOR"\n";
		message_combatd(msg, me, target);
	}
	
	if (objectp(weapon2 = target->query_temp("weapon")) && ! random(3))
	{
		if (! objectp(weapon = me->query_temp("weapon")) ||
		    (string)weapon->query("skill_type") != "sword")
			msg = HIC "突然$N" HIC "手指凌空一指，一道无形指气直刺$n"
			      HIC "拿着" +weapon2->name() + NOR HIC "的手腕。"NOR"\n";				 
		else
			msg = HIC "突然$N" HIC "手中" + weapon->name() + NOR
			      HIC "中攻直进，直刺$n" HIC "拿着" +weapon2->name() + NOR 
			      HIC "的手腕。"NOR"\n";  
		if (ap / 3 + random(ap) > dp && random(2))
		{
			busy_time += 1;
			cost_neili += 150;
			msg += HIM "$n" HIM "只觉手腕一阵刺痛，手中" + weapon2->name() + 
			       HIM "再也拿捏不住，脱手而飞！"NOR"\n";
			weapon2->move(environment(target));
		}
		else
		{
			busy_time += random(3);
			cost_neili += 100;
			msg += CYN "可是$n" CYN "看破了$N" CYN "的企图，将手中兵刃挥"
			       "舞得密不透风，挡开了$N" CYN "这一招。"NOR"\n";	 
		}
		message_combatd(msg, me, target);
	}
	else if (!target->is_busy() && random(2))
	{
		msg = HIC "$N" HIC "身子忽进忽退，宛若鬼魅，身形诡秘异常，在$n"
		      HIC "身边飘忽不定。"NOR"\n";
		if (ap / 2 + random(ap) > dp)
		{
			msg += HIC "$p" HIC "霎时只觉眼花缭乱，只能紧守门户，不"
			       "敢妄自出击！"NOR"\n";
			target->start_busy(ap / 22 + 2);
			cost_neili += 150;
		} else
		{
			msg += CYN "可是$p" CYN "看破了$P" CYN "的身法，并没有受"
			       "到任何影响。"NOR"\n";
			busy_time += random(3);
			cost_neili += 100;
		}
		message_combatd(msg, me, target);	       
	}
	else
	{
		msg = HIC "正当$n" HIC "手忙脚乱之时，$N"
		      HIC "已然转至身后，一指戳向$n"
		      HIC "的背心。"NOR"\n";  
		if (ap / 2 + random(ap) > dp)
		{
			damage = ap / 2 + random(ap);
			msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
					   HIC "$n" HIC "全然无法躲避，$N"
					   HIC "的手指端端正正扎进在$p" 
					   HIC "的背心，鲜血登时飞溅"
					   "而出。"NOR"\n");
			busy_time += 1;
			cost_neili += 150;
		} else
		{
			msg += CYN "可是$p" CYN "看破了$P" CYN "这一招，百忙之中变换招式，"
			       "没受到任何伤害。"NOR"\n";
			busy_time += random(3);
			cost_neili += 100;
		}
		message_combatd(msg, me, target);	   
	}

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		msg = HIC "只见$N" HIC "后退几步，左手手指凌空一连七指向着$n"
		      HIC "丹田大穴接连戳出。"NOR"\n";			     
	else
		msg = HIC "忽然$N" HIC "飘前几步，" NOR + weapon->name() + NOR
		      HIC "交左手，右手手指猛然向着$n"
		      HIC "丹田大穴接连戳出。"NOR"\n";   
		      
	if (ap / 4 + random(ap) > dp && target->query_temp("shield") && random(2))
	{
		point = target->query_temp("apply/armor") / 2;
		target->add_temp("apply/armor", - point);
		me->start_call_out((: call_other, __FILE__, "remove_effect_shield", target, point :), me->query_skill("force") / 3);
		busy_time += 1;
		cost_neili += 100;
		msg += HIW "$n" HIW "只觉得丹田一丝刺痛，护体真气竟溃散得荡然无存！"NOR"\n";
		message_combatd(msg, me, target);
	}
	else if (ap / 4 + random(ap) > dp && target->query_temp("powerup") && random(2))
	{
		point = target->query_temp("apply/attack") / 2;
		target->add_temp("apply/attack", - point);
		target->add_temp("apply/defense", - point);
		me->start_call_out((: call_other, __FILE__, "remove_effect_powerup", target, point :), me->query_skill("force") / 3);
		busy_time += 1;
		cost_neili += 100;
		msg += HIW "$n" HIW "只觉得丹田一丝刺痛，一道真气竟然侵入$n"
		       HIW "丹田之内，顿时将凝聚于丹田内的真气摧毁！"NOR"\n";
		message_combatd(msg, me, target);
	}
	else if (ap / 3 + random(ap) > dp && random(2))
	{
		msg += HIW "$n" HIW "只觉得丹田一丝刺痛，身内真气竟然不受控制，"
		       HIW "从丹田源源而泄！"NOR"\n";
		target->add("neili", - ap * 2);
		if (target->query("neili") < 0)
			target->set("neili", 0);

		if (random(2) &&  target->query("no_exert/until") < time() + ap / 10)
		{
			no_exert = ap / 40 + random(ap / 40);
			if (target->query("no_exert/until") > 0)
				target->add("no_exert/until", 
					    no_exert);
			else target->set("no_exert/until", time() +
					 no_exert);
						
			target->set("no_exert/msg", "你内功为辟邪剑法所破，无法"
						    "凝聚真气。\n");
		}
		message_combatd(msg, me, target);
	}
	else
	{
		msg += CYN "可是$p" CYN "识得这招利害，向后退了几步便闪开$P" 
		       CYN "的攻势。"NOR"\n";  
		message_combatd(msg, me, target);		
	}
	me->start_busy(busy_time);
	me->add("neili", -cost_neili);
	return 1;

}

void cimu_end(object me, object target)
{
	if (target && living(target) &&
	    target->query_temp("block_msg/all"))
	{
		message_combatd("$N抹了抹流着" HIR "鲜血" NOR
				"，终于能看见了。\n", target);
		target->set_temp("block_msg/all", 0);
		tell_object(target, HIR "你终于抹掉了眼前的鲜血，能看见了。"NOR"\n");
	}
	return;
}

void remove_effect_shield(object target, int amount)
{
	if (target && living(target))
	{
		target->add_temp("apply/armor", amount);
		tell_object(target, "良久过后，你的护体真气又再凝聚了。\n");
	}
}

void remove_effect_powerup(object target, int amount)
{
	if (target && living(target))
	{
		target->add_temp("apply/attack", amount);
		target->add_temp("apply/defense", amount);
		tell_object(target, "良久过后，你丹田内的真气又再凝聚了。\n");
	}
}

