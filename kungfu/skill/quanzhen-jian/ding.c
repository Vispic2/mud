// ding.c 全真剑 定阳针

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "定阳针"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("定阳针只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("quanzhen-jian", 1) < 50)
		return notify_fail("你的全真剑法不够娴熟，不能使用定阳针。\n");

	if ((int)me->query_skill("force") < 80)
		return notify_fail("你的内功火候不够，不能使用定阳针。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你现在内力太弱，不能使用定阳针。\n");

	if (me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("你没有激发全真剑法，不能使用定阳针。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "脚下左弓右箭，神气完足如雷霆"
	      "五岳，一式「定阳针」斜斜刺出。"NOR"\n";

	me->start_busy(2);
	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		damage = (int)me->query_skill("quanzhen-jian", 1) +
			 (int)me->query_skill("force", 1) +
			 (int)me->query_skill("xiantian-gong", 1);

		damage = damage / 3 + random(damage / 3);

		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
					   HIR "$n" HIR "看到$N" HIR "这气拔千钧的一击，竟不"
					   "知如何招架，登时受了重创！"NOR"\n");
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，斜跃避开。"NOR"\n";
		me->add("neili", -30);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
