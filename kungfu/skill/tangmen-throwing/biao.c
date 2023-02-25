#include <ansi.h>
#include <combat.h>

string query_name() { return "七子"ZJBR"钢镖"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
        int damage;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/biao"))
                return notify_fail("你还没有受过高人指点，无法施展。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "qizi gangbiao")
                return notify_fail("你现在手中没有拿着暗器七子钢镖，难以施展。\n");

        if ((skill = me->query_skill("tangmen-throwing", 1)) < 120)
                return notify_fail("你的唐门暗器不够娴熟，难以施展。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功修为不足，难以施展。\n");

        if ((int)me->query("max_neili") < 600)
                return notify_fail("你的内力修为不足，难以施展。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你现在真气不足，难以施展。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -100);

        msg = HIR "\n$N" HIR "突然身行一止，从怀中摸出七枚手掌大小的刚镖，一扬手向$n " HIR "掷去。\n"
              "只见七枚钢镖，飞旋打出，$n" HIR "的周身飞舞着无数的光影，却听不到一丝声音。\n"NOR;

        ap = me->query_skill("throwing")+me->query_skill("aqbj")/2;
        dp = target->query_skill("parry") +
             target->query_skill("lonely-sword", 1) / 5;

        message_combatd(msg, me, target);
        tell_object(target, HIR "\n你急忙屏气凝神，希望能够招架这致命的一击。\n"NOR);
        if (ap * 2 / 3 + random(ap / 2) > dp)
        {
                msg = HIR "忽然那无数的光影一闪而没，$n身行一顿，喷出一口鲜血，仰天而倒。\n" NOR;
                message_combatd(msg, me, target);
                tell_object(target, HIR "你只觉得胸口一阵钻心的疼痛。低头一看只见那七枚暗器已经深深的嵌在你的心口。\n"
                                    "血迹中隐约有几个小字[七子刚镖...]。\n"NOR);
                weapon->hit_ob(me, target, me->query("jiali") + 1000);
                weapon->move(environment(me));

                damage = me->query_skill("throwing") + me->query_dex()*5 + me->query("jiali")*2 + me->query_skill("aqbj");
                target->receive_wound("qi", damage, me);
                COMBAT_D->clear_ahinfo();
                //target->unconcious();
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "忽然那无数的光影一闪而没，你心中一惊急忙运内力于全身。\n" NOR);
                msg = HIR "$n" HIR "双臂急舞，衣袖带起破风之声。只听当的一声轻响，竟将那七枚暗器磕飞开去。\n" NOR;
                message_combatd(msg, me, target);
                if ( target->query("neili") < 10000 )
                        target->set("neili", 0);
                else
                        target->add("neili", -1000);
                weapon->move(environment(me));
                me->start_busy(3);
        }
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
