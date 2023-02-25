// fuxue.c 拈花指 「拈花拂穴」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "拈花"ZJBR"拂穴"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("拈花拂穴只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你内功火候不够，不能使用拈花拂穴！\n");

	if ((int)me->query_skill("finger") < 150)
		return notify_fail("你的指法修为不够，目前还不能使用拈花拂穴绝技！\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够，不能使用拈花拂穴！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if (me->query_skill_mapped("finger") != "nianhua-zhi") 
		return notify_fail("你没有激发拈花指，无法使用拈花拂穴！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出拈花指绝技「拈花拂穴」，罩住了$n"
	      HIY "的全身，指气层层叠叠的攻向$p" HIY "的要穴！"NOR"\n";

	ap = me->query_skill("finger");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg +=  HIG "结果$p" HIG "被$P" HIG "攻了个措手不及！"NOR"\n";
		target->start_busy((int)me->query_skill("nianhua-zhi", 1) / 45 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += CYN "可是$p" CYN "看破了$P"
		       CYN "的招式，连忙跃开，避开了$P"
		       CYN "的攻击。"NOR"\n";
		me->add("neili", -30);
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
