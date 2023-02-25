// 圣火焚躯

#include <ansi.h>
string query_name() { return "圣火"ZJBR"焚躯"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        int ap,dp;
        string msg,str;
        int lvl;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("你只能对战斗中的对手施展圣火焚躯。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你只有空手才能使用圣火拳。\n");

        if (!(me->query_skill_mapped("cuff") == "shenghuo-quan"))
                return notify_fail("你并没有激发圣火拳，如何用圣火焚躯？\n");

        if (!(me->query_skill_prepared("cuff") == "shenghuo-quan"))
                return notify_fail("你并没有准备圣火拳，如何用圣火焚躯？\n");

        if ((int)me->query_skill("shenghuo-quan", 1) < 60)
                return notify_fail("你的圣火拳火候不够。\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力修为不足，无法用内力施展圣火焚躯。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你现在内息不足，无法用内力施展圣火焚躯。\n");

        msg = HIR "只见$N" HIR "一声呼啸，面脸突显一片红光，双拳收于胸口，顷刻从肩膀到拳头都成为赤色。\n\n"
              "$N" HIR "深吸一口气，双拳闪电般飞出，滚滚热浪冲$n" HIR "飞卷而去，令人感到一阵窒息。\n\n"NOR;

        me->start_busy(1 + random(2));
        me->add("neili", -50);

        lvl = me->query_skill("shenghuo-quan", 1);
        damage = lvl + random(lvl/2);

        ap = me->query_skill("cuff");
        ap += me->query_skill("force");
        ap += me->query_str() * 10;
        ap += random(ap/2);
        dp = target->query_skill("dodge");
        dp += target->query_skill("force");
        dp += target->query_dex() * 10;
        dp += random(dp/2);
        if (ap > dp || !living(target))
        {
                msg += HIR "$n" HIR "见炙热拳风扑面涌来，只觉浑身一阵剧痛，"
                               "已被卷入猛烈的拳劲，烈火席卷全身，不由闷哼一声。\n\n" NOR;
                        target->receive_damage("qi", damage, me );
                        target->receive_wound("qi", random(damage/2), me);
                        target->start_busy(2);
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        msg += "($n"+str+")\n";
        } else
        {
                msg += HIY "$n" HIY "见状连忙提运内力，双足点地"
                       "，身形急退，避开了$N" HIY "扑面而来的炙热拳风。\n\n";
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
