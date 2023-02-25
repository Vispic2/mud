#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIY "当时明月在" NOR "」"
string query_name() { return "当时"ZJBR"明月在"; }
inherit F_SSERVER;

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
                return notify_fail(XIAN "只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对，难以施展" XIAN "。\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("你的内功火候不够，难以施展" XIAN "。\n");

        if ((int)me->query_skill("moon-blade", 1) < 120)
                return notify_fail("你的圆月弯刀还不到家，难以施展" XIAN "。\n");

        if (me->query_skill_mapped("blade") != "moon-blade")
                return notify_fail("你没有激发圆月弯刀，难以施展" XIAN "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你的真气不够，难以施展" XIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
        
        msg = HIY "$N" HIY "刀气横空，刀光烁闪，连环七刀，每刀均令$n" HIY "不得不全神应付，\n"
              "每刀均是朴实古拙，偏又有，明月当空的感觉。\n"
              "且刀刀均针对$n" HIY "的身形变化，似是把$n" HIY "看通看透一般！\n" NOR;
        
        ap = ap = me->query_skill("force") + me->query_skill("blade");
        dp = target->query_skill("dodge") + target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("blade");
                damage *= 3;
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 95,
                                           HIR "霎时一股冰寒的刀气掠过全身，$n" 
                                           HIR "全身顿时鲜血淋漓，摇摇欲倒！\n" NOR);
                me->start_busy(2);
                if (ap / 2 + random(ap * 2) > dp && ! target->is_busy())
                        target->start_busy(ap / 100 + 3);
        } else 
        {
                msg += CYN "$p" CYN "大吃一惊，也不招架，当即向后"
                       "横移数尺，避开了$P" CYN "这一招。\n" NOR;
                me->add("neili", -50);
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
