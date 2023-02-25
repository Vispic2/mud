// This is player's own perform (Write by Lonely@nt2)
// Create by 心荻(Xiaot) at Sat Mar 11 08:15:25 2006
// 千里冰封(feng)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "千里冰封" NOR "」"
string query_name() { return "千里"ZJBR"冰封"; }
inherit F_SSERVER;


string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count, damage;
        int attack_time;
        int attack, i;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");

        if (member_array("sword", weapon_sk) != -1)
        {

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");
        } else
        {

                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "只能空手使用。\n");
        }

        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("你" + to_chinese("daojian-guizhen") + "不够娴熟，难以施展" PFM "。\n");
	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if (member_array("sword", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("sword") != "daojian-guizhen")
                        return notify_fail("你没有准备" + to_chinese("daojian-guizhen") + "，难以施展" PFM "。\n");
        }

        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N脸色凝重，手中宝剑寒气逼人，剑气撕裂空气，周围忽起阵阵杀机，温度骤降，片片雪花飘落，剑未至气先及，$n如堕冰窖，眉毛都蒙上了薄薄白霜！只见$N一声怒嚎,“千里冰封”，冰气剑茫挟着漫天风雪，以雷霆之势扑向$n,天地为之变色！" + "\n" + NOR;
        ap = me->query_skill("blade",1) + me->query_skill("sword",1);
        dp = target->query_skill("parry",1) + target->query_skill("dodge",1) ;

        if (ap / 2 + random(ap * 2) > dp)
        {
                damage =  ap + random(ap);
               		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=HIM "$n已然冻僵，哪能闪避，$N的寒气剑茫顿时透体而入，口中鲜血狂喷，连退数步。" + "\n" NOR;

                me->add("neili", -200);

                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p见势不妙，顾不上脸面，连着几个懒驴打滚，狼狈之至，险险避过$P的这记杀招，尘土飞扬中，地上裂开了一道大口子！" + "\n" NOR;
                me->add("neili", -100);
        }

       message_combatd(msg, me, target);

        msg = HIW "$N" HIW "余势未尽，招式陡然变得凌厉无比，一转念间已然攻出数招。\n" NOR;
        if (ap / 2 + random(ap * 2) > dp)
        {
                count = ap / 20;
                msg += HIR "$n" HIR "见$P" HIR "来势迅猛之极，一时不知该如"
                       "何作出抵挡，竟呆立当场。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "见$p" HIY "来势迅猛之极，甚难防备，连"
                       "忙振作精神，小心抵挡。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        attack_time = 3;
        attack_time += random(6);
        if (attack_time > 9)
                attack_time = 9;

        me->add("neili", -attack_time * 20);

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, (member_array("sword", weapon_sk) == -1 ? 0 : weapon), 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3 + random(attack_time/ 3));
        return 1;
}

