#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, ap, dp, damage;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("langzi-sword",1);
    if( !(me->is_fighting() ))
        return notify_fail("「下字决」只能对战斗中的对手使用。\n");
          
    if( (int)me->query("neili") < 1200 )
        return notify_fail("你的真气不够！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");  
    if (!objectp(weapon2 = target->query_temp("weapon")))
       return notify_fail("对方没有兵刃，你不用担心。\n");

    if( skill < 200)
        return notify_fail("你的浪子三招等级不够, 不能使用「下字决」！\n"); 
    if( me->query("neili") < 500 )
        return notify_fail("你的内力不够，无法运用「下字决」！\n"); 
msg = HIG "$N一发狠,使出浪子三招之「"HIW"下字决"HIG"」, 手中"+weapon2->name()+HIG"，刺向$n的虎口。\n";
    message_vision(msg, me, target);
 
    damage = 10 + random(skill / 2);
ap = skill+me->query_skill("sword",1);
    dp = target->query_skill("unarmed",1);
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
        msg = "$n顿时觉得眼前一花，手腕一麻，手中";
        msg += weapon2->name();
        msg += "脱手而出！\n" NOR;
            me->add("neili",-1030);
        target->receive_damage("qi", damage);
        target->start_busy(2);
        if(weapon2->query_xy())
        {
        	weapon2->move(target);
        }
        else weapon2->move(environment(me));
    }
    else
    {
        if(userp(me))
            me->add("neili",-1030);
        msg = "可是$n看破了$N的剑法，立刻将手中" + weapon2->name() + "舞得风雨不透，使$N的「下字决」没有起到作用。\n"NOR;
   me->start_busy(3);
    }
      message_vision(msg, me, target);
    return 1;
}


