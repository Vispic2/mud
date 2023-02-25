// dian.c 神指点穴

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "神指"ZJBR"点穴"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「神指点穴」只能对战斗中的对手使用。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("sun-finger", 1) < 80)
		return notify_fail("你的一阳指法不够娴熟，不会使用「神指点穴」。\n");

	if (me->query_skill_mapped("finger") != "sun-finger")
		return notify_fail("你没有激发一阳指法，不能使用「神指点穴」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "凝神攻出一指，变化多端，巧妙的威胁$n"
	      HIY "诸处大穴！"NOR"\n";

	ap = me->query_skill("finger");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "逼得招"
		       "架不迭，一时无法反击！"NOR"\n";
		target->start_busy(ap / 26 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的变化，"
		       "小心招架，挡住了$P" CYN "的进击。"NOR"\n";
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
