#include <ansi.h>

inherit F_SSERVER;
string name() { return "万蛊噬天"; }
string query_name() { return "万蛊"ZJBR"噬天"; }
int perform(object me, object target)
{
        mapping prepare;
        string msg;
        int skill;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("「万蛊噬天」只能对战斗中的对手使用。\n");

        if (me->query_skill_prepared("hand") != "qianzhu-wandushou")
                return notify_fail("你没有准备使用千蛛万毒手，无法施展万蛊噬天。\n");

        skill = me->query_skill("qianzhu-wandushou", 1);

        if (skill < 220)
                return notify_fail("你的千蛛万毒手修为有限，无法施展万蛊噬天。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功火候不够，难以施展万蛊噬天。\n");

        if( me->query("max_neili")<3500 )
                return notify_fail("你的内力修为没有达到那个境界，无法运转内力施展万蛊噬天。\n");

        if( me->query("neili")<500 )
                return notify_fail("你的内力不够，现在无法施展万蛊噬天。\n");

        if( me->query_temp("weapon") )
                return notify_fail("你必须是空手才能施展万蛊噬天。\n");

        msg = RED "\n$N" RED "仰天一声长啸，强催内劲，全身"
              "竟浮现出隐隐碧绿之色。喝道：“万蛊噬天”,双"
              "掌猛\n然拍出，登时幻出漫天碧绿色掌影，毒气弥"
              "漫，笼罩$n" RED "全身！\n\n" NOR;

        message_combatd(msg, me, target);

        me->add("neili", -150);
        target->add_temp("apply/parry", -skill);
        target->add_temp("apply/dodge", -skill);
        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        target->add_temp("apply/parry", skill);
        target->add_temp("apply/dodge", skill);
        me->start_busy(1 + random(2));

        return 1;
}