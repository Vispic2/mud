#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "谁与"ZJBR"争锋"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	int count;
	int lvl;
	int i;

	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/yitian-zhang/zheng"))
		return notify_fail("你现在还不会使用「谁与争锋」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「谁与争锋」只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「谁与争锋」！\n");

	if ((lvl = (int)me->query_skill("yitian-zhang", 1)) < 125)
		return notify_fail("你的倚天屠龙掌不够娴熟，不会使用「谁与争锋」。\n");

	if ((int)me->query("neili", 1) < 500)
		return notify_fail("你现在真气太弱，不能使用「谁与争锋」。\n");

	if (me->query_skill_prepared("strike") != "yitian-zhang")
		return notify_fail("你现在没有准备使用倚天屠龙掌，不能使用「谁与争锋」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "神气贯通，将倚天屠龙掌二十四字一气呵成，双掌携带着排山倒海之劲贯向$n" HIY "。"NOR"\n";
	me->add("neili", -150);

	if (random(me->query_skill("force") + me->query_skill("strike")) >
	    target->query_skill("force"))
	{
		msg += HIR "$n" HIR "顿时觉得呼吸不畅，全然被这"
		       "股力道所制，只得拼命运动抵挡。"NOR"\n";
		count = lvl / 5;
		me->add_temp("apply/attack", count);
	} else
	{
		msg += HIC "$n" HIC "深吸一口气，凝神抵挡，犹如轻舟立"
		       "于惊涛骇浪之中，左右颠簸，却是不倒。"NOR"\n";
		count = 0;
	}
	message_combatd(msg, me, target);

	for (i = 0; i < 4; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
