// wuqing.c 美女拳-玉女无情
// by liu 24/07/2001
// Xuanyuan 5/9/2001修改

#include <ansi.h>
string query_name() { return "无情"ZJBR"拳意"; }
inherit F_SSERVER;

int perform(object me, object target)
{
	object ob;
	string msg;
	int damage,jiali,jiajin;

	jiali = (int)me->query("jiali");
	jiajin= (int)me->query("jiali");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("玉女无情只能对战斗中的对手使用。\n");

//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("你必须先放下手中的兵器！\n");
        if( (int)me->query_skill("yunv-xinfa", 1) < 40 )
                return notify_fail("你的玉女心法还未娴熟，不能利用神功伤敌。\n");
        if( (int)me->query_skill("meinv-quan", 1) < 120 )
                return notify_fail("你的美女拳级别不够，不会使用玉女无情。\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("你的内功还未娴熟，不能用玉女无情。\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("你现在内力太弱，不能使用玉女无情。\n");

        if( (int)me->query("jing", 1) < 200 )
                return notify_fail("你现在精力太弱，不能使用玉女无情。\n");

	msg = HIB "\n\n$N真气催动，带得拳意纵横无情！\n"NOR;
        msg += HIY "\n$N右手支颐，左袖轻轻挥出，长叹一声，脸现寂寥之意，无奈中使出杀招。\n\n"NOR;
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("cuff") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
			if(damage > 2300) damage = 2000;
			if(damage < 300) damage = 300;
			me->add("neili", -damage/2 );

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);

		if ( damage < 1000) {
			msg += HIR"只听砰的一声，$n被一拳击中小腹，内血翻涌喷口而出。\n"NOR;
		}else if ( damage < 2000) {
			msg += HIR"只听砰、砰两声，$n左眼发青、右眼发紫，鲜血直流。\n"NOR;
		}else if ( damage < 3000) {
			msg += HIR"只听砰、砰、砰三声响，$n身上被了几个窟窿，鲜血狂喷。\n"NOR;
		}else {
			msg += HIR"只听砰、砰、砰、砰几声巨响，$n被打得骨骼碎裂飞了出去。\n"NOR;
		}
		msg += NOR;
		me->start_busy(2);
  }
  else {
	 msg += HIG"$n灵光一现，纵身跃起，本能的反应帮$n逃过此劫。\n\n"NOR;
	 me->add("neili", -jiali*2 );
	 me->start_busy(2);
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
