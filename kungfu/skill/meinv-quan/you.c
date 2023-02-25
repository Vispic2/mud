// you.c 美女拳-古墓幽居

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "古墓"ZJBR"幽居"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	string pmsg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("古墓幽居只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("meinv-quan", 1) < 80)
		return notify_fail("你的美女拳级别不够，不会使用古墓幽居。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功还未娴熟，不能利用神功伤敌。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你现在真气不够，不能使用古墓幽居。\n");

	if (me->query_skill_mapped("unarmed") != "meinv-quan")
		return notify_fail("你没有激发美女拳法，不能施展古墓幽居。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "右手支颐，左袖轻轻挥出，长叹一声，使"
	      "出「古墓幽居」，一脸尽现寂寥之意。"NOR"\n";

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		me->start_busy(random(3));

		damage = (int)me->query_skill("unarmed");
		damage = damage / 2 + random(damage / 2);

		me->add("neili", -100);

		if (damage < 30)
			pmsg = HIY "结果$n" HIY "被$N袍"
			       HIY "袖一拂，闷哼一声。"NOR"\n";
		else if(damage < 55)
			pmsg = HIY "结果$n" HIY "被$N"
			       HIY "以袍袖一拂，「腾腾」地退出几步。"NOR"\n";
		else if (damage < 80)
			pmsg = HIR "结果$n" HIR "被$N"
			       HIR "以袍袖一拂，胸口有如受到一记重"
			       "锤，气血为之一窒！"NOR"\n";
		else
			pmsg = RED "结果$n" RED "被$N" RED
			       "的袍袖一拂，眼前一黑，浑身气血翻腾，"
			       "竟如身入洪炉一般！"NOR"\n";
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30, pmsg);
	} else
	{
		me->start_busy(3);
		msg += CYN "可是$p" CYN "看破了$P" CYN
		       "的企图，稳如泰山，抬手一架格开了$P"
		       CYN "这一拳。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
