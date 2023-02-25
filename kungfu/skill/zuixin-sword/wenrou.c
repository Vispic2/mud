#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int attackp, defendp;


        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("最温柔的一剑只能对战斗中的对手使用。\n");

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸掉谁的内力？\n");
           
        if( me->query_temp("sucked") )
                return notify_fail("你刚刚运过最温柔的一剑!\n");

//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("你必须空手才能施用化功大法化人内力！\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword")
                  return notify_fail("「温柔一剑」开始时必须有剑在手！\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 150 )
                return notify_fail("你的北冥神功不够娴熟，不能吸对方的内力！n");

        

        if( (int)me->query("neili",1) < 500 )
                return notify_fail("你的内力不够，不能使用化功大法。\n");

       

          message_vision( HIR "$N突然眼神变得极其温柔，手中宝剑轻轻的往前一送，剑刃向$n的不知什么部位飘去！\n" NOR,
                me, target );

        attackp = me->query_skill("force", 1) + me->query_skill("beiming-shengong", 1) + me->query_skill("lingbo-weibu", 1) / 2;
        defendp = target->query_skill("force") + target->query_skill("dodge");

        me->set_temp("sucked", 1);

        if( attackp / 2 + random(attackp) > defendp || !living(target) )
        {
                  message_vision(HIY "$p一时难以闪避，只得慌乱用双手将剑刃一夹,双手登时如被粘住一般的紧贴在剑刃上。。\n" NOR, me, target );
                tell_object(me, HIB "你见" + target->name() + "如此，当即运起北冥神功，将对方内力尽数吸来。。...\n" NOR);
                 message_vision(HIY "$p似乎想说什么，可是全身无力，现出极其痛苦的表情，双手却又抽脱不开。”\n" NOR, me, target );
                tell_object(
                        target, HIB "但觉手掌中微微一凉，内力源源不绝的顺着对方$w不住往外涌去。，\n" + 
                        "登时心中一惊，全然提不起真气收力，只得任对方吸取体内内力。。。\n" 
                        NOR);

                target->add("neili", -1*((int)me->query_skill("beiming-shengong", 1) + target->query("jiali")) );
                if ( target->query("neili") <1 ) target->set("neili",0);
//                me->add("neili", (int)me->query_skill("beiming-shengong", 1) + target->query("jiali") );
                me->add("neili", 100);

                if( target->query("combat_exp") >= me->query("combat_exp") )
                {
                        if( (int)me->query("potential") - (int)me->query("learned_points") < 110 )
                        me->add("potential", 7);
                        me->add("combat_exp", 20);
                }

                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -200);

                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_vision(HIY "可是$p看破了$P的企图，迅速地避开了这一剑。\n" NOR, me, target);
                me->start_busy(3);
                call_out("del_sucked", 17, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}


