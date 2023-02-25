// suolong.c 锁龙诀

#include <ansi.h>
#include <combat.h>

string name() { return HIW "锁龙诀" NOR; }
string query_name() { return "锁龙诀"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

	//if (userp(me) && ! me->query("can_perform/ruanhong-zhusuo/suolong"))
		//return notify_fail("你还不会使用这一招！\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
              weapon->query("skill_type") != "whip" )
                return notify_fail("你使用的武器不对，无法施展" + name() + "。\n");

        if (me->query_skill("ruanhong-zhusuo", 1) < 150)
                return notify_fail("你的软红蛛索不够娴熟，无法施展" + name() + "。\n");

        if( me->query("neili")<350 )
                return notify_fail("你的内力不够，无法施展" + name() + "。\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("你没有激发软红蛛索，无法施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "使出「锁龙」诀，手中" + weapon->name() +
              HIW "一抖，登时幻出漫天鞭影，宛如蛟龙通天，一齐袭向$n"
              HIW "而去！\n\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 4;
        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIC "结果$p" HIC "被$P" HIC
                       "攻了个措手不及，目接不暇，疲于奔命！\n" NOR;
                count = ap / 12;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "见$N" HIC "鞭势恢弘，心下凛然，凝神应付。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        if (attack_time > 8)
                attack_time = 8;

        me->add("neili", -attack_time*20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(3));
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
