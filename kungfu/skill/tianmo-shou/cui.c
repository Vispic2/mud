// cui.c 催魂

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "催魂"; }
int perform(object me)
{
        string msg;
        object weapon, target;
        int ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/tianmo-shou/cui"))
                return notify_fail("你还不会使用「催魂」绝技。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail("「催魂」只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你只能空手使用「催魂」绝技。\n");

        ap = me->query_skill("tianmo-shou", 1);

        if (ap < 150)
                return notify_fail("你的天魔手等级不够, 无法使用「催魂」！\n");

        if (me->query("neili") < 150)
                return notify_fail("你的真气不够，无法运用「催魂」！\n");

        msg = HIR "$N" HIR "步法忽变，左右横跨数步，口中吟吟有声，双手向$n" HIR
              "缓缓拍到。\n" NOR;

        dp = target->query_skill("parry", 1);
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp || !living(target))
        {
                me->add("neili", -120);
                damage = ap + (int)me->query_skill("force", 1);
                damage = damage / 2 + random(damage / 2);
                target->receive_damage("jing", damage/3, me);
                target->receive_wound("jing", damage/5, me);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "$n" HIR "正自惊疑，不及闪避，登时被"
                                           "拍个正着。顿感精神不济，摇摇欲倒！\n" NOR);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -50);
                msg += CYN "$n" CYN "见来势奇异，精神一振，奋力化解了$N"
                       CYN "这一招。\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}

