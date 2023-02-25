// yong.c 玄黄连环掌

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "玄黄"ZJBR"连环"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	int count;
	int lvl;
	int i,ap,dp;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("玄黄连环掌只能对战斗中的对手使用。\n");
 
	if (me->query("neili") < 200)
		return notify_fail("你的真气不够，无法施展玄黄连环掌！\n");

	if ((lvl = me->query_skill("bluesea-force", 1)) < 150)
		return notify_fail("你的南海玄功火候不够，无法施展玄黄连环掌！\n");

	if (me->query_skill_mapped("strike") != "bluesea-force")
		return notify_fail("你没有激发南海玄功为掌法，无法施展玄黄连环掌！\n");

	if (me->query_skill_prepared("strike") != "bluesea-force")
		return notify_fail("你没有准备好使用南海玄功，无法施展玄黄连环掌！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	ap = me->query_skill("strike") + me->query("con") * 30 +
	     me->query_skill("martial-cognize", 1);
	dp = target->query_skill("force") + target->query("con") * 30 +
	     target->query_skill("martial-cognize", 1);


	msg = HIC "$N" HIC "轻轻划了个圈子，身形忽然变快，合数招为一击攻向$n"
	      HIC "！"NOR"\n";
	i = 5;
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIY "内力激荡之下，$n" HIY "登时觉得呼吸"
		       "不畅，浑身有如重压，万分难受，只见$N"
		       HIY "一掌接一掌的攻到，有如海浪。"NOR"\n";
		count = me->query_skill("bluesea-force", 1) / 5;
		me->add_temp("apply/attack", count);
		i += random(5);
	} else
	{
		msg += CYN "$n" CYN "见来掌奇快，只好振作精神勉力抵挡。"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add("neili", -i * 20);

	while (i--)
	{
		if (! me->is_fighting(target))
			break;
		if (i > 5 && ! target->is_busy())
			target->start_busy(1);
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	target->interrupt_me(target, 1);

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(7));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
