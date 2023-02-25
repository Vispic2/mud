// 二十四桥明月夜 by 潇湘夜雨

#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
//#include <balance.h>

#define HUN "「" HIW "二十四桥明月夜" NOR "」"
string query_name() { return "二十四桥"ZJBR"明月夜"; }
string final(object me, object target, int damage);

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (! target)target = me->select_opponent();

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUN "只能对战斗中的对手使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUN "只能空手施展。\n");

        if (me->query_skill("taisu-moon", 1) < 300)
                return notify_fail("你的太素明月式还不够娴熟，难以施展" HUN "。\n");

        if (me->query_skill_mapped("cuff") != "taisu-moon")
                return notify_fail("你现在没有激发太素明月式为拳法，难以施展" HUN "。\n");

        if (me->query_skill_mapped("force") != "taisu-force")
                return notify_fail("你现在没有激发太素心经为内功，难以施展" HUN "。\n");

        if (me->query_skill_mapped("dodge") != "taisu-dodge")
                return notify_fail("你现在没有激发使用太素玲珑步，难以施展" HUN "。\n");

        if (me->query("neili") < 1000)
                return notify_fail("你的内力不够，难以施展" HUN "。\n");
 
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "\n$N" HIG "双手合十，双目微闭，太素真意自心底涌出，猛然间，$N"
              HIG "双手掌心涌出真气，缓缓紧握，随后向前击出，一股猛烈的拳劲奔向$n " HIG "。\n" NOR;
 
        ap = me->query_skill("cuff")*2 + me->query("str") * 15;

        dp = target->query_skill("force") + target->query("con") * 10;

        me->add("neili", -500);

        if (ap / 2 + random(ap) < dp)
        {
        target->add("neili",-500);//如果失败，打击对方内力，消耗等同本身。
                msg += HIY "然而$n" HIY "激发全身内力全力抵挡，终于将$N" HIY
                       "发出的拳劲挡住。\n" NOR;
                me->start_busy(2);
        } else
        {
                me->add("neili", -1000);
                me->start_busy(3);
                damage =me->query_skill("taisu-moon",1)+me->query_skill("taosu-dodge",1)+me->query_skill("taisu-force",1);//基础伤害为太素全套。
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60 + random(5),
                                           (: final, me, target, damage :));

        }
        message_sort(msg, me, target);
        return 1;
}


string final(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 3, me);
        target->busy(2);
        return  HIR "$n" HIR "急忙躲避，可是拳劲奔"
                "得极快极猛，只听$p" HIR "一声惨叫，一股拳"
                "劲已经由外入内，顿时外部鲜血飞溅！$n" HIR "顿"
                "觉极痛，口中更是鲜血喷涌而出。\n" NOR;
}

