// chan.c 全真剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "缠字诀"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("全真剑法「缠」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("quanzhen-jian", 1)) < 80)
		return notify_fail("你的全真剑法不够娴熟，不会使用「缠」字诀。\n");

	if (me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("你必须激发全真剑法才能使用「缠」字诀。\n");

	if (me->query("neili") < 60)
		return notify_fail("你现在真气不够，无法使用「缠」字诀。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出全真剑法「缠」字诀，上挑下刺，" +
	      weapon->name() + HIY "带出阵阵风声，缠绕盘旋，从四面八方"
	      "袭向$n" HIY "。"NOR"\n";

	me->add("neili", -45);
	ap = me->query_skill("sword");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "$p" HIR "只觉得$P" HIR
		       "剑上压力一层强过一层，只能使尽浑身解数运功抵挡。"NOR"\n";
		target->start_busy(level / 28 + 2);
	} else
	{
		msg += CYN "$p" CYN "见$P" CYN "此招法度严谨，不敢小觑，以浑厚的"
		       "内功为根基，巧妙的拆解$P" CYN "的来招，不露半点破绽。"NOR"\n";
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
