// huixiang.c 飞燕回翔

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "飞燕"ZJBR"回翔"; }

int perform(object me)
{
	string msg;
	object weapon2, target;
	int skill, ap, dp, mp, np, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (userp(me) && ! me->query("can_perform/shenlong-bashi/huixiang"))
		return notify_fail("你还不会使用「飞燕回翔」。\n");

	if (! me->is_fighting(target))
		return notify_fail("「飞燕回翔」只能对战斗中的对手使用。\n");

	skill = me->query_skill("shenlong-bashi", 1);

	if (! objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有使用兵器，不能使用「飞燕回翔」。\n");

	if (skill < 160)
		return notify_fail("你的神龙八式等级不够, 不能使用「飞燕回翔」。\n");

	if (me->query("max_neili") < 1500)
		return notify_fail("你的内力修为不足，不能使用「飞燕回翔」。\n");

	if (me->query("neili") < 500)
		return notify_fail("你的真气不够，不能使用「飞燕回翔」。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIM "突然$N" HIM "右足向前轻踢，接着顺势一勾" +
	      weapon2->name() + HIM "，轻轻在柄上一点。"NOR"\n";
	message_combatd(msg, me, target);

	ap = me->query_skill("dodge", 1) / 3 + skill;
	dp = target->query_skill("dodge", 1);
	mp = me->query_skill("hand", 1);
	np = target->query_skill("parry", 1);

	if (mp / 2 + random(mp) > np)
	{
		if (ap / 2 + random(ap) > dp)
		{
			me->add("neili", -300);
			target->receive_damage("qi", ap + random(ap), me);
			target->receive_wound("qi", ap / 2 + random(ap) / 2, me);

			msg = HIM "$N" HIM "身子向下一缩，只见白光一闪，" +
			      weapon2->name() + HIM "急射$n"
			      HIM "胸口，$n" HIM "防备不及，被" +
			      weapon2->name() + HIM "正中胸膛！"NOR"\n";
			me->start_busy(2 + random(4));
			weapon2->move(environment(me));
	   
		} else
		{
			me->add("neili", -100);
			msg = CYN "$n" CYN "眼一花，" + weapon2->name() + "脱手而"
			      "出，不过$n" CYN "不慌不忙，仰天一个铁板桥，扑的一"
			      "声，" + weapon2->name() +" 在他胸口掠过。"NOR"\n"; 
			me->start_busy(3);
			weapon2->move(environment(me));
		}
	} else
	{       
		me->add("neili", -80);
		msg = CYN "$n" CYN "眼明手快，轻轻一抹" +
		      weapon2->name() + CYN "架开了这一招。"NOR"\n"; 
		me->start_busy(1 + random(2));
	}

message_combatd(msg, me, target);
return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
