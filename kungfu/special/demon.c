// This program is a part of NITAN MudLIB
// demon.c 万魔附体
// Created by Lonely 04/05/2009

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIG "万魔附体" NOR; }

void remove_effect(object me, int amount);

int perform(object me, string skill)
{
        int n;

        if (me->query_temp("special_skill/demon"))
                return notify_fail("你万魔附体之术已在施展中了。\n");

        message_vision(HIG "$N" HIG "施展出万魔附体之术，刹那间全身真气迸发，犹如蚩尤再现，威猛无比！\n" NOR, me);

        n = me->query_skill("force")+(me->query("tianfu/demon")*100);
        if (n < 100) 
        n = 100;
        
        me->add_temp("apply/armor", n * 3);         
        me->add_temp("apply/reduce_damage", 30);
        me->set_temp("special_skill/demon", 1); 
 
        me->start_call_out((: call_other, __FILE__, "remove_effect", me, n * 3 :), n/10);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("special_skill/demon"))
        {
                me->add_temp("apply/armor", -amount);
                me->add_temp("apply/reduce_damage", -30);
                me->delete_temp("special_skill/demon");
                tell_object(me, "你万魔附体之术已施展完毕。\n");
        }
        
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
