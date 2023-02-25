// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// lei.c 迅雷

#include <ansi.h>
string query_name() { return "迅雷"ZJBR"一击"; }
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int j, z;
        object weapon;

        /*
        if (userp(me) && ! me->query("can_perform/xuantie-jian/lei"))
                return notify_fail("你未得高人指点，不知该如何施展「迅雷」。\n");
        */

        j = me->query_skill("xuantie-sword", 1);
        z = me->query_skill("yunv-xinfa", 1);

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「迅雷」只能在战斗中对对手使用。\n");

       if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("你必须在使用剑时才能使出「迅雷」！\n");
        if (me->query_skill_mapped("parry") != "xuantie-sword" && userp(me))
                return notify_fail("你的基本招架必须是玄铁剑法时才能使出「迅雷」！\n");
/*        || me->query_skill_mapped("sword") != "xuantie-sword"
               || me->query_skill_mapped("parry") != "xuantie-sword")
                return notify_fail("你必须在使用剑时才能使出「迅雷」！\n");
*/

        if(me->query_skill("xuantie-sword", 1) < 160 )
                return notify_fail("你的玄铁剑法还不够娴熟，使不出「迅雷」。\n");

        if(me->query_skill("yunv-xinfa", 1) < 160 )
                return notify_fail("你的怒海狂涛修为不够，使不出「迅雷」。\n");

        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("你的内功等级不够，使不出「迅雷」。\n");

        if( (int)me->query_str() < 32)
                return notify_fail("你的膂力还不够，使不出「迅雷」。\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("你的身法还不够，使不出「迅雷」。\n");

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("你现在内力太弱，使不出「迅雷」。\n");

        if( (int)me->query("neili") < 900 )
                return notify_fail("你现在真气太弱，使不出「迅雷」。\n");

        me->add_temp("apply/defense", z / 6);
        me->add_temp("apply/attack", j / 6);

        msg = BLU "\n$N将手中的"+weapon->name()+"缓缓向$n一压，忽然剑光一闪， 一剑幻为三剑，宛如奔雷掣电攻向$n！\n\n"NOR;
        message_combatd(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        me->add("neili", -500);

        me->add_temp("apply/defense", -z/6);
        me->add_temp("apply/attack", -j/6);

        me->start_busy(3);
        if( !target->is_busy() )
                target->start_busy(1);
        return 1;
}

