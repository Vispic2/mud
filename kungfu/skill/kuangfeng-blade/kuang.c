// kuang.c -「狂风二十一式」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "狂风"ZJBR"刀法"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手使用「狂风二十一式」。\n");

	if ((int)me->query_skill("kuangfeng-blade", 1) < 70)
		return notify_fail("你目前功力还使不出「狂风二十一式」。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -60);
	msg = HIC "$N" HIC "淡然一笑，本就快捷绝伦的刀法骤然变"
	      "得更加凌厉！就在这一瞬之间，$N" HIC "已劈出二十"
	      "一刀！\n刀夹杂着风，风里含着刀影！$n"
	      HIC "只觉得心跳都停止了！"NOR"\n";
	me->start_busy(2);

	ap = me->query_skill("blade");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(2);
		damage = ap / 2 + random(ap / 2);

		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40, 
					   HIR "只见$n" HIR "已被$N" HIR
					   "切得体无完肤，血如箭般由全身喷射而出！"NOR"\n");
	} else
	{
		me->start_busy(1);
		msg += HIC "可是$p" HIC "急忙抽身躲开，使$P"
		       HIC "这招没有得逞。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
