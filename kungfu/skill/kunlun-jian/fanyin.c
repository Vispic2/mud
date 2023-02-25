#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "域外"ZJBR"梵音"; }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, jing_wound;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「域外梵音」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("tanqin-jifa", 1) < 120)
		return notify_fail("你的弹琴技法尚且不够熟练, 发不出「域外梵音」！\n");

	if (me->query_skill("kunlun-jian", 1) < 120)
		return notify_fail("你的昆仑剑法等级不够, 发不出「域外梵音」！\n");

	if (me->query("max_neili") < 800)
		return notify_fail("你的内力修为尚且无法达到使用「域外梵音」所需的境界！\n");

	if (me->query("neili") < 300)
		return notify_fail("你的真气不够，运足「域外梵音」所需的内力！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = MAG "$N微微一笑，左手横握剑柄，右手五指对准" + weapon->name() + NOR +
	      MAG "剑脊轻轻弹拨，剑身微颤，声若龙吟。\n顿时发出一阵清脆的琴音……"NOR"\n";

	skill = me->query_skill("kunlun-jian",1);
	ap = me->query_skill("sword");
	dp = target->query_skill("force");
	if (dp < 1) dp = 1;
	if (random(ap) > dp / 2)
	{
		me->add("neili", -200);
		jing_wound = (int)me->query_skill("sword") +
			   (int)me->query_skill("tanqin-jifa", 1);
		jing_wound = jing_wound / 2 + random(jing_wound / 2);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, jing_wound, 66,
		       MAG "$n顿时只觉琴音犹如两柄利剑一般刺进双耳，刹那间头晕目眩，全身刺痛！"NOR"\n");
		me->start_busy(2 + random(2));
	} else
	{
		me->add("neili", -50);
		msg += HIG "可是$n赶忙宁心静气，收敛心神，丝毫不受$N琴音的干扰。"NOR"\n";
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
