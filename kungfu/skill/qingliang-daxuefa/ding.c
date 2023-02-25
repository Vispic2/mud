#include <ansi.h>
#include <combat.h>

#define DING "「" HIC "透骨钉" NOR "」"

inherit F_SSERVER;
 
string query_name() { return "透骨钉"; }
string *pfm_type() { return ({ "dagger", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail(DING "只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "dagger")
		return notify_fail("你所使用的武器不对，难以施展" DING "。\n");

	skill = me->query_skill("qingliang-daxuefa", 1);

	if (me->query_skill("force") < 150)
		return notify_fail("你的内功修为不够，难以施展" DING "。\n");

	if (me->query("neili") < 500)
		return notify_fail("你现在的真气不足，难以施展" DING "。\n");

	if (skill < 100)
		return notify_fail("你清凉打穴法修为有限，难以施展" DING "。\n");

	if (me->query_skill_mapped("dagger") != "qingliang-daxuefa")
		return notify_fail("你没有激发清凉打穴法，难以施展" DING "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "侧身将手中" + weapon->name() + HIC "斜刺而出，一式「"
	      HIR "透骨钉" NOR + HIC "」卷带着呼呼风声，将$n" HIC "包围紧裹。"NOR"\n";
 
	ap = me->query_skill("dagger");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -200);
		damage = 100 + ap / 3 + random(ap / 3);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "顿时只听得“噗嗤”一声，$n" HIR
					   "胸口被$N" HIR "这一招刺中，溅出一柱鲜血。"NOR"\n");
		me->start_busy(1);
		if (ap / 3 + random(ap) > dp && ! target->is_busy())
			target->start_busy(ap / 25 + 1);
	} else
	{
		msg += CYN "可是$p" CYN "的看破了$P" CYN
		       "的招式，巧妙的一一拆解，没露半点"
		       "破绽！"NOR"\n";
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
