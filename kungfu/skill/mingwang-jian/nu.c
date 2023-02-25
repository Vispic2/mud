// nu.c 明王怒

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "明王"ZJBR"之怒"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int damage;
	int i;
	int count;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「明王怒」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须有剑才能施展「明王怒」！\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展「明王怒」！\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，难以施展「明王怒」！\n");

	if ((int)me->query_skill("mingwang-jian", 1) < 50)
		return notify_fail("你的不动明王剑法还不到家，无法使用明王怒！\n");

	if (me->query_skill_mapped("sword") != "mingwang-jian")
		return notify_fail("你没有激发明王剑法，无法使用「明王怒」。\n");

       if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "大喝一声，手中" + weapon->name() +
	      HIR "犹如蛟龙出水，隐隐然含着杀气奔向$n" HIR "！"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -120);

	count  = me->query_skill("sword") / 12;
	damage = me->query_skill("force") / 10;
	me->add_temp("apply/attack", count);
	me->add_temp("apply/damage", damage);

	for (i = 0; i < 4; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -damage);
	me->start_busy(1 + random(4));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
