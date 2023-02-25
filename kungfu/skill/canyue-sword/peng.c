//lian.c 众星捧月
// looo/2019/10/11
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
string query_name() { return "众星"ZJBR"捧月"; }
int perform(object me, object target)

{
        object weapon;
        string msg;

        int i, j, skill;
        skill = (int)(me->query_skill("sword"));
        j = skill/4;
        i = 5 + (int)me->query("tianmo_jieti/times");

       




 if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))

                return notify_fail("「众星捧月」只能在战斗中对对手使用。\n");

        

        if (!objectp(weapon = me->query_temp("weapon")) )
                return notify_fail("你必须使用武器才能使用「众星捧月」！\n");

        if ((string)weapon->query("skill_type") != "sword")
                return notify_fail("你没有装备剑，无法使用「众星捧月」！\n");

        if(me->query_skill_mapped("sword") != "canyue-sword") 
                return notify_fail("你没有激发残月剑法，无法使用「众星捧月」！\n");

        if( (int)me->query_skill("canyue-sword", 1) < 220 )
                return notify_fail("你的残月剑法还不够娴熟，使不出「众星捧月」绝技。\n");

        if( (int)me->query_skill("force") < 300 )
                return notify_fail("你的内功等级还不够，使不出「众星捧月」绝技。\n");

        if( (int)me->query("max_neili") < (me->query_skill("force") + i*j + 2000) )
                return notify_fail("你的内力修为需要进一步提高，才能使出「众星捧月」这种超强绝招。\n");

        if( (int)me->query("neili") < (me->query_skill("force") + i*j) )
                return notify_fail("你现在真气太弱，无法使用「众星捧月」。\n");


        msg = HIM "\n$N" HIM "傲然一笑，手中"+ weapon->name() + HIM "挽出一个完美的满月，周围点点星光灿烂闪烁，俨然一幅「众星捧月」的美景。\n"
              HIM "忽然间星图变幻，万千星光护着一道朦胧华丽的月光向" HIM "$n" HIM "不断电射而去。\n" NOR;

        message_combatd(msg, me, target);

        me->add_temp("apply/str", 7);
        me->add_temp("apply/damage", j);
        me->add_temp("apply/attack", j);

        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                msg = HIB "\n星光万千，明月独尊！！\n" NOR;
                message_vision(msg,me,target);
                COMBAT_D->do_attack(me, target, weapon, 0);
                me->add("neili", -j);
        }

        me->start_busy(4);

        target->start_busy(1);

        me->add_temp("apply/str", -7);
        me->add_temp("apply/damage", -j);
        me->add_temp("apply/attack", -j);

        return 1;
}

