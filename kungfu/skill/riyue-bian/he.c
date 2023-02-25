// he.c 「合」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "合字诀"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("日月鞭法「合」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("riyue-bian", 1) < 135)
		return notify_fail("你的日月鞭法不够娴熟，不会使用「合」字诀。\n");

	if (me->query("neili") < 350)
		return notify_fail("你的真气不够，无法使用「合」字诀。\n");

	if (me->query_skill_mapped("whip") != "riyue-bian")
		return notify_fail("你没有激发日月鞭法，无法使用「合」字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "将手中的" + weapon->name() +
	      HIY "一抖，使出日月鞭法「合」字诀，舞起漫天鞭影！"NOR"\n";

	ap = me->query_skill("whip") + me->query_skill("force");
	dp = target->query_skill("force") + target->query_skill("parry");
	attack_time = 4;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIC "结果$p" HIC "被$P" HIC
		       "攻了个措手不及，目接不暇，疲于奔命！"NOR"\n";
		count = ap / 20;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 60);
	} else
	{
		msg += HIC "$n" HIC "见$N" HIC "鞭势恢弘，心下凛然，凝神应付。"NOR"\n";
		count = ap / 40;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 40);	}
		
	message_combatd(msg, me, target);

	if (attack_time > 8)
		attack_time = 8;

	me->add("neili", -attack_time * 10);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(5));
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
