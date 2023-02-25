#include <ansi.h>
#include <combat.h>

#define ZHU "「" HIY "黄龙吐珠" NOR "」"
string query_name() { return "黄龙"ZJBR"吐珠"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHU "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" ZHU "。\n");

        if ((int)me->query_skill("liancheng-jian", 1) < 120)
                return notify_fail("你这门剑法不够娴熟，难以施展" ZHU "。\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("你的内功火候不够，难以施展" ZHU "。\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力修为不够，难以施展" ZHU "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在真气不够，难以施展" ZHU "。\n");

        if (me->query_skill_mapped("sword") != "liancheng-jian")
                return notify_fail("你没有这门剑法，难以施展" ZHU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "回圈手中" + weapon->name() + HIY "施「黄龙吐珠」斜"
              "贯而出，剑尖顿时吐出一道黄芒，闪电般射向$n" + HIY "！\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                damage = damage+600;
                me->add("neili", -150);
                me->start_busy(2);
                                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                msg +=                     HIR "$n" HIR "见状连忙格挡，可哪里来得"
                                           "及，登时只觉全身一麻，剑气已透胸而过。\n"
                                           NOR;
        } else
        {
                me->add("neili", -150);
                me->start_busy(2);
                msg += CYN "可是" CYN "$n" CYN "一声冷"
                       "笑，飞身一跃而起，避开了" CYN
                       "$N" CYN "发出的剑气。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
