// hua.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "化功"ZJBR"大法"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	if (target == me) target = offensive_target(me);

	if (environment(me)->query("no_fight"))
		return notify_fail("在这里不能攻击他人。\n");

	if (! objectp(target))
		return notify_fail("你要化谁的内力？\n");

	if (target->query("race") != "人类")
		return notify_fail("搞错了！只有人才能有内力！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙，无法化他人内力。\n");

	my_max = me->query("max_neili");
	tg_max = target->query("max_neili");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能施用化功大法！\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 90)
		return notify_fail("你的化功大法功力不够，不能施展！\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的内力不够，不能施展化功大法。\n");

	if ((int)target->query("neili") < 10 ||
	    (int)target->query("max_neili") < 10)
		return notify_fail(target->name() +
				   "已然内力涣散，不必再化了。\n");

	if ((int)target->query("max_neili") > (int)me->query("max_neili") * 4 / 3 )
		return notify_fail(target->name() +
			"的内功修为远胜于你，你无法从化他的内力！\n");

	message_combatd(HIR "$N" HIR "全身骨节爆响，双臂暴长数尺，手掌"
			"刷的一抖，粘向$n！"NOR"\n",
			me, target);

	me->want_kill(target);
	if (living(target))
		if (! target->is_killing(me)) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge");
	dp = target->query_skill("force") + target->query_skill("dodge");

	me->start_busy(4 + random(4));
	if ((sp / 2 + random(sp) > random(dp)) || ! living(target))
	{
		message_combatd(HIR "$N" HIR "只觉天顶骨裂，全身功力"
				"贯脑而出，如融雪般消失得无影无踪！"NOR"\n",
				target);

		target->add("max_neili", -1 * (1 + (me->query_skill("huagong-dafa", 1) - 90) / 8));
		if (target->query("max_neili") < 1)
			target->set("max_neili", 0);

		if (! target->is_busy()) target->start_busy(2);
	} else
	{	
		message_combatd(HIY "可是$p" HIY "看破了$P"
				HIY "的企图，内力猛地一震，借势溜"
				"了开去。"NOR"\n", me, target);
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
