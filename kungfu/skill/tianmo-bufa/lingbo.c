// lingbo.c  移形换影

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return ""HIW"移形"ZJBR""HIW"换影"NOR""; }

int perform(object me, object target)
{
	string msg;
	int level;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("移形换影只有在战斗中才能使用。\n");

	if ((level = me->query_skill("tianmo-bufa", 1)) < 180)
		return notify_fail(HIY "你的天魔步法还不够熟练。"NOR"\n");

	if ((int)me->query("neili") < 500)
		return notify_fail(HIY "你现在真气不足。\n" HIY);

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if( me->query("gender") == "女性")
	       msg = HIW "$N" HIW "提起真气，依照先天伏羲六十"
		     "四卦，不理$n" HIW "如何出招，自顾自的将"
		     "移形\n步由头到尾迅速无比的走了一次。"
		     "$N" HIW "仿如换影再生，移形换影，$n" HIW
		     "却是一点\n皮毛也沾不上。$N" HIW "真个将"
		     "逍遥二字发挥得淋漓尽至。"NOR"\n";

	else   msg = HIC "$N" HIC "提起真气，依照先天伏羲六十"
		     "四卦，不理$n" HIC "如何出招，自顾自的将"
		     "移形换\n影由头到尾迅速无比的走了一次。"
		     "只见$N" HIC "意态飘逸，影子乱飞，$n" HIC
		     "却是一点\n皮毛也沾不上。$N" HIC "真个将"
		     "逍遥二字发挥得淋漓尽至。"NOR"\n";

	if (random(level) > (int)target->query_skill("dodge", 1) / 2)
	{
		msg += HIW "结果$p" HIW "被$P" HIW "围着转得头晕眼花！"NOR"\n";
		target->start_busy(level / 20);
		me->add("neili", -500);
	} else
	{
		msg += HIY "结果$p" HIY "只是勉强的逃了开去。"NOR"\n";
		me->add("neili", -500);
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
