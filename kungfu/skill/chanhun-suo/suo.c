#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "琐魂鞭"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("琐魂只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("chanhun-suo", 1) < 50)
		return notify_fail("你的缠魂索功力太浅，使不了绝技琐魂。\n");

	if (me->query_skill_mapped("whip") != "chanhun-suo")
		return notify_fail("你没有激发缠魂索法，使不了绝技琐魂。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，使不了绝技琐魂。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "一声阴笑，使出缠魂索琐魂，挥舞出满天鞭影，将$n"
	      HIR "全全笼罩！"NOR"\n";

	ap = me->query_skill("whip");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIY "结果$n" HIY "被这排山倒海般的攻击攻了个措手不及，陷如困境，完全无法脱身！"NOR"\n";
		target->start_busy((int)me->query_skill("whip") / 22 + 1);
		me->start_busy(1 + random(2));
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，往后一纵，逃开了攻势。。"NOR"\n";
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
