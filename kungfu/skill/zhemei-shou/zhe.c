// zhe.c 折梅式
 
#include <ansi.h>
 
inherit F_SSERVER;
 
string query_name() { return "折梅式"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	string msg;
	object weapon, weapon2;
	int skill, ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「折梅式」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手才能施展「折梅式」。\n");

	if (target->is_busy())
		return notify_fail("对方现在正是手忙脚乱的呢，你不必担心。\n");

	skill = me->query_skill("zhemei-shou", 1);

	if (skill < 100)
		return notify_fail("你的天山折梅手等级不够，不能「折梅式」！\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你内功火候不够，使不出「折梅式」。\n");

	if (me->query("neili") < 100)
		return notify_fail("你的内力不够，无法施展「折梅式」！\n");
 
	if (me->query_skill_prepared("hand") != "zhemei-shou")
		return notify_fail("你没有准备使用折梅手，无法施展「折梅式」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "随手抓出，虚虚实实笼罩了$n" HIC
	      "诸处要穴。"NOR"\n";
	message_combatd(msg, me, target);
 
	ap = me->query_skill("hand");
	dp = target->query_skill("parry");
	me->add("neili", -40);
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -30);
		msg = HIY "$n" HIY "心头一颤，急忙后退数步，"
		      "一时间无法反击。"NOR"\n";
		target->start_busy(ap / 30 + 2);
	} else
	{
		msg = CYN "可是$p" CYN "的看破了$P" CYN
		      "的企图，不为所动，让$P" CYN "的"
		      "虚招没有起得任何作用。"NOR"\n";
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
