#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "火麟"ZJBR"蚀月"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	int ap, dp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「火麒蚀月」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("ranmu-daofa", 1) < 180)
		return notify_fail("你的燃木刀法不够娴熟，不能使用火麒蚀月。\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("你的内功火候不够，不能使用火麒蚀月。\n");

	if ((int)me->query("max_neili") < 3000 )
		return notify_fail("你的内力修为太弱，不能使用火麒蚀月。\n");

	if ((int)me->query("neili") < 600 )
		return notify_fail("你现在内力太弱，不能使用火麒蚀月。\n");

	if (me->query_skill_mapped("blade") != "ranmu-daofa")
		return notify_fail("你没有激发燃木刀法，不能施展火麒蚀月。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "只见$N" HIR "手中" + weapon->name() + HIR "一抖，刀身登时腾起"
			"滔天烈焰，如浴火麒麟一般席卷$n" HIR "全身！"NOR"\n";

	me->start_busy(2 + random(2));
	ap = me->query_skill("ranmu-daofa", 1) + me->query_skill("force");
	dp = target->query_skill("force", 1) + target->query_skill("force");

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 3);
		me->add("neili", -400);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 42,
					   RED "只闻一股焦臭从$n" RED "处传来，已被"
					   "$P" RED "这精深奥妙的一"
					   "刀击中，鲜血飞溅而出！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "见$P" CYN "来势汹汹，不敢抵挡，急忙斜跃避开。"NOR"\n";
		me->add("neili", -200);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
