#include <ansi.h>
#include <combat.h>

#define SHENG "「" HIW "六道明月夜" NOR "」"
string query_name() { return "六道"ZJBR"明月夜"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
                int i;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHENG "只能在战斗中对对手使用。\n");

        if (me->query_skill("taisu-moon", 1) < 100)
                return notify_fail("你的太素明月式修为不够（要求一百级），难以施展" SHENG "。\n");

        if (me->query_skill_mapped("cuff") != "taisu-moon")
                return notify_fail("你没有激发太素明月式，不能用施展" SHENG "。\n");

        if( me->query("neili")<200 )
                return notify_fail("你现在真气（要求200的内力）不够，难以施展" SHENG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "身法忽快，双拳化作六道残影，突然「砰！砰！」，拳劲连连奔向向$n" HIY "。\n" NOR;

        message_combatd(msg, me, target);

                me->add("neili", -200);

        me->start_busy(1 + random(4));

                for (i = 0; i < 6; i++)
                {
                        if (! me->is_fighting(target))break;

                        if (random(2))target->start_busy(1);

                        COMBAT_D->do_attack(me, target, weapon, 0);
                }


        return 1;
}
