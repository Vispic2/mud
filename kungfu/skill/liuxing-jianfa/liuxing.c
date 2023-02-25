// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define LIU "「" HIY "天外流星" NOR "」"
string query_name() { return "天外"ZJBR"流星"; }
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" LIU "。\n");

        if (me->query_skill("force") < 120)
                return notify_fail("你的内功的修为不够，难以施展" LIU "。\n");

        if (me->query_skill("liuxing-jianfa", 1) < 120)
                return notify_fail("你的流星剑法修为不够，难以施展" LIU "。\n");

        if (me->query("neili") < 250)
                return notify_fail("你的真气不够，难以施展" LIU "。\n");

        if (me->query_skill_mapped("sword") != "liuxing-jianfa")
                return notify_fail("你没有激发流星剑法，难以施展" LIU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$n" HIY "蓦地眼前光华大盛，$N" HIY "手中" + weapon->name() + HIY
              "活像从天外飞来的流星，只奔$n" HIY "而去，那一瞬间的光芒和速度，没有一件事能阻挡。\n" NOR;
              

		ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
                me->add("neili", -150);
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "尚未反应，已被$N" HIR "手中的" + weapon->name() + 
                                           HIR "当胸搠中，鲜血飞溅！\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", -60);
                
                msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
                       CYN "的剑招。\n" NOR;
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
