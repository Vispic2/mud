#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "阴风"ZJBR"绝杀"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int damage;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("阴风刀「绝杀」只能在战斗中使用。\n");

	if ((int)me->query_skill("yinfeng-dao", 1) < 100)
		return notify_fail("你的阴风刀还不够娴熟，无法施展「绝杀」绝技！\n");

	if ((int)me->query_skill("force") < 160)
		return notify_fail("你内功火候不够，难以施展「绝杀」绝技！\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的真气不够，无法施展「绝杀」绝技！！\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法施展「绝杀」绝技！！\n");

	if (me->query_skill_mapped("strike") != "yinfeng-dao") 
		return notify_fail("你没有激发阴风刀，无法使用「绝杀」绝技！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N使出阴风刀「绝杀」绝技，掌劲幻出一片片切骨寒气如飓风般裹向$n全身！"NOR"\n";

	lvl = me->query_skill("yinfeng-dao", 1);
	ap = me->query_skill("strike") + me->query_skill("force");
	dp = target->query_skill("parry") + me->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 4);
		target->affect_by("yinfeng_dao",
			       ([ "level" : me->query("jiali") + random(me->query("jiali")),
				  "id"    : me->query("id"),
				  "duration" : lvl / 50 + random(lvl / 20) ]));
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
	      HIR "结果只听$n一声惨嚎，全身几处要穴同时被阴风寒劲砍中，疼若刮骨，鲜血狂泄而出！"NOR"\n");

		me->add("neili", -250);
		me->start_busy(1);
	} else
	{
		msg += CYN "可是$n急忙退闪，连消带打躲开了这一击。"NOR"\n";
		me->start_busy(3);
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
