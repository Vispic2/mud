// lian.c 天魔缭乱法「天魔缭乱」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return HIR"天魔"ZJBR"缭乱"NOR; }
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
		return notify_fail("天魔缭乱法「天魔缭乱」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("tianmo-liaoluan", 1) < 180)
		return notify_fail("你的天魔缭乱法不够娴熟，不会使用「天魔缭乱」字诀。\n");

	if (me->query("neili") < 250)
		return notify_fail("你的真气不够，无法使用「天魔缭乱」字诀。\n");

	if (me->query_skill_mapped("sword") != "tianmo-liaoluan")
		return notify_fail("你没有激发天魔缭乱法，无法使用「天魔缭乱」字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出天魔缭乱法「天魔缭乱」字诀，化出一个个圆圈，把$n"
	      HIY "圈在当中。"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	attack_time = 10;
	if (ap / 2 + random(ap * 2 * 2) > dp)
	{
		msg += HIC "结果$p" HIC "被$P" HIC
		       "攻了个措手不及，天魔缭乱天魔缭乱后退不暇！"NOR"\n";
		count = ap / 5;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 30);
	} else
	{
	msg += HIC "结果$p" HIC "被$P" HIC
		       "攻了个措手不及，天魔缭乱天魔缭乱后退不暇！"NOR"\n";
		count = ap / 5;
		me->add_temp("apply/attack", count);
		attack_time += random(ap / 30);
	}
		
	message_combatd(msg, me, target);

	if (attack_time > 10)
		attack_time = 20;

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
