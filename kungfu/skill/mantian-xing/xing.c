// xing.c 穹外飞星
// edit by qdz

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "穹外"ZJBR"飞星"; }

int perform(object me, object target)
{
	int skill, i;
	int n;
	int my_exp, ob_exp;
	string pmsg;
	string msg;
	object weapon;

	if (playerp(me) && ! me->query("can_perform/mantian-xing/xing"))
		return notify_fail("你还不会使用「" HIR "穹外飞星" NOR "」这一绝技。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「" HIR "穹外飞星" NOR "」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你现在手中并没有拿着暗器。\n");

	if (weapon->query_amount() < 15)
		return notify_fail("你手中至少要有十五枚暗器才能施展「" HIR "穹外飞星" NOR "」这一招。\n");

	if ((skill = me->query_skill("mantian-xing", 1)) < 80)
		return notify_fail("你的满天星不够娴熟，不会使用「" HIR "穹外飞星" NOR "」这一招。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，不能使用「" HIR "穹外飞星" NOR "」这一招。\n");

	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力修为不足。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你内力不够。\n");

	if ((int)target->query_temp("feixing"))
		return notify_fail("对方已经中了你的绝招，现在是废人一个，赶快进攻吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -100);
	weapon->add_amount(-15);

	message_combatd(HIR "只听$N" HIR "仰天一声清啸，飞身跃起，十指"
			"箕张，一招「穹外飞星」，将手中" + weapon->name() +
			HIR "尽数凌空射出。\n只听破空声骤响，" + weapon->name() +
			HIR "便如同陨星飞坠一般，笼罩$n" HIR "各处大穴！\n" 
			NOR, me, target);

	my_exp = COMBAT_D->valid_power(me->query("combat_exp"));
	ob_exp = COMBAT_D->valid_power(target->query("combat_exp"));

	me->want_kill(target);
	if (my_exp / 2 + random(my_exp * 3 / 2) > ob_exp)
	{
		if (target->query_skill("parry") < me->query_skill("throwing"))
		{
			n = 2 + random(2);
			if (random(my_exp) > ob_exp) n += 1 + random(2);
			if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
			if (random(my_exp / 4) > ob_exp) n += 1 + random(2);

			msg = HIR "只听$n" HIR "惨叫一声，全身同时中了$P"
			      HIR + chinese_number(n) + weapon->query("base_unit") +
			      weapon->name() + HIR "，要穴受创，$n"
			      HIR "直感到两耳轰鸣，目不视物。"NOR"\n", me, target;
			while (n--)
			{
				COMBAT_D->clear_ahinfo();
				weapon->hit_ob(me, target,
					       me->query("jiali") + 100 + n * 10);
			}
			if (stringp(pmsg = COMBAT_D->query_ahinfo()))
				msg += pmsg;

			message_combatd(msg, me, target);

			tell_object(target, RED "你现在要穴受到重损，乃至全身乏力，提不上半点力道！"NOR"\n");
			target->set_temp("feixing", 1);
			target->add_temp("apply/attack", -70);
			target->add_temp("apply/dodge", -70);
			target->add_temp("apply/parry", -20);
			target->receive_damage("qi", 150, me);
			target->receive_wound("qi", 50, me);
			target->kill_ob(me);
			call_out("back", 2 + random(skill / 15), target);
		} else
		{
			message_combatd(HIR "\n$n" HIR "集中生智，双手画圈回旋挥"
				       "舞，拨弄开了要害处的杀着。"NOR"\n", me, target);
			tell_object(target, RED "你只觉全身几处一阵刺痛，知道自己虽被击中，但却是避开了要穴。"NOR"\n");
			target->receive_damage("qi", 100);
			target->receive_wound("qi", 40);
			target->kill_ob(me);
			me->start_busy(1 + random(2));
		}
	} else
	{
		 message_combatd(CYN "可是$n" CYN "小巧腾挪，好不容易避开了"
				 CYN "$N铺天盖地的攻击。"NOR"\n", me, target);
		 me->start_busy(3);
	}   
	return 1;
}

void back(object target)
{
	if (objectp(target))
	{
		target->add_temp("apply/attack", 70);
		target->add_temp("apply/dodge", 70);
		target->add_temp("apply/parry", 20);
		tell_object(target, HIY "渐渐的你觉得力气一丝丝的恢复了。"NOR"\n");
		target->delete_temp("feixing");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
