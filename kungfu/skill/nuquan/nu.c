// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define PO "「" MAG "一怒杀佛" NOR "」"
string query_name() { return "一怒"ZJBR"杀佛"; }
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("nuquan", 1) < 40)
                return notify_fail("你的怒拳不够娴熟，无法施展" PO "。\n");
                                
        if ((int)me->query("neili") < 200)
                return notify_fail("你现在真气不够，无法施展" PO "。\n");

        if (me->query_skill_prepared("cuff") != "nuquan")
                return notify_fail("你没有准备使用怒拳，无法施展" PO "。\n");

        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "拳劲如芒、使拳如雷、拳气如风、拳风如雾，拳劲彷佛无所不在，狠狠打击$n" 
              HIY "的视、听、闻、味、触五觉。\n" NOR;
		ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("cuff");

                me->add("neili", -120);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75,
                                           HIR "顿时$n" HIR "防守大受影响，只见$N" HIR "这一拳把$n" HIR
                                           "飞了出去，重重的摔在地上，吐血不止！\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += HIC "可是$p" HIC "奋力招架，硬生生的挡开了$P"
                       HIC "这一招。\n"NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
