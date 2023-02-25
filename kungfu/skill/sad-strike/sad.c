// sad.c 黯然消魂

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "黯然"ZJBR"销魂"; }
string *pfm_type() { return ({ "unarmed", }); }

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
		return notify_fail("「黯然销魂」只能在战斗中对对手使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然销魂」只能空手使用。\n");
		
	if (me->query("static/marry") > 1)
		return notify_fail("你感情早已不纯，哪里还能领略到那种黯然销魂的感觉？\n");

	if (! me->query("couple/id"))
		return notify_fail("你老婆都没有，还黯然什么？\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("sad-strike", 1) < 180)
		return notify_fail("你的黯然销魂掌不足180级，无法施展「黯然销魂」。\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功有效等级不足300级，无法施展「黯然销魂」。\n");

	if (sizeof(me->query_skill_prepare()) &&
	    me->query_skill_prepared("unarmed") != "sad-strike")
		return notify_fail("你现在没有准备使用黯然销魂掌，无法施展「黯然销魂」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIM "$N" HIM "一声长叹，心如止水，黯然神伤，于不经意中随"
	      "手使出了" HIR "『黯然销魂』" HIM "！"NOR"\n";

	ap = me->query_skill("unarmed") + me->query("con") * 10;
	dp = target->query_skill("parry") + target->query("dex") * 10;
	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 12;
		msg += HIY "$n" HIY "见$P" HIY "这一招变化莫测，奇幻无"
		       "方，不由大吃一惊，慌乱中破绽迭出。"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "不敢小觑$P" HIC
		       "的来招，腾挪躲闪，小心招架。"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -200);
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(3) == 0 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(1 + random(6));
	me->add_temp("apply/attack", -count);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
