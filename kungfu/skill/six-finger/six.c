// six.c 六脉剑气

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "六脉"ZJBR"剑气"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target)
{
	mapping prepare;
	string msg;
	int skill;
	int delta;
	int ap, dp;
	int i,lj=0;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「六脉剑气」只能对战斗中的对手使用。\n");

	if (me->query_skill_mapped("finger") != "six-finger")
		return notify_fail("你没有激发六脉神剑，无法施展「六脉剑气」。\n");

	if (me->query_skill_prepared("finger") != "six-finger")
		return notify_fail("你没有准备使用六脉神剑，无法施展「六脉剑气」。\n");

	skill = me->query_skill("six-finger", 1);

	if (skill < 200)
		return notify_fail("你的六脉神剑修为有限，无法使用「六脉剑气」！\n");

	if (me->query_skill("force") < 360)
		return notify_fail("你的内功火候不够，难以施展「六脉剑气」！\n");

	if (me->query("max_neili") < 7500)
		return notify_fail("你的内力修为没有达到那个境界，无法运转内力形成「六脉剑气」！\n");

	if (me->query("neili") < 500)
		return notify_fail("你的真气不够，现在无法施展「六脉剑气」！\n");

	if (me->query_temp("weapon"))
		return notify_fail("你必须是空手才能施展「六脉剑气」！\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "摊开双手，手指连弹，霎时间空气炙热，几"
	      "欲沸腾，六道剑气分自六穴，一起杀向$n" HIY "！"NOR"\n";

	ap = me->query_skill("finger");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "$n" HIR "见此剑气纵横，微一愣神，不禁心萌退意。"NOR"\n";
		delta = -skill / 5;
	} else
		delta = 0;

	message_combatd(msg, me, target);

	me->add("neili", -300);
	target->add_temp("apply/parry", delta);
	target->add_temp("apply/dodge", delta);


	
	if(me->query("six-finger_zj")){
	for (i = 0; i < 8; i++)
	{
	lj+=1;
    if(lj>5)  
    lj=random(6);
    
		if (! me->is_fighting(target))
			break;
		if (random(3) == 1 && ! target->is_busy())
			target->start_busy(1);
		me->set_temp("six-action",lj);
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	}else{
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(3) == 1 && ! target->is_busy())
			target->start_busy(1);
		me->set_temp("six-action",i);
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	
	}



	target->add_temp("apply/parry", -delta);
	target->add_temp("apply/dodge", -delta);
	
	target->interrupt_me(target, 1);
	
	me->delete_temp("six-action");
	if(me->query("six-finger_zj")){
	me->start_busy(1 + random(3));
    }else{
    me->start_busy(1 + random(5));
    }
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
