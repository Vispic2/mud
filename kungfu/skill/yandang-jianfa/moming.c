// 剑动莫名

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "剑动"ZJBR"莫名"; }
string name() { return "剑动莫名"; }
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i,j,times,n;

        i = me->query_skill("yandang-jianfa", 1)/60;
        j = me->query_skill("sword")/60;

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("你只能对战斗中的对手使用绝招「剑动莫名」。\n");
        if( !objectp(weapon=me->query_temp("weapon")))return notify_fail("你必须使用武器才能使用「剑动莫名」！\n");
        if ( (int)me->query_str() < 35 ) return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
        if ( (int)me->query_skill("sword",1) < 200 ) return notify_fail("你的基本剑法的火候还不到家, 不能使用这一绝技 !\n");
        if ( (int)me->query_skill("yandang-jianfa", 1) < 200 ) return notify_fail("你的雁荡剑法的火候还不到家, 不能使用这一绝技 !\n");
        if( me->query("neili")<1000)return notify_fail("你的真气不够！\n");
        if( me->query("max_neili")<1000)return notify_fail("你的内力修为不够！\n");
        if ( me->is_busy() ) return notify_fail("你上一个动作还没有完成！\n");

        msg = MAG "\n$N脸现幽思,往事如潮涌上心头,手中剑望空斜指一股怨气从剑尖散发弥漫开来！\n" NOR;
        message_combatd(msg, me,target);
        me->add_temp("apply/damage", i);
        me->add_temp("apply/attack", j);
		times = 12;
        for ( n=0; n<times; n++ )
        {
                if ( !target ) break;
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"),1);
        }
        me->add_temp("apply/damage", -i);
        me->add_temp("apply/attack", -j);
        me->add("neili", -200);
        me->start_busy(random(2)+2);
        if ( target && !target->is_busy() ) target->start_busy(random(2)+1);
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
