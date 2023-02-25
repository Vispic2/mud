// jiedu.c 解五毒神掌
// By Kayin @ CuteRabbit Studio 99-4-16 15:19 new
#include <ansi.h>
string query_name() { return "解毒"; }

inherit F_SSERVER;
int exert(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("你要给谁解毒。\n");

        if( (int)me->query_skill("shenlong-xinfa", 1) < 270 )
                return notify_fail("你的神龙心法不够娴熟，不能解毒。\n");

if (!userp(target))
	      if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能解毒。\n");
        if( me->is_fighting() )
        return notify_fail("你正忙着呢！\n");
        if( me->is_busy() )
        return notify_fail("你正忙着呢！\n");
        me->add("neili", -300);
me->start_busy(2);
        target->apply_condition("lianhua_poison", 99);
  ("xx_poison", 50);
        target->apply_condition("zhua_poison", 99);
        target->apply_condition("fire_poison", 99);
        target->apply_condition("xuanming_poison", 99);
        target->apply_condition("snake_poison", 99);
        msg = HIW "$N使出神龙心法“解毒”的手法为$n推拿。接着给$n服下一粒“解药”\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
