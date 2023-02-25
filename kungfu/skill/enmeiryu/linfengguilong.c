// ning@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "落日"; }
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        extra = me->query_skill("enmeiryu");
        if ( extra < 60) return notify_fail("你的陆奥圆明流拳术还不够纯熟！\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［落日］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("enmeiryu") / 30;
  if (extra>200) extra=200;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/unarmed_damage", extra);
        //msg = HIY  "$N使出柳家拳法中的精髓［麟凤龟龙］，双拳舞出四种异兽向$n扑去！" NOR;
	msg = HIR  "$N仰天发出一声长笑，使出陆奥圆明流拳术中的［落日］，\n" NOR;
	msg += HIR   "就似灿烂无比的夕阳，顿时间天地亦为之变色！\n" NOR;
	message_vision(msg,me,target);
        msg = HIY  "麒麟破日！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "凤凰穿日！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "神龟灭日！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天龙破日！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/unarmed_damage", -extra);
        me->add("neili",-100);
        me->start_busy(2);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
