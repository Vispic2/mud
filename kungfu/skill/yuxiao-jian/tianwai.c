// tianwai.c 天外清音

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天外"ZJBR"清音"; }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound,lvl;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天外清音」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("bibo-shengong", 1) < 120)
		return notify_fail("你的碧波神功等级不够，不"
				   "能使用「天外清音」！\n");

	skill = me->query_skill("yuxiao-jian", 1);

	if (skill < 100)
		return notify_fail("你的玉箫剑法等级不够, 不会使用「天外清音」！\n");

	if (me->query("neili") < 200)
		return notify_fail("你的真气不够，无法运用「天外清音」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "一声清啸，剑发琴音" + weapon->name() +
	      HIC "闪动不止，剑影如夜幕般扑向$n" HIC "。"NOR"\n";

	ap = me->query_skill("sword") + me->query_skill("chuixiao-jifa");
	dp = target->query_skill("force") + target->query_skill("chuixiao-jifa");
	if (dp < 1) dp = 1;
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -180);
		qi_wound = (int)me->query_skill("sword") +
			   (int)me->query_skill("bibo-shengong", 1);
		qi_wound = qi_wound *2/ 3 + random(qi_wound / 3);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, qi_wound, 66,
					   HIR "$n" HIR "顿时觉得眼前金光乱闪动，双耳嗡嗡"
					   "内鸣，不知那里一阵刺痛如针扎一般！"NOR"\n");
            target->receive_wound("qi", qi_wound / 2, me);
	        message_combatd(msg, me, target);

            lvl=me->query_skill("chuixiao-jifa");
	        target->add_temp("apply/dodge", -lvl/3);
	        target->add_temp("apply/parry", -lvl/3);

		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, weapon, 0);
		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, weapon, 0);
		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, weapon, 0);

	        target->add_temp("apply/dodge", lvl/3);
	        target->add_temp("apply/parry", lvl/3);

		me->start_busy(1 + random(3));
	} else
	{
		me->add("neili", -70);
		msg += HIG "可是$n" HIG "宁心静气，随手挥洒，将$N"
		       HIG "的招数撇在一边。"NOR"\n";
	        message_combatd(msg, me, target);
		me->start_busy(2);
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
