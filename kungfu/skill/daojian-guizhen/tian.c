// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define TIAN "「" HIR "刀剑七重天" NOR "」"
string query_name() { return "刀剑"ZJBR"七重天"; }
inherit F_SSERVER;


int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon;
        int ap, dp, damage;

        if (me->query_skill("daojian-guizhen", 1) < 200)
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if (! me->is_fighting(target))
                return notify_fail(TIAN "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你所使用的武器不对，难以施展" TIAN "。\n");




        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("你没有激发刀剑归真，难以施展" TIAN "。\n");

        if (me->query_skill("daojian-guizhen", 1) < 350)
                return notify_fail("你的剑归真等级不够，难以施展" TIAN "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" TIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("sword") +
             me->query_skill("blade") +
             me->query_skill("daojian-guizhen", 1) * 3 / 2;

        dp = target->query_skill("force") +
             target->query_skill("dodge") +
             target->query_skill("parry", 1);

        damage = me->query_skill("sword",1)+me->query_skill("blade",1);

        msg = HIY "$N" HIY "将" + weapon->name() + HIY "与" +
              weapon->name() + HIY "横置于胸前，运转出「"
              HIR "刀剑七重天" HIY "」功力，内劲如海啸般爆发。\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "见$N" HIR "杀气大涨，不禁心"
                       "生惧意，招架顿时散乱，全然不成章理。\n" NOR;
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "见$N" HIG "杀气大涨，丝毫不"
                       "敢大意，急忙收敛心神，努力不受干扰。\n" NOR;
        }

        msg += HIW "\n突然间$N" HIW "身形一展，右手" + weapon->name() +
               HIW "忽地一振，凌空卷出一道半弧，直劈$n" HIW "而去。\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {

                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "奋力抵挡，却哪里招架得住"
                                           "，被$N" HIR "一招划中要脉，鲜血四处飞"
                                           "溅。\n" NOR;


        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }

        msg += HIW "\n接着$N" HIW "又将左手" + weapon->name() +
               HIW "朝$n" HIW "平平递出，招式看似简单，却蕴藏着"
               "极大的杀着。\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {
                // 转移武器
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "只觉眼花缭乱，全然无法洞"
                                           "察先机，$N" HIR "一招命中，射出一柱鲜"
                                           "血。\n" NOR;
                // 转移回初始状态

        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }
        me->start_busy(3);
        me->add("neili", -300);
        message_combatd(msg, me, target);
        return 1;
}
