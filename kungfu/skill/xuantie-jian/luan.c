// luan.c

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "乱字诀"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	int count;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("乱字诀只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("施展乱字诀必须拿着一把剑！\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法施展乱字诀！\n");

	if (me->query_skill("surge-force", 1) < 250)
		return notify_fail("你的怒海狂涛内功火候不够，难以施展如此凶猛的武功！\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 250)
		return notify_fail("你的玄铁剑法还不到家，无法使用乱字诀！\n");

	if (me->query_skill("martial-cognize", 1) < 120)
		return notify_fail("你的武学修养有限，难以施展出乱字诀中的精微奥妙之处！\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("你没有激发玄铁剑法，无法使用乱字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "仰天长啸，手中" + weapon->name() +
	      HIY "劈头盖脑的奔$n" HIY "砍去，霎时已劈出了无数剑。\n"
	      "四下空气激荡回旋，有如海浪涛涛叠叠，将$n"
	      HIY "团团卷在其中！"NOR"\n";
	me->add("neili", -100);

	count = (me->query_skill("martial-cognize", 1) -
		 target->query_skill("martial-cognize", 1)) / 3;
	if (count < -10)
		msg += HIG "然而$n" HIG "乃武学大家，对此汹涌澎"
		       "湃的攻势丝毫不惧，于剑光中进退自如。"NOR"\n";
	else
	if (count < 30)
		msg += HIC "然而$n" HIC "见识非凡，不在$N"
		       HIC "之下，在这汹涌入潮的攻击下镇定自如，从容抵挡。"NOR"\n";
	else
	{
		msg += HIR "$n" HIR "大吃一惊，只觉得$N"
		       HIR "内力有如潮水般涌至，眼前剑网闪亮，黑白难辨。"NOR"\n";
		if (count > 50) count = 50;
	}
	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(5));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
