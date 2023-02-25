// lian.c 太极剑法「连」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "连字诀"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("太极剑法「连」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("taiji-jian", 1) < 120)
		return notify_fail("你的太极剑法不够娴熟，不会使用「连」字诀。\n");

	if (me->query("neili") < 250)
		return notify_fail("你的真气不够，无法使用「连」字诀。\n");

	if (me->query_skill_mapped("sword") != "taiji-jian")
		return notify_fail("你没有激发太极剑法，无法使用「连」字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出太极剑法「连」字诀，化出一个个圆圈，把$n"
	      HIY "圈在当中。"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIC "结果$p" HIC "被$P" HIC
		       "攻了个措手不及，连连后退不暇！"NOR"\n";
		count = ap / 10;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 45);
	} else
	{
		msg += HIC "$n" HIC "见$N" HIC "这几剑并无破绽，不敢大意，小心应付。"NOR"\n";
		count = 0;
	}
		
	message_combatd(msg, me, target);

	if (attack_time > 10)
		attack_time = 10;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(attack_time));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
