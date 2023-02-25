// jianzhang.c  剑掌五连环

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "剑掌"ZJBR"连环"; }
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
		return notify_fail("「剑掌五连环」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("「剑掌五连环」开始时必须拿着一把剑！\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展「剑掌五连环」！\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，难以施展「剑掌五连环」！\n");

	if ((int)me->query_skill("huashan-sword", 1) < 50)
		return notify_fail("你的华山剑法还不到家，无法使用剑掌五连环！\n");

	if (me->query_skill_mapped("sword") != "huashan-sword")
		return notify_fail("你没有激发华山剑法，无法使用「剑掌五连环」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出华山派绝技「剑掌五连环」，身法陡然加快！"NOR"\n";
	message_combatd(msg, me);
	me->add("neili", -100);

	count = me->query_skill("sword") / 10;
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
