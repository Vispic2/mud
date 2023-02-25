// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// 力荡群魔

#include <ansi.h>
string query_name() { return "力荡"ZJBR"群魔"; }
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, damage, ap, dp;
        object weapon;
        string msg, pmsg;



        if (! target) target = offensive_target(me);

        if (! target
        ||  ! target->is_character()
        ||  ! me->is_fighting(target))

                return notify_fail(
                        "「"RED"力荡群魔"NOR"」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，加紧攻击吧ⅵ\n");

        if((int)me->query_skill("xuantie-sword", 1) < 120)
                return notify_fail(
                        "你的玄铁剑法不够娴熟，不会使用「"RED"力荡群魔"NOR"」。\n");

        if ((int)me->query_skill("yunv-xinfa", 1) < 120
        &&  (int)me->query_skill("yunv-xinfa", 1) < 120)
                return notify_fail(
                        "你的古墓内功修为太浅，不会使用「"RED"力荡群魔"NOR"」。\n");

        if (me->query_str() < 40)
                return notify_fail(
                        "你的臂力不够，使用「"RED"力荡群魔"NOR"」过于艰难。\n");

        if (me->query("neili") < 300)
                return notify_fail("你的内力不够！\n");

        msg = HIB"骤然间，$N手中"NOR+weapon->query("name")+HIB"发出一阵轰鸣，带着隆隆" +
              "的风雷之声，挟雷霆万均之势，\n一式「"NOR+BLINK+RED"力荡群魔"NOR+HIB"」，" +
              "手中"NOR+weapon->query("name")+HIB"朝$n当头直压下去！\n";

        ap = me->query_skill("sword") + me->query_str() * 2;
        dp = target->query_skill("parry") + target->query_str() * 2;

        if (ap / 2 + random(ap) > dp)
        {
                skill = (int)me->query_skill("xuantie-sword", 1);
                damage  =me->query_skill("sword")*2+random(skill);
                me->add("neili", -200);

                pmsg = HIR "$n无力招架，登时被$N这记重招压得气血翻腾，禁不住「哇」地吐出一口鲜血！\n" NOR;
//                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80, pmsg);
       target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n无力招架，登时被$N这记重招压得气血翻腾，禁不住「哇」地吐出一口鲜血！\n" NOR;
                me->start_busy(1);
                target->start_busy(2);
        } else
        {
                me->add("neili", -100);
                msg += HIW"$p连忙全力一挡，「砰」地一声巨响，$P这记重招居然被$p接了下来！\n" NOR;
                me->start_busy(2);
        }

        message_combatd(msg, me, target);

        return 1;
}


