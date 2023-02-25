// bei.c 若悲

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "明王"ZJBR"若悲"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("明王剑绝技「若悲」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if ((int)me->query_skill("mingwang-jian", 1) < 90)
		return notify_fail("你的不动明王法不够娴熟，不会使用「若悲」。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在真气不够，无法使用「若悲」。\n");

	if (me->query_skill_mapped("sword") != "mingwang-jian")
		return notify_fail("你没有激发明王剑法，无法使用「若悲」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "手中的" + weapon->name() + HIW "轻轻递出，"
	      "发出一阵轻鸣，$n" + HIW "听了心中不禁有些迷茫。"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIG "结果$p" HIG "一时竟然沉迷当中，忘记了继续攻击。"NOR"\n";
		target->start_busy((int)me->query_skill("sword") / 26 + 2);
	} else
	{
		msg += HIC "可是$p" HIC "神智只是略微一滞，随即清醒，没有被$P"
		       HIC "所困扰。"NOR"\n";
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
