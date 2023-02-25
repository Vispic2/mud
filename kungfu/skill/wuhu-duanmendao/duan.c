// duan.c

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "断字诀"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("五虎断门刀「断」字决只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("blade") < 120)
		return notify_fail("你的五虎断门刀还不到家，无法使用「断」字决！\n");

	if (me->query_skill_mapped("blade") != "wuhu-duanmendao")
		return notify_fail("你没有激发五虎断门刀，无法使用「断」字决！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "猛然伏地，使出五虎断门刀「断」字决，顿"
	      "时一片白光直向前滚去！"NOR"\n";
	message_combatd(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

	me->add("neili", -150);
	me->start_busy(1 + random(3));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
