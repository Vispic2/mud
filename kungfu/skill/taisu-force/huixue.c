// zu.c  by sinb

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "太素"ZJBR"回血"; }
int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用太素心经恢复自己的气血。\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("你的真气不够！\n");

        if (me->query_condition("taisu_hq"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("taisu-force", 1);

        me->add("neili", -1500);
        me->add("jing", -1500);

        message_combatd(HIC "$N" HIC "运起「回血」劲道，"
                        "眼中闪过一片青芒，随即恢复正常\n" NOR, me);


        me->apply_condition("taisu_hq", skill / 100);
        if (me->is_fighting()) me->start_busy(5);

        return 1;
}

