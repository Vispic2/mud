// 弹射毒药

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "弹射"ZJBR"毒药"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object du;
	int damage;
	int ap;
	string msg;

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能战斗，你不可以使用毒技伤人。\n");

	if (target->query_competitor())
		return notify_fail("比武的时候最好是正大光明的较量。\n");

	if (! target || me == target)
		return notify_fail("你想攻击谁？\n");

	if ((int)me->query_skill("poison", 1) < 80)
		return notify_fail("你的基本毒技火候不够。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 100)
		return notify_fail("你的化功大法火候不够。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你现在内力不足，不能弹射毒药。\n");

	if (! objectp(du = me->query_temp("handing")))
		return notify_fail("你得先准备(hand)好毒药再说。\n");

	if (! mapp(du->query("poison")))
		return notify_fail(du->name() + "又不是毒药，你乱弹什么？\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN "运转内力，手指粘住" + du->name() +
	      CYN "对准$n" CYN "弹了过去。"NOR"\n";
	me->start_busy(2 + random(2));
	me->add("neili", -300);

	if (me->query("neili") / 2 + random(me->query("neili")) <
	    target->query("neili") * 5 / 4)
	{
		msg += WHT "然而$n轻轻一抖，将$N射过来的" + du->name() + WHT "全部震落。"NOR"\n";
	} else
	{
		ap = me->query_skill("poison", 1) / 2 +
		     me->query_skill("force");
		if (ap / 2 + random(ap) < target->query_skill("dodge") * 3 / 2)
		{
			msg += WHT "$n见势不妙，急忙腾挪身形，避开了$N的攻击。"NOR"\n";
		} else
		{
			msg += GRN "$n连忙躲闪，结果仍然觉得微微一阵麻痹。"NOR"\n";
			target->affect_by(du->query("poison_type"), du->query("poison"));
		}
	}

	destruct(du);
	message_combatd(msg, me, target);
	me->want_kill(target);
	if (! target->is_killing(me)) target->kill_ob(me);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
