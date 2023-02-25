// 圣火普照

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "圣火"ZJBR"普照"; }
int perform(object me, object target)
{
        int damage;
        int ap,dp;
        string msg,str;
        int lvl;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("你只能对战斗中的对手施展圣火普照。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你只有空手才能使用光明神掌。\n");

        if (!(me->query_skill_mapped("strike") == "guangming-zhang"))
                return notify_fail("你并没有激发光明神掌，如何用圣火普照？\n");

        if (!(me->query_skill_prepared("strike") == "guangming-zhang"))
                return notify_fail("你并没有准备光明神掌，如何用圣火普照？\n");

        if ((int)me->query_skill("guangming-zhang", 1) < 80)
                return notify_fail("你的光明神掌火候不够。\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力修为不足，无法用内力施展圣火普照。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在内息不足，无法用内力施展圣火普照      。\n");

        msg = HIR "只见$N" HIR "面色端庄，无喜无怒，无慈无悲，口中喃喃不绝，浑身红光大盛！\n\n"
              "$N" HIR "双掌缓缓抬起，两团耀眼的血色光芒笼罩着手掌，看起来诡异绝伦！\n\n"
              "猛然间，$N" HIR "吐气长啸，双掌迅猛推出，红色光芒带着滚滚热浪将$n整个包围起来！\n\n"NOR;

        me->start_busy(1 + random(2));
        me->add("neili", -50);

        lvl = me->query_skill("guangming-zhang", 1);
        damage = lvl + random(lvl/2);
        damage += me->query("jiali");

        ap = me->query_skill("strike");
        ap += me->query_skill("force");
        ap += me->query_str();
        ap += random(ap/2);
        if (living(target))
        {
                dp = target->query_skill("dodge");
                dp += target->query_skill("force");
                dp += target->query_dex();
                dp += random(dp/2);
        }  else dp = 0;
        if (ap < dp)
        {
                msg += HIY "$n" HIY "屏气凝神，不受满眼红芒的困扰"
                       "，身形急闪，挣脱了$N" HIY "这烈焰滔天的可怕一掌。\n\n";
        } else
        {
                msg += HIR "$n" HIR "只觉得眼前红光一片，再也看不到$N的身形，"
                               "大惊失色下，火浪已经席卷而止，接着胸口给重重印上一掌，不由鲜血狂喷！\n\n" NOR;
                        target->receive_damage("qi", damage, me );
                        target->receive_wound("qi", random(damage/2), me);
                        if (! target->is_busy())
                        target->start_busy(2);
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        msg += "($n"+str+")\n";
        }

        message_combatd(msg, me, target);
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
