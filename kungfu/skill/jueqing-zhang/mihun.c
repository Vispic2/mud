#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "迷魂"; }
int perform(object me, object target)
{
        string msg;
int busy; 
       busy=(int)me->query("zjb_dj/dj")/2+1;  
    if (busy > 20 ) busy=20; 

	if( !target ) target = offensive_target(me);

        if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
                return notify_fail("你不是移花宫弟子不能使用冥雨神功.\n
                                    绝情掌博大精深, 非移花宫弟子不传, 真不知道你是怎么学会的!\n
                                    要是让两位宫主知道了你可惨了.\n");


	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("迷魂只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "现在已经神志不清了！\n");
		
	if( (int)me->query_skill("jueqing-zhang", 1) < 40 )
		return notify_fail("你的绝情掌法不够娴熟，不会使用「迷魂」。\n");

	msg = HIM "突然周围出现无数花瓣，只见$N站花瓣丛中向$n妩媚一笑。\n";

	me->start_busy(1);
   if( random(me->query_exp()*4) > target->query_exp() ) { 
        msg += HIR " $p神不守舍地看着你，怜香惜玉之心由然而起，竟然忘了自己在战斗之中。\n" NOR;
         target->start_busy( (int)me->query_skill("jueqing-zhang") / 40 );
	} else {
		msg += HIY "$p轻蔑的看了$P一眼，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
