// ying.c 霹雳刀法「刀影重重」
// By Haiyan

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "刀影重重"; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, zhao;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                 return notify_fail("「刀影重重」只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                 return notify_fail("你使用的武器不对。\n");

        if ((int)me->query_skill("pili-daofa", 1) < 120)
                 return notify_fail("你的霹雳刀法火候不够，无法施展「刀影重重」。\n");

        if (me->query("neili") < 120)
                return notify_fail("你的真气不够，不能使用「刀影重重」。\n");

        msg = HIC "$N" HIC "身法忽变，手中" + weapon->name() + "划出片片刀影，向$n" + HIC
              "一层层卷去。\n" NOR; 

        ap = me->query_skill("blade", 1) / 2 + me->query_skill("pili-daofa", 1);
        dp = target->query_skill("dodge") / 2 + target->query_skill("parry", 1);

        if ( ap / 2 + random(ap) > dp || !living(target))
        {
                msg += HIR "只听$p" HIR "一声惨叫，"
                      "身上顿时被砍得血肉模糊，鲜血崩流！\n" NOR;
                zhao = 5;
                count = ap / 5;
        } else
        {
                msg += CYN "可是$p" CYN "奋力格挡，将$P" CYN
                       "的攻击化解。\n" NOR;
                zhao = 0; 
                count = 0;
        }
                
        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);
        for (i = 0; i < zhao; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(3);

        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
