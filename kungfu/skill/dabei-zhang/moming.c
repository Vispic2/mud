//moming.c
//by jerry update 2008.12.06

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
    int busy;
    busy=(int)me->query_skill("dabei-zhang") / 40; 
    if (busy > 20 ) busy=20;

        if( !target ) target = offensive_target(me);      

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("悲痛莫明只能对战斗中的对手使用。\n");

 if ( (string)me->query("family/family_name") != "通吃帮") 
return notify_fail("不是通吃帮弟子也想用这武功？\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "已经不能动了！\n");
                
        if( (int)me->query_skill("dabei-zhang", 1) < 100 )
                return notify_fail("你的大悲掌不够娴熟，不会使用「悲痛莫明」。\n");

       msg = HIB "$N脸上露出一丝悲痛的神情，和手念了一声阿弥陀佛,\n"NOR;
       msg += HIB "双手缓缓的推出，看似平常的一招，可是看不出一丝\n"NOR;
       msg += HIW "破绽，次招正是大悲掌最后绝技「悲痛莫明」。\n"NOR;

 if( random(me->query_exp()*6) > target->query_exp() ) {
   msg += HIW "$p企图突破$N的攻击范围，但是被$N的掌风避的毫无退路。\n" NOR;
             target->start_busy( busy );
   me->add("neili", -500);
        } else {
        me->start_busy(3);
           me->add("neili",-300);        
                msg += HIC "$p一眼看出了$N的破绽，躲了过去。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

