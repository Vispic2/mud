// dongqu.c 大江东去

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "大江"ZJBR"东去"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	int ap, dp, pp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("大江东去只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 100)
		return notify_fail("你的玄铁剑法不够娴熟，不能使用大江东去。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，不能使用大江东去。\n");

	if ((int)me->query("neili") < 300 )
		return notify_fail("你现在内力太弱，不能使用大江东去。\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("你没有激发玄铁剑法，不能施展大江东去。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "一声猛喝，一股气劲从身后澎湃迸发，手中" +
	      weapon->name() + HIW "凌空挥卷而出，疾如电闪，势若"
	      "\n雷霆，剑光幻作万道长虹一齐贯向$n" HIW "！"NOR"\n";

	me->start_busy(2);
	ap = me->query_skill("sword") + (weapon->query_weight() - 10000) / 100;
	pp = target->query_skill("force") + target->query_str() * 5;
	dp = target->query_skill("force") + target->query_dex() * 5;
	if (me->query("character") == "光明磊落")
		ap += ap / 10;
	if (ap / 2 + random(ap) < pp)
	{
		msg += CYN "然而$p" CYN "内功当真深厚，奋力接下此剑，竟然不落半点下风。"NOR"\n";
		me->add("neili", -100);
	} else
	if (ap / 2 + random(ap) < dp)
	{
		msg += CYN "$p" CYN "见$P" CYN "此剑势不可挡，急忙提气跃开。"NOR"\n";
	} else
	{
		damage = ap / 2 + random(ap);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "$p" HIR "不及闪避，只得奋力招架，却被$P" HIR
					   "这一剑震的飞起，口中鲜血狂吐不止！"NOR"\n");
	}

	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
