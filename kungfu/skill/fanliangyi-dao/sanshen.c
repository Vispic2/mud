// sanshen.c 华岳三神峰

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "华岳"ZJBR"三神"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「华岳三神峰」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功功力不足！\n");

	if ((int)me->query_skill("blade") < 50 ||
	    me->query_skill_mapped("blade") != "fanliangyi-dao")
		return notify_fail("你的「反两仪刀法」还不到家，无法使用「华岳三神峰」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出华山派绝技「华岳三神峰」，身"
	      "法突然变得异常灵动飘忽！"NOR"\n";
	message_combatd(msg, me);

	for (i = 0; i < 3; i++)
	{
		if (! me->is_fighting(target))
			break;

		COMBAT_D->do_attack(me, target, weapon);
	}

	me->add("neili", -100);
	me->start_busy(1 + random(3));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
