// liuxing.c 流星闪烁

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "流星闪烁"; }

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i;
        int skill;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("「流星闪烁」只能对战斗中的对手使用。\n");

        skill = me->query_skill("liushui-bian", 1);

        if (userp(me) && skill < 50)
                return notify_fail("你的流水鞭法修为不够，现在不能使用「流星闪烁」！\n");

        if (me->query("neili") < 100)
                return notify_fail("你的真气不够，无法运用「流星闪烁」！\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对！\n");

        msg = HIW "$N" HIW "招式突然加快，急挥手中的" + weapon->name() +
              HIW "，顿时如烟花绽放般卷出无数鞭花，流星骤雨般向$n"
              HIW "卷出。\n" NOR;

        message_combatd(msg, me, target);
        count = skill / 3;
        me->add_temp("apply/attack", count);

        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))  break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(2 + random(3));
        me->add_temp("apply/attack", -count);

        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
