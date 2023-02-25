// zhong.c 种生死符

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "中生"ZJBR"死符"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	int damage;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能战斗。\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("生死符只能种在战斗中的对手身上。\n");

	if (target->query("not_living"))
		return notify_fail("看清楚了，那不是活人。\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你的内功不够火候，不能种生死符。\n");

	if ((int)me->query_skill("liuyang-zhang", 1) < 150)
		return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");

	if (me->query_skill_mapped("strike") != "liuyang-zhang")
		return notify_fail("你没有激发天山六阳掌，不能种生死符。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "逆运真气，化空气中的水露为冰，凝"
	      "于掌中，轻飘飘地拍向$n" HIC "。\n";

	ap = me->query_skill("strike");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 53,
					   CYN "结果$p" CYN "被$P" CYN "攻了个正着，中了$P"
					   CYN "一枚生死符！"NOR"\n");
		target->affect_by("ss_poison",
			       ([ "level" : me->query("jiali") + random(me->query("jiali")),
				  "id"    : me->query("id"),
				  "duration" : ap / 70 + random(ap / 30) ]));
		me->start_busy(1 + random(4));
	} else
	{
		msg += CYN "可是$p" CYN "内力激荡，让$P"
		       CYN "的生死符无法发挥任何效用。"NOR"\n";
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
