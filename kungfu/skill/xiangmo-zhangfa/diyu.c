#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "地狱"ZJBR"焚身"; }
string *pfm_type() { return ({ "staff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int lvl;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「地狱焚身」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须手持一把杖才能施展「地狱焚身」！\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以施展「地狱焚身」！\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展「地狱焚身」！\n");

	if ((lvl = (int)me->query_skill("xiangmo-zhangfa", 1)) < 120)
		return notify_fail("你的降魔杖法还不到家，无法使用地狱焚身！\n");

	if (me->query_skill_mapped("staff") != "xiangmo-zhangfa")
		return notify_fail("你没有激发降魔杖法，无法使用地狱焚身！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "长啸一声，将全身功力注入手中的" + weapon->name() +
	      HIW "顿时间" HIR "霞光四射" HIW "，照得$n睁不开眼" HIW "！"NOR"\n";

	if (lvl / 2 + random(lvl) > target->query_skill("parry",1) * 2 / 3)
	{
		msg += HIY "$n" HIY "见$N" HIY "把手中的" + weapon->name() +
		       HIY "幻起一片枪林杖雨,顿时喘不过气来，进攻防守全都失去了章法。"NOR"\n";
		count = lvl / 6;
		me->add_temp("apply/attack", count);
	} else
		count = 0;

	message_combatd(msg, me, target);
	me->add("neili", -100);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(2) && ! target->is_busy())
			target->start_busy(1);
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
