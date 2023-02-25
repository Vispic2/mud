// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define XUE "「" HIW "双刀合壁" NOR "」"
string query_name() { return "双刀"ZJBR"合壁"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        string type, msg;
        object weapon1, weapon2;
        int i, count, damage;
        int ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(XUE "只能对战斗中的对手使用。\n");
        
        weapon1 = me->query_temp("weapon"); 
        weapon2 = me->query_temp("handing"); 

        if (! objectp(weapon1) || ! objectp(weapon2))
                return notify_fail("你没有同时装备双刀，难以施展" XUE "。\n");

        if (weapon2->query("consistence") <= 0)
                return notify_fail("你的" + weapon2->name() + "已经严重"
                                   "损坏，无法继续使用了。\n");

        if (weapon1->query("skill_type") != weapon2->query("skill_type") ||
            weapon1->query("skill_type") != "blade")
                return notify_fail("你所使用的武器不对，难以施展" XUE "。\n");

        type = weapon1->query("skill_type");

        if (me->query_skill(type, 1) < 150)
                return notify_fail("你的" + to_chinese(type) + "太差，"
                                   "难以施展" XUE "。\n");

        if (me->query_skill_mapped(type) != "yanzi-blade")
                return notify_fail("你没有激发燕子双飞刀法，难以施展" XUE "。\n");

        if (me->query_skill("yanzi-blade", 1) < 150)
                return notify_fail("你的燕子双飞刀法等级不够，难以施展" XUE "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" XUE "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "手持两把刀，攻向$n " HIW "。可是在这一刹那间，两把刀仿佛忽然变成了一把刀。\n"
              HIW "双刀合壁，力量竟增加了一倍，本该是一千斤的力量，竟增加为两千斤。力量增加了一倍，速度当然也要增加一倍。\n"
              HIW "$N" HIW "双刀合壁，两把刀明明已合而为一，却又偏偏仿佛是从两个不同的方向劈下来的。\n"
              HIW "明明是砍向$n" HIW "的右边，可是$n" HIW "往左闪避，还是闪不开。$n" HIW "往右闪，更闪不开。\n" NOR;
        

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap * 2) > dp)
        {
                damage = me->query_skill("blade") * 2;
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 85,
                                           HIR "只见$n" HIR "一声惨叫，胸口给"
                                           "劈开一个巨大的口子，鲜血汹涌喷出！\n" NOR);
                me->start_busy(2);
                if (ap / 3 + random(ap / 2) > dp && ! target->is_busy())
                        target->start_busy(3);
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
