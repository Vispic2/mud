#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "诛天"ZJBR"弑神"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon, weapon2;
	int damage;
	string  msg;
	string  pmsg;
	string *limbs;
	string  limb;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill_mapped("sword") != "zhuihun-jian") 
		return notify_fail("你没有激发追魂夺命剑，无法使用「诛天刹神」。\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「诛天刹神」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("zhuihun-jian", 1) < 160)
		return notify_fail("你的追魂夺命剑还不够娴熟，不能使用「诛天刹神」。\n");
				
	if ((int)me->query("neili", 1) < 300)
		return notify_fail("你现在内力太弱，不能使用「诛天刹神」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "突然$N" HIW "一声冷哼，一个跨步，手中" + weapon->name() +
	      NOR + HIW "中攻直进，如闪电一般刺向$n" HIW "！"NOR"\n";
	me->add("neili", -150);

	ap = me->query_skill("zhuihun-jian", 1) +
	     me->query_skill("sword", 1);
	dp = target->query_skill("parry", 1) * 2;

	me->want_kill(target);
	if (target->query("static/sadly") > 2)
		ap = ap * 2;

	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(2);
		me->add("neili", -200);
		damage = 0;

		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			damage = ap * 5 + (int)me->query_skill("force");

			pmsg = HIR "只见$N" HIR "这一剑来势好快，便听“嗤"
			       "啦”一声，剑尖已没入$n" HIR "咽喉半尺，\n$n"
			       HIR "咯咯叫了两声，软绵绵的瘫了下去。"NOR"\n";

			msg += COMBAT_D->do_damage(me, target,
			       WEAPON_ATTACK, damage, 120, pmsg);
		} else

		if (objectp(weapon2 = target->query_temp("weapon")) &&
		   me->query_skill("force") > target->query_skill("parry") &&
		   ! random(3))
		{
			msg += HIR "只听“嗤啦”一声，$n" HIR "腕部已被$N"
			       HIR + weapon->name() + NOR + HIR "对穿而过"
			       "，手中" + weapon2->name() + NOR + HIR
			       "再也捉拿不住，脱手而飞！"NOR"\n";
			me->start_busy(random(2));
			weapon2->move(environment(target));
		} else
		{
			damage = ap + (int)me->query_skill("force");
		      
			if (arrayp(limbs = target->query("limbs")))
				limb = limbs[random(sizeof(limbs))];
			else
				limb = "要害";
			pmsg = HIR "$n" HIR "飞身躲闪，然而只听“嗤啦”"
			       "一声，$N" HIR + weapon->name() + NOR +
			       HIR "已没入$n" HIR + limb + "半寸，鲜血"
			       "狂溅而出。"NOR"\n";
			msg += COMBAT_D->do_damage(me, target,
			       WEAPON_ATTACK, damage, 70, pmsg);
		}
	} else 
	{
		me->start_busy(3);
		msg += CYN "可是$p" CYN "看破了$P"
		       CYN "的企图，避开了这一招。"NOR"\n";
	}

	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
