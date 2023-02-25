// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIR "明月战天" NOR; }
string query_name() { return "明月"ZJBR"战天"; }
int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手使用。\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("你内功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<3000 )
                return notify_fail("你内力修为不够，难以施展" + name() + "。\n");

        if ((int)me->query_skill("taisu-moon", 1) < 200)
                return notify_fail("你太素明月式火候不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("cuff") != "taisu-moon")
                return notify_fail("你没有激发太素明月式，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("cuff") != "taisu-moon")
                return notify_fail("你没有准备太素明月式，难以施展" + name() + "。\n");

        if( me->query("neili")<1000 )
                return notify_fail("你现在真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        // 第一掌
		ap = me->query_skill("cuff") + me->query("str") * 20;
		dp = target->query_skill("dodge") + target->query("dex") * 10;
        damage = me->query_skill("cuff");
        damage+= me->query("jiali");

        message_combatd(sort_msg(HIM "\n忽然间$N" HIW "身形激进，左拳紧握，右手张开，拳劲与掌劲顿时爆发，便"
                     "向$n" HIW "击去，正是太素明月式「" NOR + HIY "明月战天第一式" NOR
                     + HIW "」一招，力自拳生之际说到便到，势不可挡向$n" HIW
                     "击去。。\n" NOR), me, target);
        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target,UNARMED_ATTACK, damage, 65,
                                          HIR "$p" HIR "一楞，只见$P" HIR "身形"
                                          "一闪，已晃至自己跟前，躲闪不及，被击"
                                          "个正中。\n:内伤@?");

                message_combatd(msg, me, target);

        } else
        {
                msg = HIC "$p" HIC "内劲涌出，凝神应对，游刃有余，$P"
                      HIC "拳劲如泥牛入海，尽数卸去。\n" NOR;
                message_combatd(msg, me, target);
        }

        // 第二掌
        ap = me->query_skill("cuff") + me->query("str") * 25;
        dp = target->query_skill("parry") + target->query("dex") * 10;

        message_combatd(sort_msg(HIW "\n$N" HIW "一招既出，身子已然抢到离$n" HIW "三四丈之外"
                     "，后拳紧握，前拳如图幻影般击出，此为「" NOR + HIY "明月"
                     "战天第二式" NOR + HIW "」，拳力犹如怒潮狂涌，势不可当。霎时$n"
                     HIW "带着破空声到飞  。\n" NOR), me, target);
        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK,damage, 65,
                                           HIR "只听$p" HIR "一声惨嚎，被$P" HIR
                                           "一拳击中腰间，“喀嚓喀嚓”断了好几根肋"
                                           "骨。");

                message_combatd(msg, me, target);
        } else
        {
                msg = HIC "$p" HIC "气贯双臂，凝神应对，游刃有余，$P"
                      HIC "拳力如泥牛入海，尽数卸去。\n" NOR;
                message_combatd(msg, me, target);
        }

        // 第三掌
        ap = me->query_skill("cuff") + me->query("str") * 30;
        dp = target->query_skill("force") + target->query("dex") * 10;

        message_combatd(sort_msg(HIW "\n紧跟着$N" HIW "一声暴喝，右拳极速挥出，前招拳力未消"
                     "，两股拳劲合二为一，又攻出一招「" NOR + HIY "明月战天第三式" NOR
                     + HIW "」，拳劲猛如龙虎，向前疾冲而"
                     "去。$n" HIW "只觉气血翻涌，气息沉浊。\n" NOR), me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK,damage, 75,
                                           HIR "结果$p" HIR "躲闪不及，$P" HIR
                                           "的拳劲顿时穿胸而过，“哇”的喷出一大"
                                           "口鲜血。\n:内伤@?");

                message_combatd(msg, me, target);
                me->start_busy(1 + random(3));
                me->add("neili", -200-random(100));
                return 1;
        } else
        {
                msg = HIC "$p" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，脱出$P" HIC "拳劲之外。\n" NOR;
                message_combatd(msg, me, target);
                me->start_busy(1 + random(3));
                me->add("neili", -200-random(100));
                return 1;
        }
        message_combatd(msg, me, target);
        return 1;
}
