// tiaoyan.c 夺命三斧之「挑眼式」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "挑眼式"; }

int perform(object me, object target)
{
	string msg;
	int lvl;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「挑眼式」只能在战斗中对对手使用。\n");

	if ((lvl = me->query_skill("duanyun-fu")) < 60)
		return notify_fail("你的夺命三斧还不到家，不会施展「挑眼式」。\n");

	if (me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展「挑眼式」。\n");

	msg = HIG "$N" HIG "使出夺命三斧之「挑眼式」，斧尖疾挑$n" HIG "双眼。"NOR"\n";

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	ap = me->query_skill("axe");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -50);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, lvl, 45,
					   HIR "结果$p" HIR "只觉得眼前一黑，双眼一"
					   "阵剧痛，血流满面。"NOR"\n");
	} else
	{
		msg += HIG "可是$p" HIG "看破了$P" HIG "的企图，急忙躲开了。"NOR"\n";
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
