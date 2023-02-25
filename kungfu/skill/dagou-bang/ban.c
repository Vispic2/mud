// ban.c 打狗棒法「绊」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "绊字诀"; }
string *pfm_type() { return ({ "staff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int i;

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("打狗棒法「绊」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("dagou-bang", 1) < 100)
		return notify_fail("你的打狗棒法不够娴熟，不会使用「绊」字诀。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功不够深厚，难以使用「绊」字诀。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在的真气不够，无法使用「绊」字诀。\n");

	if (me->query_skill_mapped("staff") != "dagou-bang")
		return notify_fail("你没有激发打狗棒法，不能使用「绊」字诀。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "使出打狗棒法「绊」字诀，手中的" + weapon->name() +
	      HIG "左封右逼，霎时连出数招。"NOR"\n";

	message_combatd(msg, me);
	me->add("neili", -180);
	count = me->query("int") * 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 4; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(2) && ! target->is_busy())
			target->start_busy(1);
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	target->interrupt_busy(target, 1);

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(4));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
