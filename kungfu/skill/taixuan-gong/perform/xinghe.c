// xinghe.c 星河影动

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count, n;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("太玄神功「星河影动」只能在战斗中对对手使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("你手中拿着兵器，无法施展「星河影动」。\n");
                
        if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                return notify_fail("你现在没有准备使用太玄神功，无法使用「星河影动」！\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够！\n");

        ap = (int)me->query_skill("taixuan-gong", 1);

        if (ap < 180)
                return notify_fail("你的太玄神功火候不够，无法使用「星河影动」！\n");

        if ((int)me->query_skill("force", 1) < 300)
                return notify_fail("你的内功修为不够，无法使用「星河影动」！\n");

        n = 5 + ap / 100;

        msg = HIW "$N" HIW "气沉丹田，双足一点，身子如旋风般向上卷出，"
              "霎时已向$n" HIW "劈空击出" + chinese_number(n) +
              "招，招招呼啸有声！\n\n" NOR;

        dp = target->query_skill("parry", 1);

        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 5;
                msg += HIR "$n" HIR "刚想避开$P" HIR "这如影如风般的攻势，"
                       "却发现已被一股巨大的劲力包围，无从闪避。\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "凝神应战，聚真气于双臂，奋力化解$P" HIC
                       "这几招。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add("neili", -300);

        for (i = 0; i < n; i++)
        {
                if (! me->is_fighting(target))   break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2 + random(3));
        me->add_temp("apply/attack", -count);

        return 1;
}

