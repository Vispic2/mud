// tan.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "弹指"ZJBR"神功"; }

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
		return notify_fail("弹指只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing" ||
	    weapon->query_amount() < 1)
		return notify_fail("你现在手中并没有拿着暗器，怎么施展弹指？\n");

	if ((skill = me->query_skill("tanzhi-shentong", 1)) < 100)
		return notify_fail("你的弹指神通不够娴熟，不会使用弹指。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -90);
	weapon->add_amount(-1);

	msg = HIC "$N" HIC "合指轻弹，只听破空声大作，一" +
	     weapon->query("base_unit") + weapon->name() + HIC "疾速飞出" +
	     "，打向$n" HIC "。"NOR"\n";

	me->start_busy(2);
	my_exp = me->query_skill("finger");
	ob_exp = target->query_skill("dodge");
	if (random(my_exp) > ob_exp * 2 / 3)
	{
		msg += HIR + weapon->name() + HIR "来得好快，$n"
		       HIR + "一个闪避不及，被打了个正中，浑身一"
		       "阵剧痛，整个人几乎都要散架了。"NOR"\n";
		target->receive_wound("qi", skill / 2 + random(skill / 2), me);
		COMBAT_D->clear_ahinfo();
		weapon->hit_ob(me, target,
			       me->query("jiali") + 150);
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += CYN "可是$p" CYN "轻轻一闪，躲过了$P" HIG "发出的" +
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
