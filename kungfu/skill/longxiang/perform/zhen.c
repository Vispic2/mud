// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHEN "「" HIW "真·般若极" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp;
        int i, count,damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHEN "只能空手施展。\n");

        if ((int)me->query_skill("longxiang", 1) < 370)
                return notify_fail("你的龙象般若功修为不够，难以施展" ZHEN "。\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("你的内力修为不足，难以施展" ZHEN "。\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("你没有激发龙象般若功为拳脚，难以施展" ZHEN "。\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("你没有激发龙象般若功为内功，难以施展" ZHEN "。\n");



        if (me->query("neili") < 1000)
                return notify_fail("你现在的真气不足，难以施展" ZHEN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "仰天一声怒嚎，将龙象般若功提运至极限，全身顿时罡劲"
              "迸发，真气蒸腾而出，笼罩$N" HIY "\n四方！电光火石间，$N" HIY "双"
              "拳已携着雷霆万钧之势崩击而出，卷起万里尘埃，正是密宗绝学：\n\n" NOR;

        msg += HIW "        般  \n          若    \n        极   \n" NOR;

        msg += HIY "$N" HIY "一道掌力打出，接着便涌出了第二道、第三道掌力，掌势"
               "连绵不绝，气势如虹！直到$N" HIY "\n第十三道掌力打完，四周所笼罩"
               "着的罡劲方才慢慢消退！而$n" HIY "此时却已是避无可避！\n\n" NOR;

        ap =  me->query_skill("unarmed")+ me->query("con") * 20;
        dp =  target->query_skill("parry") + target->query("dex") * 20;

        if (me->query("max_neili") / 2 + random(me->query("max_neili") / 2) > target->query("max_neili"))
        {
                msg += HIR "$n" HIR "全然无力阻挡，竟被$N"
                       HIR "一拳击得飞起，重重的跌落在地上。\n" NOR;
                me->add("neili", -50);
                me->start_busy(1);

                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);

                message_combatd(msg, me, target);

                target->receive_damage("qi", damage);
                if (userp(target) && random(3)==0)
                {
                target->unconcious(me);
              }
              else
              	{
              	target->start_busy(10);
              	}
                return 1;
        } else
        if (ap * 3 / 2 + random(ap) > dp)
        {
                count = ap / 10;
                msg += HIR "$n" HIR "见$P" HIR "来势迅猛之极，一时不知该如"
                       "何作出抵挡，竟呆立当场。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "见$p" HIY "来势迅猛之极，甚难防备，连"
                       "忙振作精神，小心抵挡。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);
if (count>=200) count=200;
        me->add("neili", -300);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);

        return 1;
}

