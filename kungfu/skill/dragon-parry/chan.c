#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);string query_name() { return "魔龙"ZJBR"缠身"; }

int perform(object me, object target)
{
        int skill;

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

   if ((int)me->query("neili") < 10000000)
                return notify_fail("你从哪偷学来的魔龙缠身？\n");     if ((int)me->query_skill("dragon-parry", 1) < 120)
                return notify_fail("你的魔龙缠身修为不够。\n");

        if ((int)me->query_temp("dragon-parry"))
                return notify_fail("你已经运起魔龙缠身了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIB "$N" HIB "默念口诀，邪念在心中迸发脸色随即变得阴森苍白，背后惊现三条魔龙虚影缠绕周身！魔龙虚影散发出骇人的气息！"NOR, me);

        me->add_temp("apply/armor", skill / 2);
        me->add_temp("apply/defense", skill / 2);
        me->set_temp("dragon-parry", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("dragon-parry"))
        {
                me->add_temp("apply/armor", -(amount / 2));
                me->add_temp("apply/defense", -(amount / 2));
                me->delete_temp("dragon-parry");
                tell_object(me, "你的魔龙缠身绝招魔龙三影运行完毕，将内力收回丹田。\n");
        }
}
