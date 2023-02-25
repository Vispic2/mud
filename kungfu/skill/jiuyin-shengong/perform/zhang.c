// zhang.c 九阴神掌

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "九阴"ZJBR"神掌"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("九阴神掌只能对战斗中的对手使用。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("jiuyin-shengong", 1) < 100)
		return notify_fail("你的九阴神功不够深厚，不会使用九阴神掌。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "双掌一错，幻化出无数掌影，层层叠荡向$n"
	      HIY "逼去！"NOR"\n";

	ap = me->query_skill("strike") * 3 / 2 +
	     me->query_skill("martial-cognize", 1);
	dp = target->query_skill("parry") +
	     target->query_skill("martial-cognize", 1);

	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "逼得施展不开半点招式！"NOR"\n";
		target->start_busy( me->query_skill("jiuyin-shengong", 1)/ 45 + 4);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的掌势来路，"
		       "镇定自若，应对自如。"NOR"\n";
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
