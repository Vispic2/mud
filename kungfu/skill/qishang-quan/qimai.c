// qimai.c 七脉皆伤

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "七脉"ZJBR"皆伤"; }
string *pfm_type() { return ({ "cuff", }); }

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
		return notify_fail("「七脉皆伤」只能在战斗中对对手使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「七脉皆伤」只能空手使用。\n");
		
	if (me->query("max_neili") < 2000)
		return notify_fail("你的内力修为还不够，无法施展「七脉皆伤」。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query("qi") < 800)
		return notify_fail("你的体力现在不够！\n");

	if ((int)me->query_skill("qishang-quan", 1) < 150)
		return notify_fail("你的七伤拳火候不够，无法使用「七脉皆伤」！\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功修为不够，无法使用「七脉皆伤」！\n");

	if (me->query_skill_prepared("cuff") != "qishang-quan")
		return notify_fail("你现在没有准备使用七伤拳，无法使用「七脉皆伤」！\n");

	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "凝神屏气，口中念着四句似歌似诗的七伤，"
	      "总诀，刹那间，跨上一步，连出几拳！"NOR"\n";
	ap = me->query_skill("cuff") + me->query("con") * 10;
	dp = target->query_skill("force") + target->query("con") * 6;
	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 9;
		msg += HIR "$n" HIR "面对$P" HIR "如此迅疾的拳法，完全"
		       "没有躲闪的余地，“砰，砰，砰”胸口硬接了数拳。"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "打起精神，全力化解这几招凌厉$P" HIC
		       "的攻势。"NOR"\n";
		count = 0;
	}

	message_vision(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -300);
	me->add("qi", -100);   
			       
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(5) < 2 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(1 + random(5));
	me->add_temp("apply/attack", -count);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
