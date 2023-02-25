// powerup.c 混天气功加力
// Modified by Venus Oct.1997

#include <ansi.h>
string query_name() { return "星移功"; }

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
    int skill;

    if( target != me )
        return notify_fail("你只能用星移功来提升自己的战斗力。\n");

    if( (int)me->query_skill("shenyuan-gong",1)<10)
	return notify_fail("你的本门内功不够，不能使用「星移功」。\n");

    if( (int)me->query("neili") < 100  )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("你已经在运功中了。\n");

    skill = me->query_skill("force");
    me->add("neili", -100);
    me->receive_damage("qi", 0);

    message_combatd(
HIG "$N微一凝神，身如飘风，恰似漫天星移!\n" NOR, me);

    me->add_temp("apply/attack", skill/5);
    me->add_temp("apply/dodge", skill/5);
    me->set_temp("powerup", 1);

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

    if( me->is_fighting() ) me->start_busy(3);

    return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/5);
   me->add_temp("apply/dodge", -skill/5);
    me->delete_temp("powerup");
    tell_object(me, "你的星移功运行完毕，将内力收回丹田。\n");
}

