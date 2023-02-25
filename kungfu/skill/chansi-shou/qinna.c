#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "擒拿手"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("缠丝擒拿手只能在战斗中对对手使用。\n");

	skill = me->query_skill("chansi-shou", 1);

	if (skill < 120)
		return notify_fail("你的缠丝擒拿手等级不够，不会使用绝技！\n");

	if (me->query("neili") < 100)
		return notify_fail("你的真气不够，无法运用绝技！\n");
 
	if (me->query_skill_mapped("hand") != "chansi-shou") 
		return notify_fail("你没有激发缠丝擒拿手，无法使用绝技！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "悄然贴近$n" HIC "，猛然使出缠丝擒拿手，只见$P"
	      "双手忽折忽扭，或抓或甩，直琐$n" HIC "各处要脉！"NOR"\n";
 
	ap = me->query_skill("hand");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -80);
		damage = 40 + ap / 6 + random(ap / 6);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
					   HIR "$p" HIR "奋力抵抗，终究不敌$P"
					   HIR "，连中数招后还是被压制得无法"
					   "反击！"NOR"\n");
		me->start_busy(1);
		if (ap / 3 + random(ap) > dp && ! target->is_busy())
			target->start_busy(ap / 25 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "的看破了$P" CYN
		       "的招式，巧妙的一一拆解，没露半点破绽！"NOR"\n";
		me->add("neili",-20);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
