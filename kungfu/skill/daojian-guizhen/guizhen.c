// This is player's own perform (Write by Lonely@nt2)
// Create by 心荻(Xiaot) at Fri Mar 10 11:48:11 2006
// 反璞归真(guizhen)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "反璞归真" NOR "」"
string query_name() { return "反璞"ZJBR"归真"; }
inherit F_SSERVER;


string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int attack;



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

        if (member_array("sword", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("sword") != "daojian-guizhen")
                        return notify_fail("你没有准备" + to_chinese("daojian-guizhen") + "，难以施展" PFM "。\n");
        }
        	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N突然刀剑互易、颠倒刚柔，刀又是剑，剑又是刀，或变或不变，幻出一片刀光剑影，教$n难以捉摸,正是刀剑的终极杀招“反璞归真”！" + "\n" + NOR;

        ap = me->query_skill("blade",1) + me->query_skill("sword",1);
        dp = target->query_skill("parry",1) + target->query_skill("dodge",1) ;

        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = ap + random(ap);
               		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=HIM "只见$n一声惨叫，胸口给劈开一个巨大的口子，鲜血汹涌喷出！" + "\n" NOR;
                me->add("neili", -200);
                me->start_busy(1);
                if (! target->is_busy())
                        target->start_busy(3);
        } else
        {
                msg += NOR + CYN "$p见势不妙，抽身急退，险险避过$P的这记杀招，尘土飞扬中，地上裂开了一道大口子！" + "\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }

        message_combatd(msg, me, target);
        return 1;
}

