// hui.c  回风拂柳剑法「回风拂柳」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "回风"ZJBR"拂柳"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	string wname;
	int ap, dp;

	if (userp(me) && ! me->query("can_perform/huifeng-jian/hui"))
		return notify_fail("你还不会使用「回风拂柳」这一绝技。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「回风拂柳」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("没装备剑怎么使用「回风拂柳」？\n");

	if (me->query_skill_mapped("sword") != "huifeng-jian")
		return notify_fail("你没有激发回风拂柳剑法，不能使用「回风拂柳」。\n");

	if ((int)me->query_skill("huifeng-jian", 1) < 120)
		return notify_fail("你的回风拂柳剑法不够娴熟，还使不出「回风拂柳」。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以施展「回风拂柳」。\n");

	if ((int)me->query("neili") < 500)
	       return notify_fail("你现在真气不够，难以施展「回风拂柳」！"NOR"\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	wname = weapon->name();

	damage = (int)me->query_skill("huifeng-jian", 1) / 2;
	damage += random(damage);

	// 第一招
	ap = me->query_str();
	dp = target->query_str();
	msg = HIC "$N" HIC "一声暴喝，手中的" + wname + HIC "对准$n" HIC "直劈而下！"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "$p" HIR "奋力抵挡，却哪里招架得住？被$P"
					   HIR "这一剑劈下，登时鲜血迸流！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "嘿的一声，硬声声将$P"
		       CYN "这一剑架开，丝毫无损。"NOR"\n";
	}

	// 第二招
	ap = me->query_int();
	dp = target->query_int();
	msg += "\n" HIC "$N" HIC "随即一声冷笑，手中的" + wname +
	       HIC "伸伸缩缩，吞吞吐吐，变幻莫测，层层剑光笼罩了$n" HIC "。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
					   HIR "$p" HIR "大惑不解，一时难以勘透其"
					   "中奥妙，一连中了几招，身披数创！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "淡淡一笑，浑然不将$P"
		CYN "玄妙的招数放在眼中，随意将之架开。"NOR"\n";
	}

	// 第三招
	ap = me->query_con();
	dp = target->query_con();
	msg += "\n" HIC "$N" HIC "深深吸了一口气，手中的" + wname +
	       HIC "幻化出一层浅浅的光芒，人剑合一，扑向$n" HIC "。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "$p" HIR "运气抵挡，只觉得一股透体凉意"
					   "袭了上来，一个激凌，丹田立刻变得空空荡荡！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "一口气自丹田运了上来，$P"
		CYN "附体剑芒虽然厉害，却未能伤$p" CYN "分毫。"NOR"\n";
	}

	// 第四招
	ap = me->query_dex();
	dp = target->query_dex();
	msg += "\n" HIC "$N" HIC "脚步一晃，忽然近上身来，身法奇快，手中的" + wname +
	       HIC "应声而起，刺向$n" HIC "。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
					   HIR "$p" HIR "只是慢了一步，登时被$P"
					   HIR "这一剑刺了个正中，鲜血四处飞射！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "身法却是更快，只是一退，让$P"
		CYN "这一招堪勘不能奏效。"NOR"\n";
	}

	// 第五招
	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	msg += "\n" HIC "$N" HIC "一声长叹，眼神变得寒冷无情，" + wname +
	       HIC "悠悠而转，四下空气瑟瑟，萧然肃杀，长剑犹如轻风拂柳，说不清的缠绵之意。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
					   HIR "$p" HIR "只觉得沐浴在风中一般，对这招竟然是无可抵挡，被"
					   HIR "剑光削了个血肉模糊！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "冷静非凡，丝毫不为这奇幻的招数"
		       "所动，凝神抵挡，不漏半点破绽！"NOR"\n";
	}

	me->start_busy(2 + random(5));
	me->add("neili", -400 - random(100));
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
