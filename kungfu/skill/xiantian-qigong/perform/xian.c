// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIY "先天罡气" NOR; }

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 500)
                return notify_fail("你的先天功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<4000 )
                return notify_fail("你的内力修为不足，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为拳脚，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为内功，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("unarmed") != "xiantian-qigong")
                return notify_fail("你没有准备使用先天功，难以施展" + name() + "。\n");

        if( me->query("neili")<2000 )
                return notify_fail("你现在的真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n$N" HIW "施出先天罡气，顿时将方圆十里天地之气吸入体内"
              "，凝聚于双手手掌处，左手一挥，层层叠叠涌向$n" HIW "！\n" NOR;

        me->add_temp("apply/ap_power", 30);
        ap=me->query_skill("unarmed")+me->query_con()*20;
        dp=target->query_skill("parry")+target->query_dex()*20;

        damage = ap * 2 / 3 ;
        damage+= me->query("jiali");
        damage *= 3;
		if (damage > 10000)
			damage = 10000;
        if (ap / 2 + random(ap) > dp)
        {
                if( !target->is_busy() )
                        target->start_busy(2);
		        target->receive_damage("qi", damage*2 );
				target->receive_wound("qi", damage );
               /* msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 100,
                                                    (: attack1, me, target, damage :));*/
        } else
        {
                msg += CYN "$n" CYN "倒吸一口凉气，飞身一跳，狼狈地躲过这招。\n" NOR;
        }

        message_combatd(msg, me, target);
        msg = HIW "紧接着，$N" HIW "一声清啸，右手虚向$n"HIW"盖下，庞大的天地之气汹涌般压向$n" HIW "！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                if( !target->is_busy() )
                        target->start_busy(2);
		        target->receive_damage("qi", damage*4 );
				target->receive_wound("qi", damage );
                /*msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 500,
                                                   (: attack2, me, target, damage :));*/
        } else
        {
                msg += CYN "$n" CYN "倒吸一口凉气，飞身一跳，狼狈地躲过这招。\n" NOR;
        }

        message_combatd(msg, me, target);
        me->add_temp("apply/ap_power", -30);
        me->add("neili", -1000);

        me->start_busy(3 + random(2));

        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        target->receive_damage("jing", damage / 10);
        target->receive_wound("jing", damage / 10);

        msg = HIR "结果$N" HIR "这掌正中$n" HIR "胸"
              "口，先天罡气登时贯脑而入，接连喷出数"
              "口鲜血。\n" NOR;

        //if (random(2) != 1) return msg;

        target->add("neili", damage);

        msg += WHT "$n" WHT "只感到胸口一痛，全身真气宛若游丝，难受无比。\n" NOR;

        return msg;
}

void clear_no_exert(object target)
{
        if( !objectp(target) ) return;

        target->clear_condition("no_perform");
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "结果$N" HIR "这掌正中$n" HIR "胸"
              "口，先天罡气登时贯体而入，接连喷出数"
              "口鲜血。\n" NOR;

        //if (random(2) != 1) return msg;
        //if( target->query_condition("no_exert") ) return msg;

        target->apply_condition("no_perform", 10);
        call_out("clear_no_exert", 12, target);

        msg += WHT "$n" WHT "感到气脉受损，内息紊乱，说不出的痛苦。\n" NOR;

        return msg;
}
