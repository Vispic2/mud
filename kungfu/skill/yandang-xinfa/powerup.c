// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "雁荡"ZJBR"战气"; }
int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用雁荡心法提升自己的战斗力。\n");

        if( me->query("neili")<100 )
                return notify_fail("你的真气不够！");

        if( me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("neili", -100);

        message_combatd(HIM "$N一声长啸，身形急转、飘洒之极！\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill / 3 :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("powerup") )
        {
                me->addn_temp("apply/attack", -amount);
                me->addn_temp("apply/dodge", -amount);
                me->delete_temp("powerup");
                tell_object(me, "你的雁荡心法运行完毕，将内力收回丹田。\n");
        }
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
