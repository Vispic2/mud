// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define DANG "「" HIW "神威浩荡" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon, cloth;
        int ap, dp, damage, wp, cl;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DANG "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DANG "只能空手施展。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 240)
                return notify_fail("你的先天功修为不够，难以施展" DANG "。\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        if (me->query("max_neili") < 4000)
                return notify_fail("你的内力修为不足，难以施展" DANG "。\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为拳脚，难以施展" DANG "。\n");

        if (me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为内功，难以施展" DANG "。\n");


        if (me->query("neili") < 800)
                return notify_fail("你现在的真气不足，难以施展" DANG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "只见$N" HIW "双目精光四射，双掌陡然一振，将体内积蓄的"
              "先天真气云贯推出，顿时呼啸\n声大作，先天劲道层层叠叠，宛如"
              "涛浪般涌向$n" HIW "。\n" NOR;

        ap = me->query_skill("unarmed") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");

        if (ap * 11 / 20 + random(ap) > dp)
        {

                        me->start_busy(4);
                        damage = me->query_skill("unarmed")*2;
                        me->add("neili", -400);
               		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=   HIR "$N" HIR "的"
                                                   "罡劲登时瓦解了$n" HIR "的护"
                                                   "体真气，$p" HIR "真元受损，"
                                                   "接连喷出数口鲜血。\n" NOR;


                        if (objectp(weapon = target->query_temp("weapon"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                wp = weapon->name();
                                msg += HIW "只听“锵”的一声脆响，$n" HIW "手"
                                       "中的" + wp + HIW "在$N" HIW "内力激荡"
                                       "下应声而碎，脱手跌落在地上。\n" NOR;
                                me->add("neili", -150);
                                weapon->set("consistence", 0);
                                weapon->move(environment(target));
                        } else

                        if (objectp(cloth = target->query_temp("armor/armor"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                cl = cloth->name();
                                msg += HIW "只听“轰”的一声闷响，$n" HIW "身"
                                       "着的" + cl + HIW "在$N" HIW "内力激荡"
                                       "下应声而裂，化成一块块碎片。\n" NOR;
                                me->add("neili", -150);
                                cloth->set("consistence", 0);
                                cloth->move(environment(target));
                        } else

                        if (objectp(cloth = target->query_temp("armor/cloth"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                cl = cloth->name();
                                msg += HIW "只听“轰”的一声闷响，$n" HIW "身"
                                       "着的" + cl + HIW "在$N" HIW "内力激荡"
                                       "下应声而碎，化成一块块碎片。\n" NOR;
                                me->add("neili", -150);
                                cloth->set("consistence", 0);
                                cloth->move(environment(target));
                        }

        } else
        {
                me->start_busy(4);
                me->add("neili", -120);
                msg += CYN "可是$p" CYN "知道$P" CYN "这招的厉"
                       "害，不敢硬接，当即斜跃躲避开来。\n" NOR;
        }
        message_combatd(msg, me, target);



        return 1;
}
