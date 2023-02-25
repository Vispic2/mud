// dian.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "银索"ZJBR"点穴"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("点穴攻击只能对战斗中的对手使用。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    weapon->query("skill_type") != "whip")
		return notify_fail("你的武器不对，无法点穴！\n");

	if (me->query_skill("yinsuo-jinling", 1) < 50)
		return notify_fail("你的银索金铃级别不够，无法点穴！\n");

	if (me->query("neili") < 50)
		return notify_fail("你现在真气不够，无法点穴！\n");

	if (me->query_skill_mapped("whip") != "yinsuo-jinling")
		return notify_fail("你没有激发银索金铃，无法点穴！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "单手一抖，手中" + weapon->name() +
	      HIY "疾颤三下，分点$n" HIY "脸上「迎香"
	      "」、「承泣」、「人中」三个穴道，\n这三下"
	      "点穴出手之快、认位之准，实是武林罕见！\n";

	ap = me->query_skill("whip");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "$n" HIR "只听$N" + weapon->name() +
		       HIR "发出玎玎声响，声虽不大，却是"
		       "十分怪异，入耳荡心摇魄，一不\n留神"
		       "，被这招点个正着，全身瘫软无力，动"
		       "弹不得！"NOR"\n";
		target->start_busy((int)me->query_skill("yinsuo-jinling") / 20 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P"
		       CYN "的企图，斜跳躲闪开来。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
