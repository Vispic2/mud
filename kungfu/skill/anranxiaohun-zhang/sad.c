// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// sad.c 黯然消魂

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
string query_name() { return "黯然"ZJBR"销魂"; }
inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
object weapon;
weapon=me->query_temp("weapon");


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「黯然销魂」只能在战斗中对对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("「黯然销魂」只能空手使用。\n");

        if ((int)me->query("neili") < 1500)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) < 250)
                return notify_fail("你的黯然销魂掌火候不够，无法施展「黯然销魂」。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功修为不够，无法施展「黯然销魂」。\n");


        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("你的玉女剑法火候太浅。\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("你的玉女身法火候太浅。\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("你的天罗地网火候太浅。\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳火候太浅。\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("你的五展梅火候太浅。\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("你的银索金铃火候太浅。\n");
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIM "$N" HIM "一声长叹，心如止水，黯然神伤，于不经意中随"
              "手使出了" HIR "『黯然销魂』" HIM "！\n" NOR;

        ap = me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");

        if (ap * 11 / 20 + random(ap) > dp)
        {
                count = ap / 10;
target->add("qi",-ap);
target->add("eff_qi",-ap);

                        msg +=HIR "只听$n" HIR "一声闷哼，“噗”的一"
                                           "声，这一掌正好击在$p" HIR "肩头。 \n"
                                           NOR;
                msg += HIY "$n" HIY "见$P" HIY "这一招变化莫测，奇幻无"
                       "方，不由大吃一惊，慌乱中破绽迭出。\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "不敢小觑$P" HIC
                       "的来招，腾挪躲闪，小心招架。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        if (count> 200) count=200;
        me->add_temp("apply/attack", count);

        me->add("neili", -200);
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(1);

                 COMBAT_D->do_attack(me, target, weapon, 1);
        }

        me->start_busy(3);
        me->add_temp("apply/attack", -count);

        return 1;
}
