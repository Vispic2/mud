// ren.c  两仪剑法「天地同仁」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天地"ZJBR"同仁"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int ap, dp;

	if (! target) target = offensive_target(me);
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("没装备剑也想使「天地同仁」？\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天地同仁」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("liangyi-jian", 1) < 60)
		return notify_fail("你两仪剑法不够娴熟，使不出「天地同仁」。\n");

	if ((int)me->query_skill("taiji-shengong", 1) < 90)
		return notify_fail("你太极神功火候不够，使不出「天地同仁」。\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail("你内力修为不足，无法运足内力。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够，没能将「天地同仁」使完！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "手中长剑剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n"
	      HIC "，\n$n" HIC "看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭"
	      "向右首！\n";
	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword");
		damage = damage / 2 + random(damage / 2);

		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIC "$n" HIC "疾忙左转，却发现$N"
					   HIC "的剑根本没有右偏，" + weapon->name() +
					   HIC "登时把$n" HIC "的左胸留下一个血洞，"
					   "血涌泉喷出！"NOR"\n");
		me->add("neili", -180);
	} else
	{
		me->start_busy(2);
		msg += HIY "可是$p" HIY "轻轻一笑，侧身右转，果然$P"
		       HIY "的剑式突然左展，在$p" HIY "身前\n划过，"
		       "仅差半寸。却是一根毫毛都没伤到。"NOR"\n";
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
