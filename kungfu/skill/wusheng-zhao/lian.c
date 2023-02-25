#include <ansi.h>
#include <combat.h>

string query_name() { return "五圣"ZJBR"毒爪"; }

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(query_name()+ "只能在战斗中对对手使用。\n");

		//if (userp(me) && ! me->query("can_perform/wusheng-zhao/lian"))
		//return notify_fail("你还不会使用这一招！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用" +query_name()+ "。\n");

        skill = me->query_skill("wusheng-zhao", 1);

        if (skill < 120)
                return notify_fail("你的五圣毒爪等级不够，难以施展" + query_name() + "。\n");

        if( me->query("neili")<200 )
                return notify_fail("你的真气不够，难以施展" + query_name() + "。\n");

        if (me->query_skill_mapped("claw") != "wusheng-zhao")
                return notify_fail("你没有激发五圣毒爪，难以施展" + query_name() + "。\n");

        if (me->query_skill_prepared("claw") != "wusheng-zhao")
                return notify_fail("你没有准备使用五圣毒爪，难以施展" + query_name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "身形一展，扑至$n" HIY "跟前，猛然施展「夺"
              "命连环」，双爪幻作数道金光，直琐$n" HIY "各处要脉！\n" NOR;


		ap = me->query_skill("claw");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = me->query_skill("claw");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$p" HIR "奋力抵抗，结果还是连中$P"
                                           HIR "数抓，登时鲜血飞溅，无法反击！\n" NOR);
                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 100 + 2);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的招式，巧妙的一一拆解，没露半点破绽！\n" NOR;
                me->add("neili", -50);
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
