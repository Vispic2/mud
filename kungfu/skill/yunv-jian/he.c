// he.c 玉女剑-双剑合璧

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "双剑"ZJBR"合璧"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("双剑合璧只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功不够深厚，不能使用双剑合璧。\n");

	if (me->query_skill("zuoyou-hubo", 1) < 150)
		return notify_fail("你的左右互博之术尚未修炼到家，难以分使这两种剑招。\n");

	if ((int)me->query_skill("yunv-jian", 1) < 120)
		return notify_fail("你的玉女剑法不够娴熟，不能使用双剑合璧。\n");

	if ((int)me->query_skill("quanzhen-jian", 1) < 120)
		return notify_fail("你的全真剑法不够娴熟，不能使用双剑合璧。\n");

	if ((int)me->query("neili", 1) < 400)
		return notify_fail("你现在内力太弱，不能使用双剑合璧。\n");

	if (me->query_skill_mapped("sword") != "yunv-jian")
		return notify_fail("你没有激发玉女剑法，不能使用双剑合璧。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "左手以全真剑法剑意，右手化玉女剑法剑"
	      "招，双剑合璧同时刺出。"NOR"\n";

	ap = me->query_skill("zuoyou-hubo", 1) + me->query_skill("sword", 1) +
	     (me->query_skill("yunv-jian", 1) + me->query_skill("quanzhen-jian", 1)) / 2;
	dp = target->query_skill("parry") * 2 + target->query_skill("zuoyou-hubo", 1);
	me->start_busy(3);
	if (ap / 2 + random(ap) > dp)
	{
		damage = 100 + ap / 2 + random(ap / 2);
		me->add("neili", -250);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 58,
					   HIR "$n" HIR "看到$N" HIR "双剑飞舞，招式中所有"
					   "破绽都为另一剑补去，竟不知如何是好！\n"
					   HIR"一呆之下，$N" HIR "的剑招已经破式而入！$n"
					   HIR "一声惨叫之下，登时受了重创！"NOR"\n");
	} else
	if (target->query_skill("zuoyou-hubo", 1) >= 100)
	{
		msg += CYN "可是$p" CYN "丝毫不乱，左右手分使两种武功招架，将$P"
		       CYN "的攻势全然化解。"NOR"\n";
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，将"
		       "自己的全身上下护得密不透风，令$P" CYN "无计可施。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
