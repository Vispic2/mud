// jingang.c 金刚印

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "金刚印"; }

int perform(object me, object target)
{
	string msg;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「金刚印」只能对战斗中的对手使用。\n");

	skill = me->query_skill("dashou-yin", 1);

	if (skill < 100)
		return notify_fail("你的大手印修为不够, 不能使用「金刚印」！\n");

	if (me->query("neili") < 150)
		return notify_fail("你的真气不够，无法运用「金刚印」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "面容庄重，伸手拍出，正是密宗绝学「金刚印」。"NOR"\n";

	ap = me->query_skill("hand", 1) / 2 + skill;
	dp = target->query_skill("parry");
	if (dp < 1) dp = 1;
	if (ap / 2 + random(ap * 4 / 5) > dp)
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage = 10 + skill / 3 + random(skill / 2);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
					   HIR "结果$p" HIR "招架不及，被$P" HIR
					   "这一下打得七窍生烟，吐血连连。"NOR"\n");
	} else
	{
		me->add("neili",-40);
		msg += CYN "可是$p" CYN "不慌不忙，巧妙的架开了$P"
		       CYN "的金刚印。"NOR"\n";
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
