
#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "雁荡"ZJBR"护体"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用雁荡心法来提升自己的防御力。\n");

        if( me->query("neili")<100 )
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("yandang-xinfa",1) < 50)
                return notify_fail("你的雁荡心法修为不够。\n");

        if( me->query_temp("shield") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIW "$N" HIW "运起雁荡心法顿时全身紫蕴朦胧，衣袖飘扬！\n" NOR, me);

        me->add_temp("apply/armor", skill);
        me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("shield") )
        {
                me->add_temp("apply/armor", -amount);
                me->delete_temp("shield");
                tell_object(me, "你的雁荡心法运行完"
                            "毕，将内力收回丹田。\n");
        }
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
