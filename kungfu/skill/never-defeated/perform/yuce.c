// yuce.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "御策"ZJBR"器决"; }

int perform(object me, object target)
{
	int skill, i;
	int n;
	int my_exp, ob_exp;
	string pmsg;
	string msg;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("御策诀只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing" ||
	    weapon->query_amount() < 1)
		return notify_fail("你现在手中并没有拿着暗器，怎么施展御策诀？\n");

	if ((skill = me->query_skill("never-defeated", 1)) < 100)
		return notify_fail("你的不败神功火候不够，不会施展御策诀。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -120);
	weapon->add_amount(-1);

	msg = HIC "$N" HIC "手指一合一弹，只听呼啸破空声起，有若龙吟，一" +
	     weapon->query("base_unit") + weapon->name() + HIC "如蛟龙般" +
	     "打向$n" HIC "。"NOR"\n";

	me->start_busy(1);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("parry");
	if (random(my_exp) > ob_exp * 2 / 3)
	{
		msg += HIR + "只见那" + weapon->name() + HIR "去势恰如神光闪电！$n"
		       HIR + "不及闪避，被打了个正中，惨叫一"
		       "声，退了几步。"NOR"\n";
		target->receive_wound("qi", skill / 2 + random(skill / 2), me);
		COMBAT_D->clear_ahinfo();
		weapon->hit_ob(me, target,
			       me->query("jiali") + 150);
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += CYN "可是$p" CYN "急忙一闪，躲过了$P" HIG "发出的" +
		       weapon->name() + CYN "。"NOR"\n";
		message_combatd(msg, me, target);
	}

	me->reset_action();
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
