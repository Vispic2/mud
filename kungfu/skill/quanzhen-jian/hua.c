// hua.c 全真剑 一气化三清

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "化三清"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;

	if (userp(me) && ! me->query("can_perform/quanzhen-jian/hua"))
		return notify_fail("你还不会使用一气化三清。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("一气化三清只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("quanzhen-jian", 1) < 100)
		return notify_fail("你的全真剑法不够娴熟，不能使用一气化三清。\n");

	if ((int)me->query_skill("xiantian-gong", 1) < 100)
		return notify_fail("你的先天功不够娴熟，无法领会一气化三清的奥秘。\n");

	if ((int)me->query("neili", 1) < 500)
		return notify_fail("你现在真气不够，不能使用一气化三清。\n");

	if (me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("你没有激发全真剑法，不能使用一气化三清。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "站稳马步，将内力全然运到剑上，一声长喝，" +
	      weapon->name() + HIC "上" HIM "紫芒" HIC "闪耀，化作数"
	      "道剑气逼向$n。"NOR"\n";

	ap = me->query_skill("xiantian-gong", 1) + me->query_skill("sword");
	dp = target->query_skill("force") + target->query_skill("parry", 1) * 2 / 3;
	if (dp < 1) dp = 1;
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(3);
		if (! target->is_busy())
			target->start_busy(1);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, ap / 2 + random(ap / 2), 66,
					   HIR "$n" HIR "一声惨叫，剑气及身，身上"
					   "顿时冒出数道血柱！"NOR"\n");
		message_combatd(msg, me, target);
		if (ap / 3 + random(ap) > dp)
		{
			if (! target->is_busy())
				target->start_busy(1);
			count = me->query_skill("xiantian-gong", 1) / 5;
			me->add_temp("apply/attack", count);
			message_combatd(HIC "$N" HIC "看到$n" HIC
					"在这一击之下破绽迭出，身"
					"形前跃，“唰唰唰”就是三剑！"NOR"\n",
					me, target);
			COMBAT_D->do_attack(me, target, weapon);
			COMBAT_D->do_attack(me, target, weapon);
			COMBAT_D->do_attack(me, target, weapon);
			me->add_temp("apply/attack", -count);
		}
	} else
	{
		me->start_busy(2);
		msg += CYN "可是$n" CYN "看破了$N" CYN "的企图，斜跃避开。"NOR"\n";
		message_combatd(msg, me, target);
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
