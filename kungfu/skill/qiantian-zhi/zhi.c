// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIR "乾阳神指" NOR; }
string query_name() { return "乾阳"ZJBR"神指"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int n, skill;
        int damage, ap, dp ;
        string msg;
		skill = me->query_skill("qiantian-zhi", 1);
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("qiantian-zhi", 1) < 80)
                return notify_fail("你乾天指法不够娴熟，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("finger") != "qiantian-zhi")
                return notify_fail("你没有激发乾天指法，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("finger") != "qiantian-zhi")
                return notify_fail("你没有准备乾天指法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你内功修为不够，难以施展" + name() + "。\n");

        if( me->query("neili")<100 )
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "陡然使出一招「乾阳神指」，双指齐施，同时朝$n"
              HIR "面门及胸口处点去。\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        msg = HIY "$N" HIY "出手成指，随意点戳，似乎看尽了$n"
              HIY + "招式中的破绽。\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                n = 4 + random(4);
                if (ap * 11 / 20 + random(ap) > dp)
                {
                        msg += HIY "$n" HIY "见来指玄幻无比，全然无法抵挡，慌乱之下破绽迭出，$N"
                               HIY "随手连出" + chinese_number(n) + "指！\n" NOR;
                        message_combatd(msg, me, target);
                        me->start_busy(1 + random(n));
                        while (n-- && me->is_fighting(target))
                        {
                                if (random(2) && ! target->is_busy())
                                	target->start_busy(1);

                                COMBAT_D->do_attack(me, target, 0, 0);
                        }

                        weapon = target->query_temp("weapon");
                        if (weapon && random(ap) / 2 > dp && weapon->query("type") != "pin")
                        {
                                msg = HIW "$n" HIW "觉得眼前眼花缭乱，手中的" + weapon->name() +
                                      HIW "一时竟然拿捏不住，脱手而出！\n" NOR;
                                weapon->move(environment(me));
                        } else
                        {
                                msg = HIY "$n勉力抵挡，一时间再也无力反击。\n" NOR;
                        }

                        if (! me->is_fighting(target))
                                // Don't show the message
                                return 1;
                } else
                {
                        msg += HIY "$n" HIY "不及多想，连忙抵挡，全然无法反击。\n" NOR;
			if (! target->is_busy())
                        	target->start_busy(4 + random(skill / 30));
                }
        } else
        {
                msg += HIC "不过$n" HIC "紧守门户，不露半点破绽。\n" NOR;
                me->start_busy(3 + random(2));
        }

        message_combatd(msg, me, target);
        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
