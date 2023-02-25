#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "柔月"ZJBR"穿空"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/raozhi-roujian/chuankong"))
		return notify_fail("你现在还不会使用「柔月穿空」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「柔月穿空」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("force") < 150)
		return notify_fail("你的内功的修为不够，使不出「柔月穿空」这一招！\n");

	if (me->query_skill("raozhi-roujian", 1) < 90)
		return notify_fail("你的绕指柔剑修为不够，使不出「柔月穿空」这一招！\n");

	if (me->query("neili") < 250)
		return notify_fail("你的真气不够，使不出「柔月穿空」这一招！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIM "$N" HIM "猛地里一声清啸，剑法忽变，那柄" + weapon->name() + HIM
		  "竟似成了一条软带，轻柔曲折，飘忽不定，正是武当派的\n"
		  "七十二招「绕指柔剑」中的一招「柔月穿空」。只见$N" 
		  HIM + weapon->name() + HIM "剑破长空，疾刺$n" HIM "胸膛，"
		  "剑到中途，\n剑尖微颤，竟然弯了过去，斜刺$p" HIM "右肩。"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap);
		me->add("neili", -150);
		me->start_busy(2);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "结果$n" HIR "一个不慎，被$N" HIR
					   "精妙的剑招刺中，一声惨嚎，鲜血飞溅而出！"NOR"\n");
	} else
	{
		me->add("neili", -60);
		me->start_busy(3);
		msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
		       CYN "的剑招。"NOR"\n";
	}

	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
