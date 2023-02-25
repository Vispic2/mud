// ci.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "神门刺"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp;

	if (userp(me) && ! me->query("can_perform/shenmen-jian/ci"))
		return notify_fail("你还不会使用「神门刺」这一招。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	skill = me->query_skill("shenmen-jian", 1);

	if (! target || ! me->is_fighting(target))
		return notify_fail("神门刺只能对战斗中的对手使用。\n");

	if (! objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有使用兵器，你用了神门刺也没用。\n");

	if (skill < 120)
		return notify_fail("你的神门十三剑等级不够, 无法施展神门刺。\n");

	if (me->query("neili") < 200)
		return notify_fail("你的内力不够，无法施展神门刺！\n");

	if (me->query_skill_mapped("sword") != "shenmen-jian")
		return notify_fail("你现在没有激发神门十三剑，无法施展神门刺。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "突然$N" HIY "一声冷哼，手中" + weapon->name() + NOR HIY
		  "中攻直进，直刺$n拿着的" +weapon2->name() + NOR HIY "的"
		  "手腕。"NOR"\n";
	message_combatd(msg, me, target);

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	if (dp < 1) dp = 1;

	if (ap / 4 + random(ap) > dp)
	{
		me->add("neili", -120);
		msg = HIR "$n" HIR "只觉手腕一阵刺痛，手中" + weapon2->name() + HIR
		      "再也拿捏不住，脱手而飞！"NOR"\n";
		me->start_busy(2 + random(2));
		weapon2->move(environment(target));
	} else
	{
		me->add("neili", -40);
		msg = CYN "可是$n" CYN "看破了$N" CYN "的企图，将手中兵刃挥"
		      "舞得密不透风，挡开了$N" CYN "的兵器。"NOR"\n";
		me->start_busy(4);
	}

	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
