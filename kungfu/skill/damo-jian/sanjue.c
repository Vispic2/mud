// sanjue.c  达摩剑 达摩三绝剑

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "三绝剑"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「达摩三绝剑」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_dex() < 30)
		return notify_fail("你的身法不够，目前还不能使用这项绝技！\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你的内功的修为不够，不能使用这一绝技！\n");

	if (me->query_skill("dodge") < 200)
		return notify_fail("你的轻功修为不够，不能使用达摩三绝剑！\n");
 
	if (me->query_skill("sword") < 200)
		return notify_fail("你的剑法修为不够，目前不能使用达摩三绝剑！\n");

	if (me->query("neili") < 150)
		return notify_fail("你的真气不够，不能使用达摩三绝剑！\n");

	if (me->query_skill_mapped("sword") != "damo-jian")
		return notify_fail("你没有激发达摩剑，不能使用达摩三绝剑！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！"NOR"\n";
	message_combatd(msg, me);

	me->add("neili", -75);

	// The first attack
      	COMBAT_D->do_attack(me, target, weapon, 0);

	// The second attack
	me->add_temp("apply/attack", 40);
	COMBAT_D->do_attack(me, target, weapon, 0);

	// The third attack
	me->add_temp("apply/attack", 40);
	COMBAT_D->do_attack(me, target, weapon, 0);

	// Back
	me->add_temp("apply/attack", -80);

	me->start_busy(1 + random(3));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
