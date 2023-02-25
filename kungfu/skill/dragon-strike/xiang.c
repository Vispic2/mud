// xiang.c 龙翔九天

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "龙翔"ZJBR"九天"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「龙翔九天」只能在战斗中对对手使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「龙翔九天」只能空手使用。\n");
		
	if (me->query("max_neili") < 2000)
		return notify_fail("你的内力修为还不够，无法施展「龙翔九天」。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query("qi") < 800)
		return notify_fail("你的体力现在不够！\n");

	if ((int)me->query_skill("dragon-strike", 1) < 150)
		return notify_fail("你的降龙十八掌火候不够，无法使用「龙翔九天」！\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功修为不够，无法使用「龙翔九天」！\n");

	if (me->query_skill_prepared("strike") != "dragon-strike")
		return notify_fail("你现在没有准备使用降龙十八掌，无法使用「龙翔九天」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "深吸一口气，跨前一步，双掌猛然翻滚，缤纷而出，宛如一条神龙攀蜒于九天之上！"NOR"\n";
	ap = me->query_skill("strike") + me->query("str") * 10;
	dp = target->query_skill("parry") + target->query("dex") * 6;
	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 9;
		msg += HIR "$n" HIR "面对$P" HIR "这排山倒海攻势，完全无法抵挡，唯有退后。"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "凝神应战，竭尽所能化解$P" HIC "这几掌。"NOR"\n";
		count = 0;
	}

	message_vision(msg, me, target);
	me->add_temp("apply/attack", count*2);

	me->add("neili", -300);
	me->add("qi", -100);    // Why I don't use receive_damage ?
				// Becuase now I was use it as a cost
				
				
	if(!me->query("dragon-strike_zj")){	
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(5) < 2 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}
	}else{
	for (i = 0; i < 6+random(5); i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(5) < 2 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}
	
	}
	target->interrupt_me(target, 1);

	me->start_busy(1 + random(5));
	me->add_temp("apply/attack", -count*2);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
