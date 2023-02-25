// huimou.c 贵妃回眸
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "贵妃"ZJBR"回眸"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
  
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("贵妃回眸只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 150)
		return notify_fail("你的神龙八式手法还不够娴熟，不能使用贵妃回眸。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，不能使用贵妃回眸。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在真气不够，不能使用贵妃回眸。\n");

	if (me->query_skill_mapped("hand") != "shenlong-bashi")
		return notify_fail("你没有激发神龙八式手法，不能使用贵妃回眸。\n");

	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "身子微曲，纤腰轻扭，右足反踢向$n小腹"
	      HIG "去。$n瘁缩相避，$N顺势反过身来，左手搂住$n的头"
	      HIG "颈，右手对准了$n的瘁心猛的一招。"NOR"\n";
	      
	me->start_busy(2 + random(2));

	if (random(me->query_skill("hand")) > target->query_skill("parry") / 2)
	{
		damage = (int)me->query_skill("force");
		damage = damage * 3 / 4 + random(damage);
		me->add("neili", -180);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
					   HIR "$p" HIR "急忙提手去隔，却没能挡住$P" 
					   HIR "的招数，结果被$P" HIR "重重的击中，"
					   "哇的吐了一口鲜血。"NOR"\n");
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，甩头避开了$P"
		       CYN "的进攻。"NOR"\n";
		me->add("neili", -70);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
