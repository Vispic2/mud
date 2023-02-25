// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "魔气"ZJBR"血杀"; }
int perform(object me, object target)
{
        string msg;
        int ski_value, max_lv;
        int ap, dp, damage;
        int f = 0;
       
        ski_value = random(me->query_skill("mingyu-gong", 1));
        max_lv = me->query_skill("mingyu-gong", 1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『魔气血杀』只能对战斗中的对手使用。\n");
  
        if( me->query_skill("mingyu-gong", 1) < 250 )
                return notify_fail("你的明玉功功力不足。 \n");

        if( me->query_skill("force", 1) < 250 )
                return notify_fail("你的内功不够好。 \n");
        
        if(me->query("neili") < 1000)
                return notify_fail("你的内力不够。\n");
        
        if (me->query_skill_mapped("force") != "mingyu-gong") 
                return notify_fail("你现在没有激发明玉功为内功，难以施展『魔气血杀』。\n"); 
   
        msg = HIY "$N自残己身，以血气转换成杀气。\n
            ……$N身上发出一股强大的杀气……\n
    ■$N身上杀气逐渐地聚集在双手,在双手上形成两团魔气■\n
            $N倏地大喝一声－－魔 气 血 杀－－\n\n" NOR;

        ap = me->query_skill("force"); 
        dp = target->query_skill("force");
        
        if (ap / 2 + random(ap) > dp)  
        {
                msg += HIR BLINK "$N突然喉头一动～～　只见$N口中喷出一道血柱往$n射去～～\n此乃魔气杀之最终杀招 『魔 血 气 杀』\n\n$n遭到前所未有的打击,但$N也受伤不轻。\n" NOR;

                damage = me->query_skill("force");
                
                if (! target->is_busy())
                        target->start_busy( 3 + random(2) );
                target->receive_wound("jing", damage, me);
                /*
                target->receive_wound("qi", damage, me);
                */
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 100 + random(10), msg); 
                me->receive_wound("qi", me->query("qi")* 1 /10);
                me->add("neili",-500); 
                 
                f = 1;
        }
        else if( random(4) > 2 )
        {
                msg += HIR BLINK"$N真气所转换的杀气不够大,对敌人毫无影响。\n" NOR;
                me->receive_wound("qi", me->query("qi")*1/100);
                me->add("neili",-200);  
        }
        else
        {
                msg += HIR BLINK"$n受到强大的杀气伤害，动弹不得。\n" NOR;
                me->receive_wound("qi", me->query("qi")* 5 /100);
                target->receive_damage("qi", (int)me->query_skill("mingyu-gong", 1), me);
                if (! target->is_busy())
                        target->start_busy(3);
                me->add("neili",-300);
        }
                
        message_combatd(msg, me, target);
        if( f )
                COMBAT_D->report_status(target);
        me->start_busy(4 + random(2));
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
