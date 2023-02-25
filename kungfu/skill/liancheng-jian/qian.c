#include <ansi.h>
#include <combat.h>

#define QIAN "「" HIY "剑舞千秋" NOR "」"
string query_name() { return "剑舞"ZJBR"千秋"; }
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;


	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" QIAN "。\n");

        if ((int)me->query_skill("liancheng-jian", 1) < 160)
                return notify_fail("你这门剑法不够娴熟，难以施展" QIAN "。\n");

        if ((int)me->query_skill("force") < 220 )
                return notify_fail("你的内功火候不够，难以施展" QIAN "。\n");

        if ((int)me->query("max_neili") < 1800)
                return notify_fail("你的内力修为不够，难以施展" QIAN "。\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("你现在真气不够，难以施展" QIAN "。\n");

        if (me->query_skill_mapped("sword") != "liancheng-jian")
                return notify_fail("你没有激发这门剑法，难以施展" QIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "手中" + weapon->name() + HIY "一声龙吟，三十七势连"
              "城剑连环施出，将$n" HIY "罩在剑光之中。\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

        attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "$p" HIR "只见得剑光万道，顿时被$P" HIR
                       "凌厉的剑招攻得应接不暇，连连后退！\n" NOR;
                count = ap / 10;

                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "见$N" HIC "剑势汹涌，霍霍剑光"
                       "逼人而来，不敢大意，小心应付。\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

	me->add("neili", -attack_time * 25);
me->add_temp("apply/attack", count);
me->add_temp("apply/damage", 350);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
me->add_temp("apply/damage", -350);
                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(3);
        me->add_temp("apply/attack", -count);
	me->start_busy(3);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
