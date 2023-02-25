// qimen.c  落英神掌「奇门五转」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "奇门"ZJBR"五转"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「奇门五转」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("luoying-shenzhang", 1) < 80)
		return notify_fail("你的落英神掌不够娴熟，不会使用「奇门五转」。\n");

	if ((int)me->query_skill("qimen-wuxing", 1) < 100)
		return notify_fail("你对奇门五行的研究不够透彻，无法运用「奇门五转」。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够高，无法使用「奇门五转」。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在内力不够，无法使用「奇门五转」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "突然变幻莫测，双掌翻飞，虚虚实实的攻向$n" HIG "。"NOR"\n";

	ap = (int)me->query_skill("luoying-shenzhang", 1) +
	     (int)me->query_skill("qimen-wuxing", 1) +
	     (int)me->query_skill("force") +
	     (int)me->query("int") * 10;

	dp = (int)target->query_skill("force") +
	     (int)target->query_skill("parry") +
	     (int)target->query_skill("qimen-wuxing", 1) +
	     (int)target->query("int") * 10;

	me->start_busy(1);
	me->add("neili", -150);
	if (ap / 2 + random(ap) > dp)
	{
		damage = (int)me->query_skill("force") + (int)me->query_skill("strike");
		damage = damage / 3;
		damage += random(damage);

		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 55,
					   HIR "$n" HIR "大吃一惊，哪里抵挡得了，"
					   "“蓬蓬”接连中掌，狂吐一口鲜血，身子急"
					   "转个不停。"NOR"\n");
	} else
		msg += HIG "可是$p" HIG "看破了$P" HIG
		       "的企图，连消带打，避开了$P" HIG "这一击。"NOR"\n";

	message_vision(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
