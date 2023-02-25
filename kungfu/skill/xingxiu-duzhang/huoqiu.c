// 弹射火球

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "弹射"ZJBR"火球"; }

int perform(object me, object target)
{
	object du;
	int damage;
	int ap;
	string msg;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手弹射火球。\n");

	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("你的抽髓掌火候不够。\n");

	if ((int)me->query_skill("poison", 1) < 120)
		return notify_fail("你的基本毒技火候不够。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 120)
		return notify_fail("你的化功大法火候不够。\n");

	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力修为不足，无法用内力弹射火球。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你现在内息不足，无法用内力弹射火球。\n");

	if (! objectp(du = me->query_temp("handing")) && userp(me))
		return notify_fail("你首先要拿着(hand)一些毒药作为引子。\n");

	if (objectp(du) && ! mapp(du->query("poison")))
		return notify_fail(du->name() + "又不是毒药，无法弹射？\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "提运内力，一声爆喝，对准$n"
	      HIR "猛地弹出一个殷红色的火球，携着一股热浪向$p" HIR "扑去。"NOR"\n";
	me->start_busy(2 + random(2));
	me->add("neili", -200);

	lvl = me->query_skill("chousui-zhang", 1);
	damage = 50 + random(lvl);

	if (me->query("max_neili") / 2 + random(me->query("max_neili")) <
	    target->query("max_neili") * 16 / 10)
	{
		msg += WHT "可是$n" WHT "浑然不放在眼里，衣袖轻轻一拂，便将火球熄灭。"NOR"\n";
	} else
	{
		ap = me->query_skill("poison", 1) / 2 +
		     me->query_skill("force");
		if (ap + random(ap) < target->query_skill("dodge"))
		{
			msg += CYN "$n" CYN "见势不妙，急忙腾挪身形，避开了$N"
			       CYN "的攻击。"NOR"\n";
		} else
		{
			msg += HIR "结果只听$n" HIR "一声惨嚎，已被火球打中，皮肉烧得“嗤嗤”作响。"NOR"\n";
			target->affect_by("fire_poison",
				       ([ "level" : me->query("jiali") + random(me->query("jiali") * 3 / 2),
					  "id"    : me->query("id"),
					  "duration" : lvl / 30 + random(lvl / 15) ]));
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage / 2, me);
		}
	}

	if (objectp(du)) destruct(du);
	message_combatd(msg, me, target);

	return 1;
}
