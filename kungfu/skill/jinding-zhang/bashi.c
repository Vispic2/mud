// bashi.c 金顶绵掌 八式合一

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "八式"ZJBR"合一"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int count, d_count, qi, maxqi, skill;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「八式合一」只能在战斗中对对手使用。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的内力还不够高！\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功的修为不够，不能使用八式合一！\n");

	if ((int)me->query_skill("jinding-zhang", 1) < 100)
		return notify_fail("你的金顶绵掌的修习不够，无法使用八式合一！\n");

	if (me->query_skill_mapped("strike") != "jinding-zhang")
		return notify_fail("你没有激发金顶绵掌，无法使用八式合一！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "深深吸了一口气，提起全身的功力于"
	      "双掌，只听的$P" HIY "骨骼一阵爆响！"NOR"\n";
	ap = me->query_skill("strike");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		damage  = (int)me->query_skill("linji-zhuang", 1);
		damage += (int)me->query_skill("jinding-zhang", 1);
		damage /= 3;
		damage += random(damage);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
					   HIR "只见$N" HIR "腾空而起，使出了「八式"
					   "合一」，漫天的掌影，飘忽不定的罩向$n"
					   HIR "全身各个部位，霹雳啪啦$p"
					   HIR "接连中了好多掌！"NOR"\n");
		me->add("neili", -100);
		me->start_busy(2);
	 } else
	 {
		msg += CYN "可是$p" CYN "猛地向后一跃，跳出了$P"
		       CYN "的攻击范围。"NOR"\n";
		me->start_busy(3);
	 }
	 message_combatd(msg, me, target);
	 return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
