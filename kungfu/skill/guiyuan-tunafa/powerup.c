// powerup.c 玄天无极加力
// Modified by Venus Oct.1997

#include <ansi.h>
string query_name() { return "归元"ZJBR"战气"; }
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
    int skill;

    if( target != me )
        return notify_fail("你只能用归元吐纳法来提升自己的战斗力。\n");

    if( (int)me->query("neili") < 100  )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("你已经在运功中了。\n");

    skill = me->query_skill("force");
    me->add("neili", -100);
    me->receive_damage("qi", 0);

    message_combatd(
HIC "$N微一凝神，运起归元吐纳法，全身骨节发出一阵爆豆般的声响。\n" NOR, me);

    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/4);
    me->set_temp("powerup", 1);

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

    if( me->is_fighting() ) me->start_busy(3);

    return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/3);
   me->add_temp("apply/dodge", -skill/4);
    me->delete_temp("powerup");
    tell_object(me, "你的归元吐纳法运行完毕，将内力收回丹田。\n");
}

