#include <ansi.h>
#include <combat.h>

#define ZHAI "「" HIW "云边摘月" NOR "」"
string query_name() { return "云边"ZJBR"摘月"; }
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAI "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" ZHAI "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((level = me->query_skill("liancheng-jian", 1)) < 100)
                return notify_fail("你这门剑法不够娴熟，难以施展" ZHAI "。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，难以施展" ZHAI "。\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力修为不够，难以施展" ZHAI "。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你现在真气不够，难以施展" ZHAI "。\n");

        if (me->query_skill_mapped("sword") != "liancheng-jian")
                return notify_fail("你没有激发这门剑法，难以施展" ZHAI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "一声清哮，剑势舒张，吞吐不定，瞬间向$n" HIW "连刺"
              "数剑，企图扰乱$n" HIW "的攻势。\n" NOR;

        me->add("neili", -30);
        if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
		msg += HIR "结果$p" HIR "只见$P" HIR "剑招精妙，全然"
                       "辨不清招中虚实，攻势登时一紧！\n" NOR;
                target->start_busy(level / 50 + 3);
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "剑势的来路，"
                       "径自出招，丝毫不为所动。\n" NOR;
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
