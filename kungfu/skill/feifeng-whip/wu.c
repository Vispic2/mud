// jing.c 惊天一击

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "飞凤"ZJBR"翔舞"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int damage;
	int i;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("「飞凤翔舞」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query_skill("feifeng-whip", 1) < 60)
		return notify_fail("你的飞凤鞭法不够娴熟，不会使用「飞凤翔舞」。\n");
				
	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功修为不够高。\n");
			
	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够，不能使用「飞凤翔舞」。\n");

	if (me->query_skill_mapped("whip") != "feifeng-whip")
		return notify_fail("你现在没有激发飞凤鞭法，不能使用「飞凤翔舞」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "身子一晃，手中的" + weapon->name() +
	      HIY "画了一个圈子，缠向$n" HIY "。"NOR"\n";

	if (random(me->query_skill("whip")) > target->query_skill("force") / 2)
	{
		damage = (int)me->query_skill("force") + (int)me->query_skill("whip");
		damage = damage / 8;
		damage += random(damage);
		me->add("neili", -50);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "$n" HIR "只觉得浑身一震，内息有如"
					   "潮涌，一时不由全身乏力，向后退了一步。"NOR"\n");
		msg += HIY "\n$N" HIY "见状，手中" + weapon->name() + HIY +
		       "急挥，一连数招攻向$n" HIY "！"NOR"\n";
		message_combatd(msg, me, target);

		for (i = 0; i < 3; i++)
		{
			if (! me->is_fighting(target))
				break;
			COMBAT_D->do_attack(me, target, weapon, 0);
		}

		me->start_busy(1 + random(3));
	} else 
	{
		msg += CYN "可是$p" CYN "轻轻架开$P" CYN
		       "这一招，似乎并没有废多少气力。"NOR"\n";
		me->add("neili", -70);
		me->start_busy(3);
		message_combatd(msg, me, target);
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
