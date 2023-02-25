// ruyi.c 如意六刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "如意"ZJBR"六刀"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「如意六刀」只能对战斗中的对手使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("刀都没有，使什么「如意六刀」？\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 145 )
		return notify_fail("你的内功火候不够！\n");

	if (me->query_skill("blade") < 135)
		return notify_fail("你的如意刀法还不到家，无法使用「如意六刀」！\n");

	if (me->query_skill_mapped("blade") != "ruyi-dao")
		return notify_fail("你没有激发如意刀法，无法使用「如意六刀」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "使出逍遥绝技「如意六刀」，身法忽然奇快无比，变幻莫测！"NOR"\n";
	message_combatd(msg, me);
	me->add("neili", -120);

	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(1 + random(6));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
