#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "震雷"ZJBR"乾坤"; }
string *pfm_type() { return ({ "club", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「震雷乾坤」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill_mapped("club") != "qujing-gunfa")
		return notify_fail("你现在并未运用取经棍法，使不出「震雷乾坤」。\n");

       if(me->query_skill("qujing-gunfa", 1) < 160 )
		return notify_fail("你的取经棍法还不够娴熟，使不出「震雷乾坤」。\n");

       if( (int)me->query_skill("force") < 200 )
		return notify_fail("你的内功等级不够，使不出「震雷乾坤」。\n");

	if( (int)me->query("max_neili") < 1800 )
		return notify_fail("你现在内力太弱，使不出「震雷乾坤」。\n");      

	if( (int)me->query("neili") < 200 )
		return notify_fail("你现在真气太弱，使不出「震雷乾坤」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "\n$N" HIW "将手中的" + weapon->name() + HIW "缓缓向$n"
	      HIW "压去，棒端竟隐隐带有风雷之劲，正是取经棍法的杀着「"
	      NOR + HIR "震雷乾坤" NOR + HIW "」。\n陡然间棒端光芒暴"
	      "涨，幻出无数根" + weapon->name() + HIW "，宛如奔雷掣电"
	      "般铺天盖地向$n" HIW "席卷而去！"NOR"\n";

	ap = me->query_skill("club");
	dp = target->query_skill("parry");
	attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "\n结果$n" HIR "被$N" HIR
		       "攻了个措手不及，目接不暇，疲于奔命！"NOR"\n";
		count = ap / 10;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 45);
	} else
	{
		msg += HIC "$n" HIC "见$N" HIC "气势如虹，心下凛然，凝神应付。"NOR"\n";
		count = 0;
	}
		
	message_combatd(msg, me, target);

	if (attack_time > 10)
		attack_time = 10;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(attack_time));
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
