// xiao.c 潇湘夜雨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i, n;
        int skill;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("太玄神功的「潇湘夜雨」绝技只能对战斗中的对手使用。\n");

        skill = me->query_skill("taixuan-gong", 1);

        if (skill < 180)
                return notify_fail("你的太玄神功修为不够，不能使用「潇湘夜雨」！\n");

        if ((int)me->query_skill("force", 1) < 300)
                return notify_fail("你的内功修为还不够，无法使用「潇湘夜雨」！\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，无法运用「潇湘夜雨」！\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你只有装备剑才能施展「潇湘夜雨」！\n");

        n = 4 + skill / 100;

        msg = HIW "$N" HIW "手中" + weapon->name() + HIW "连连晃动，顿时荡起一阵"
              HIW "低沉的有如滚滚雷音的海啸声……\n突然间$N" HIW "手中的" +
              weapon->name() + HIW "如一道闪电划过，瞬间已向$n"
              HIW "唰唰唰连刺" + chinese_number(n) + "剑。\n" NOR;

        message_combatd(msg, me, target);
        count = skill / 6;
        me->add_temp("apply/attack", count);

        for (i = 0; i < n; i++)
        {
                if (! me->is_fighting(target))  break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(2 + random(3));
        me->add_temp("apply/attack", -count);

        return 1;
}

