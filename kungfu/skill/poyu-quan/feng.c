// feng.c 破玉拳「封闭手」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "封闭手"; }
string *pfm_type() { return ({ "cuff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("破玉拳「封闭手」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「封闭手」！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("poyu-quan", 1) < 120)
		return notify_fail("你的破玉拳法不够娴熟，不会使用「封闭手」。\n");

	if (me->query_skill_mapped("cuff") != "poyu-quan")
		return notify_fail("你没有激发破玉拳为拳法，无法使用「封闭手」。\n");

	if (me->query_skill_prepared("cuff") != "poyu-quan")
		return notify_fail("你现在没有准备使用破玉拳，无法使用「封闭手」！\n");


	if (me->query("neili") < 500)
		return notify_fail("你现在真气不够，无法使用「封闭手」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "只见$N" HIC "左掌虚探，右拳飕的一声从掌风中"
	      "猛穿过来，正是破玉拳法的绝招之一“封闭手”。"NOR"\n";

	me->add("neili", -30);
	if (random(me->query_skill("cuff")) > (int)target->query_skill("force") / 2)
	{
		msg += HIR "结果$p" HIR "运力招架，一时却觉得"
		       "内力不济，被$P" HIR "抢住手腕一拉，顿时立足"
		       "不稳，滴溜溜打了两个圈子。"NOR"\n";
		target->start_busy((int)me->query_skill("cuff") / 50 +1);
	} else
	{
		msg += CYN "可是$p" CYN "奋力一架，硬生生格开了$P"
		       CYN "这一拳。"NOR"\n";
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
