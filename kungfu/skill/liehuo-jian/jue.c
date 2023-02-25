// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// jue.c 烈火三绝剑

#include <ansi.h>
#include <weapon.h>
inherit F_SSERVER;
 string query_name() { return "烈火"ZJBR"三绝剑"; }
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i;

        if (! me->is_fighting())
                return notify_fail("「"+HIR"烈火三绝剑"NOR+"」只能在战斗中使用。\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query_skill("sword") < 100 ||
                me->query_skill_mapped("sword") != "liehuo-jian")
                return notify_fail("你的「烈火剑」还不到家，无法使用「"+HIR"烈火三绝剑"NOR+"」！\n");

        msg = HIR "$N运起内力，顿时手中兵器火焰逼人，接着向对方连环刺去！\n" NOR;
        message_combatd(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
        me->add("neili", -300);

        for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0)
        {
                me->set_temp("action_msg", "紧跟着");
                if (! weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, ob,weapon, 0);
        } else break;

        me->start_busy(1 + random(2));
        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
