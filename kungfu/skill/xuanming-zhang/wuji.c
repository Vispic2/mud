#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "玄冥"ZJBR"无极"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("玄冥无极只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用玄冥无极。\n");	 

	if ((int)me->query_skill("xuanming-zhang", 1) < 150)
		return notify_fail("你的玄冥神掌不够熟练，不会使用玄冥无极。\n");

	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力修为不足，无法使用玄冥无极。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法使用玄冥无极。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = MAG "$N运起玄冥神功，全身浮现出一层紫气，猛然间双掌翻腾，施"
		    "展出绝招玄冥\n无极，携带着万古至毒至寒之气的掌劲已攻向$n！"NOR"\n";  

	lvl = me->query_skill("xuanming-zhang", 1);
	ap = me->query_skill("strike") + me->query("str") * 10;
	dp = target->query_skill("dodge") + target->query("dex") * 10;
	me->start_busy(4);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
		me->add("neili", -400);
		target->apply_condition("xuanming_poison", lvl + (int)target->query_condition("xuanming_poison"));
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
	       MAG "$n只见眼前紫影晃动，突然间胸口一震，已知大势不妙，只感胸口处一股\n寒气升起，尽损三焦六脉。"NOR"\n");
	} else
	{
		msg += HIY "$n看见$N来势汹涌，急忙提气跃开。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
