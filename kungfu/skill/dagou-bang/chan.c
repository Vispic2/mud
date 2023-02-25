// chan.c 打狗棒法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "缠字诀"; }
string *pfm_type() { return ({ "staff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("打狗棒法「缠」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if ((int)me->query_skill("dagou-bang", 1) < 70)
		return notify_fail("你的打狗棒法不够娴熟，不会使用「缠」字诀。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功不够深厚，不会使用「缠」字诀。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在的真气不够，无法使用「缠」字诀。\n");

	if (me->query_skill_mapped("staff") != "dagou-bang")
		return notify_fail("你没有激发打狗棒法，不能使用「缠」字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "使出打狗棒法「缠」字诀，棒头在地"
	      "下连点，连绵不绝地挑向$n" HIG "的小腿和脚踝。\n";

	me->add("neili", -50);
	ap = me->query_skill("staff");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR " 结果$p" HIR "被$P" HIR "攻的蹦跳不停，手忙脚乱！"NOR"\n";
		target->start_busy((int)me->query_skill("dagou-bang") / 20);
	} else
	{
		msg += "可是$p" HIG "看破了$P" HIG
		       "的企图，镇定解招，一丝不乱。"NOR"\n";
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
