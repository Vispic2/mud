// hanxing-fada/lastrisk.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "孤注"ZJBR"一掷"; }

int perform(object me, object target)
{
	int i, skill;
	string msg;
	object *ob;
	object weapon;
	string pmsg;
	int ap, dp;
	int n;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("孤注一掷只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing" ||
	    weapon->query_amount() < 1)
		return notify_fail("你手中必须先有暗器。\n");

	if ((skill = me->query_skill("hanxing-bada", 1)) < 60)
		return notify_fail("你的寒星八打修为太浅，无法施展孤注一掷。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN "孤注一掷，发出所有暗器攻向$n" CYN "！"NOR"\n";
	me->start_busy(2);
	ap = me->query_skill("throwing");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "攻了个措手不及，中了数枚暗器！"NOR"\n";
		target->receive_wound("qi", skill / 2 + random(skill / 2), me);
		COMBAT_D->clear_ahinfo();
		n = random(weapon->query_amount()) + 1;
		if (n > 5) n = 5;
		while (n--)
			weapon->hit_ob(me, target, me->query("jiali") + 120);

		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
	} else
	{
		msg += CYN "可是$p" CYN "从容不迫的躲过了$P"
		       CYN "的最后一击。"NOR"\n";
	}

	message_combatd(msg, me, target);
	destruct(weapon);
	me->reset_action();
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
