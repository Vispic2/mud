#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "随风"ZJBR"而舞"; }
int perform(object me, object target)
{   
        string msg;
        object env = environment(me); 
        mapping *obb = env->query("exits"); 

        if (userp(me) && ! me->query("can_perform/qiulin-shiye/wu")) 
                return notify_fail("你还没有受过高人指点，无法施展「随风而舞」。\n"); 
                    
        if (! target) target = offensive_target(me);
        
        if (! target || ! target->is_character() ||
            ! me->is_fighting(target))
                return notify_fail("你只能在战斗中使用「随风而舞」。\n");
                
        if ((int)me->query_skill("qiulin-shiye", 1) <  90)
                return notify_fail("你目前功力还使不出「随风而舞」。\n");
                
        if ((int)me->query("neili") < 500)
                return notify_fail("你的内力不够。\n");
                
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
                
        me->add("neili", -200);
        msg = HIC"$N突然轻嘘一声，身形一展，向随风飘舞而上，身形越来越小。\n"NOR;
        me->start_busy(1);
    
        if (random(me->query("combat_exp")) >
            (int)target->query("combat_exp") / 4) 
        {
                target->start_busy(3 + random(3));
                me->receive_damage("qi", 200);
                me->receive_damage("jing",80);
                if (sizeof(obb) > 0) me->move(obb[0]);
                msg += RED"只见$n只看的目瞪口呆,一时手忙脚乱起来，不知如何是好。\n"NOR;
        } else 
        {
                msg += HIC "可是$p却暴身南而起，大喝一声：“那里走！”，拦在你的前面，$P这招没有得逞。\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
