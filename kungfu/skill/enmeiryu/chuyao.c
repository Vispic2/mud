// ning@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "荡魔"ZJBR"除妖"; }
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
        extra = me->query_skill("enmeiryu");
        if ( extra < 50) return notify_fail("你的陆奥圆明流拳术还不够纯熟！\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
		if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［荡魔除妖］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("enmeiryu") / 30;
if (extra>200) extra=200;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/unarmed_damage", extra);
        msg = HIY "$N运力于掌，使出绝技「荡魔除妖」，飞身疾进，双掌铺天盖地向$n的天灵盖拍去！" NOR;
	message_vision(msg,me,target);
        msg = HIY  "引趣众生！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "歌舞阎罗！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "浮游血海！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "驱鬼御魔！" NOR;
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
