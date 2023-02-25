// wang.c 天罗地网

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "天罗"ZJBR"地网"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天罗地网」只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon"))
		return notify_fail("你必须空手才能施展「天罗地网」。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("tianluo-diwang", 1)) < 60)
		return notify_fail("你的天罗地网还不够娴熟，不会使用绝招。\n");

	if (me->query_skill_mapped("strike") != "tianluo-diwang")
		return notify_fail("你必须激发天罗地网掌法才能使用绝招。\n");

	if (me->query("neili") < 60)
		return notify_fail("你现在真气不够，无法使用「天罗地网」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "双掌齐出，幻化出无数掌影，将$n" HIG "团团笼罩。"NOR"\n";

	me->add("neili", -35);
	if (random(level) > (int)target->query_skill("dodge", 1) / 2)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "压制的难以反击，"
		       "只能竭力抵挡！"NOR"\n";
		target->start_busy(level / 16 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "身形一闪，跃出$P" CYN "的掌力"
		       "所及的范围。"NOR"\n";
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
