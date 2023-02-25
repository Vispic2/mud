// powerup.c 
// by dream

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        
        if (target != me)
                return notify_fail("你只能用冰心决来提升自己的战斗力。\n");
                
        if ((int)me->query("neili") < 300)
                return notify_fail("你的内力不够。\n");
                
        if ((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -200);
        me->receive_damage("qi", 0);
        
        message_combatd(
                HIW "$N大吼一声：“心若冰心，天塌不惊”。\n" NOR, me);
                
        me->add_temp("apply/attack", skill * 2 / 5);
        me->add_temp("apply/defense", skill * 2 / 5);
        me->set_temp("powerup", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", 
                           me, skill * 2 / 5 :), skill);
                           
        if (me->is_fighting()) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", - amount);
                me->add_temp("apply/defense", - amount);
                me->delete_temp("powerup");
                tell_object(me, "你的冰心决运行完毕，将内力收回丹田。\n");
        }
}

