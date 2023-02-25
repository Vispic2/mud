#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "「" HIW "九转乾坤" NOR "」"


int perform(object me, object target)
{
        string msg;
        int count;
        int lvl, damage;
        int i, ap, dp;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yinyang-shiertian/jiu"))
                return notify_fail("你尚未修炼到乾坤境界，难以施展" JIU "！\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "只能对战斗中的对手使用。\n");

        if ((int)me->query("neili") < 900)
                return notify_fail("你的真气不够，无法施展" JIU "！\n");

        if (me->query("max_neili") < 9000)
                return notify_fail("你的内力修为还不足以使出" JIU "。\n");

        if ((int)me->query_skill("force") < 800)
                return notify_fail("你的内功火候不够，难以施展" JIU "！\n");

        if ((lvl = (int)me->query_skill("yinyang-shiertian", 1)) < 800)
                return notify_fail("你的阴阳九转十二重天还不够熟练，无法使用" JIU "！\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIM "\n$N" HIM "运起阴阳九转十二重天，仿佛九天神龙翱翔天际，"
                     HIM "正是无上绝学" JIU HIM "！\n" NOR, me, target);

        ap = me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("yinyang-shiertian", 1);

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "身若游龙，挟风雷之力，从空中向$n"
                             HIW "猛扑下来！\n" NOR, me, target);

                if (ap * 3 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("force");
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 10 ,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的内劲已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 10,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的内劲已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        }
                } else
                {
                        msg = CYN "$n" CYN "气凝双臂，奋力招架，将"
                              "$N" CYN "的内劲卸掉。\n" NOR;
                }

                message_sort(msg, me, target);

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);
        }

        me->start_busy(3 + random(4));
        me->add("neili", -1000 - random(1000));
        return 1;
}


