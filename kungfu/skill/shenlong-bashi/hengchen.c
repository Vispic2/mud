// hengchen.c 小怜横陈

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "小怜"ZJBR"横陈"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("小怜横陈只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 150)
		return notify_fail("你的神龙八式手法还不够娴熟，不能使用小怜横陈。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，不能使用小怜横陈。\n");

	if ((int)me->query("neili") < 400)
		return notify_fail("你现在真气不够，不能使用小怜横陈。\n");

	if (me->query_skill_mapped("hand") != "shenlong-bashi")
		return notify_fail("你没有激发神龙八式手法，不能使用小怜横陈。\n");

	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "顺势在地下一个筋斗，在$n胯下钻过，"
	      HIG "右手成拳，重重一拳击向$n的瘁心。"NOR"\n";
	      
	me->start_busy(1 + random(4));

	if (random(me->query_skill("hand")) > target->query_skill("dodge") / 2 )
	{
		damage = (int)me->query_skill("hand") + (int)me->query_skill("force");
		damage = damage / 2 + random(damage);
		me->add("neili", -210);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
					   HIR "$p" HIR "急忙后退两步，却还是没能" 
					   "躲过$P" HIR "的招数，被打得口吐鲜血。"NOR"\n");
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，一扭身闪开了$P"
		       CYN "的进攻。"NOR"\n";
		me->add("neili", -80);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
