// This program is a part of NITAN MudLIB
// huaxue.c

#include <ansi.h>

#define HUAXUE "「" HIR "神刀化血" NOR "」"
string query_name() { return "神刀"ZJBR"化血"; }
inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        object weapon;
        string msg;
        int skill;

        if ((int)me->query_temp("huaxue"))
                return notify_fail(HIG "你已经运起" + HUAXUE + HIG "了。\n");

        /*
        if (! me->is_fighting())
                return notify_fail(HUAXUE + "只能在战斗中使用。\n");
        */

        if ((int)me->query("neili") < 200)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的蚩尤狂战决修为不够，不能使用" + HUAXUE + "！\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon) || weapon->query("skill_type") != "blade")
                return notify_fail("你没有装备刀，难以施展" + HUAXUE + "。\n");

        msg = HIR "$N" HIR "凝神闭目，右手持刀，左手顺着" + weapon->name() +
              HIR "刀刃一抹，鲜血顿时将" + weapon->name() + HIR "染红。待到$N"
              HIR "双目睁开，顿时杀气冲天！\n" NOR;

        skill = (int)me->query_skill("moshen-xinfa", 1);

        me->add("neili", -150);
        me->add_temp("apply/damage", skill*5);
        me->add_temp("apply/unarmed_damage", skill*5);
        me->add_temp("apply/blade", skill);
        me->add_temp("apply/blade_damage",skill*5);
        me->set_temp("huaxue", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                           me, skill :), skill);

        message_combatd(msg, me);
        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("huaxue"))
        {
                me->add_temp("apply/damage", -amount*5);
                me->add_temp("apply/unarmed_damage", -amount*5);
                me->add_temp("apply/blade", -amount);
                me->delete_temp("huaxue");
                tell_object(me, "你的" + HUAXUE + "运行完毕，将内力收回丹田。\n");
        }
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
