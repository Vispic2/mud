// pai.c 降龙十八掌「排山倒海」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "排山"ZJBR"倒海"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	int level;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("降龙十八掌排山倒海只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon"))
		return notify_fail("你必须空手才能施展排山倒海。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("dragon-strike", 1)) < 120)
		return notify_fail("你的降龙十八掌不够娴熟，不会使用排山倒海。\n");

	if (me->query_skill_mapped("strike") != "dragon-strike")
		return notify_fail("你必须激发降龙十八掌才能使用排山倒海。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在真气不够，无法使用排山倒海。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "大喝一声，往前踏一大步，左掌怒挥，一股雄浑无比的掌力"
	      "已席卷而去。再踏一大步，\n右掌随即递出，漫天黄叶飞舞，隐隐"
	      "有风雷之声，压向$n" HIR "。"NOR"\n";

	me->add("neili", -60);
	ap = me->query_skill("strike");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "气势所慑，一时间只觉得呼吸不畅，"
		       "全身再无半点力气反击。"NOR"\n";
		target->start_busy(level / 21 + 2);
	} else
	{
		msg += CYN "然而$p" CYN "内力深厚，和$P" CYN
		       "微一交手，随即连退数步，已然脱离了你的掌力范围。"NOR"\n";
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
