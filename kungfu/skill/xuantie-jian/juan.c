// juan.c 卷字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "风卷"ZJBR"残云"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	int ap, dp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("卷字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 70)
		return notify_fail("你的玄铁剑法不够娴熟，不能使用卷字诀。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，不能使用卷字诀。\n");

	if ((int)me->query("neili") < 100 )
		return notify_fail("你现在内力太弱，不能使用卷字诀。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("你没有激发玄铁剑法，不能施展卷字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N一抖手中的" + weapon->name() + HIY "，自下而上的朝$n"
	      HIY "卷了过去，曲曲折折，变化无常！"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
	if (ap + random(ap / 2) > dp)
	{
		target->start_busy(ap / 20 + 2);
		me->add("neili", -50);
		msg += YEL "$p" YEL "连忙竭力招架，一时无暇反击。"NOR"\n";
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，斜跃避开了$P"
		       CYN "的攻击。"NOR"\n";
		me->add("neili", -25);
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
