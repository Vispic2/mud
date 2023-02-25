#include <ansi.h>
#include <combat.h>

#define SHI "「" HIY "石破天惊" NOR "」"
string query_name() { return "石破"ZJBR"天惊"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(SHI "只能空手施展。\n");

        if ((int)me->query_skill("zhentian-quan", 1) < 80)
                return notify_fail("你的震天拳法不够娴熟，难以施展" SHI "。\n");

        if( me->query("neili")<200 )
                return notify_fail("你的真气不够，难以施展" SHI "。\n");

        if (me->query_skill_mapped("cuff") != "zhentian-quan")
                return notify_fail("你没有激发震天拳法，难以施展" SHI "。\n");

        if (me->query_skill_prepared("cuff") != "zhentian-quan")
                return notify_fail("你现在没有准备使用震天拳法，难以施展" SHI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "猛提内劲，聚力于掌一拳挥出，气势有如石破天惊，"
              "携着呼啸之声向$n" HIY "直贯而去！\n" NOR;

        if (random(me->query_skill("cuff")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("cuff");
                damage = damage / 2 + random(damage / 2);
                me->add("neili", -150);
				COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        } else
        {
                me->start_busy(3);
                me->add("neili", -50);
                msg += CYN "可是$p" CYN "识破了$P"
                       CYN "这一招，斜斜一跃避开。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
