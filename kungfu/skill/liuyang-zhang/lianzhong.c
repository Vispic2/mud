// zhong.c 种生死符

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
string query_name() { return "连种"ZJBR"生死符"; }
inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
		int i;
	string msg;
	 int extra;
        extra = me->query_skill("liuyang-zhang",1);
	if( !target ) target = offensive_target(me);

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「连种生死符」只能在战斗中使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");

	if( !target || !target->is_character() )
		return notify_fail("连种生死符只能种在对手身上。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 200 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 200 ))
		return notify_fail("你的本门内功不够娴熟，不能连种生死符。\n");

	if (me->query("neili")<200)
		return notify_fail("你真气不足。\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
		return notify_fail("你的天山六阳掌不够娴熟，不能连种生死符。\n");


        me->add_temp("apply/str", extra/4);
        me->add_temp("apply/attack", 80);
	me->add_temp("apply/damage", 380);
	msg = BLU "$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n。\n";
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW  "$N左指一弹，"HIG"第一道生死符"HIW"向$n左边打来！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N右指一弹，"HIG"第二道生死符"HIB"向$n右边打来! " NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$N凌空跃起,"HIG"第三道生死符"CYN"向$n上面打来!" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->start_busy(2);

	if ( me->query("family/family_name")=="灵鹫宫"  && me->query_skill("liuyang-zhang", 1) >= 500 && me->query("bahuangok"))
	{
		msg = HIG " 结果$n被$N攻了个正着！身上中了几道生死符\n" NOR;
		target->apply_condition("ss_poison", (me->query_skill("liuyang-zhang",1)/50) + 30 + target->query_condition("ss_poison"));
		if (random(2)==0)
		{
			msg = HIG " $N分掌为阳，演化“生”“死”----------生！！！\n" NOR;
			target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 30 + target->query_condition("ss_poison"));
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   //二分之一几率只连一招，给敌人生机，但是自己无忙乱。
			message_combatd(msg, me, target);
	    } else
		{
			msg += "$N合掌为阴，演化“生”“死”----------死！！！\n" NOR;
			target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 30 + target->query_condition("ss_poison"));
			for(i=0;i<extra/100;i++)  //每100级加一连
			{
				msg = RED "$N八荒六合，唯我独尊 ！\n" NOR;
				COMBAT_D->do_attack(me, target, 0, i);   //不论用何武器，都变成加强空手招式

			}
			me->start_busy(2);  //另外二分之一几率绝灭敌人生机，强力连，自己忙乱2 。
			message_combatd(msg, me, target);
		}
	}
	me->add_temp("apply/str", -extra/4);
	me->add_temp("apply/damage", -380);
	me->add_temp("apply/attack", -80);
 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
 {
		msg = HIG " 结果$p被$P攻了个正着！身上中了几道生死符\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",155 + random( (int)me->query_skill("liuyang-zhang",1)));
		target->receive_wound("jing", 10 + random(50));
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 30 +
		target->query_condition("ss_poison"));
		me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
        me->add("neili",-200);
// if target is not busy, then busy him (by xbd)
	if (!target->is_busy()) target->start_busy(2);
//	if( !target->is_killing(me) ) target->kill_ob(me);
//	if(!target->is_fighting(me)) target->kill_ob(me);

	return 1;
}
