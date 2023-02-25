// fuxue.c 兰花拂穴手 「兰花拂穴」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "兰花"ZJBR"拂穴"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("兰花拂穴只能对战斗中对手使用。\n");

	if ((int)me->query_dex() < 25)
		return notify_fail("你身法不够，不能使用这一绝技！\n");

	if ((int)me->query_skill("force") < 140)
		return notify_fail("你碧波神功的功力不够不能使用兰花拂穴！\n");

	if ((int)me->query_skill("hand") < 140)
		return notify_fail("你的手法修为不够，目前还不能使用兰"
				   "花拂穴绝技！\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你内力现在不够, 不能使用拈花拂穴！\n");

	if (target->is_busy())
		return notify_fail(target->name() +
				   "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIB "$N" HIB "右手反手伸出，三个指头婉转如一朵盛开的"
	      "兰花，轻盈点向$n" HIB "的胁下要穴。\n";

	ap = me->query_skill("hand");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		msg +=  HIB "结果$p" HIB "被$P" HIB "点个正着，顿时手足"
			"无措，呆立当地！"NOR"\n";
		target->start_busy((int)me->query_skill("lanhua-shou", 1) / 45 + 2);
		me->add("neili", -100);
	} else
	{
		msg += HIY "可是$p" HIY "看破了$P" HIY
		       "的企图，轻轻一跃，跳了开去。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
