// lingxiao.c 天罡指穴法 「凌空指穴」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "凌空"ZJBR"指穴"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("凌空指穴绝技只能对战斗中的对手使用。\n");

	if ((int)me->query_dex() < 28)
		return notify_fail("你身法不够，不能使用这一绝技！\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你内功火候不够，还不能使用凌空指穴！\n");

	if ((int)me->query_skill("finger") < 100)
		return notify_fail("你的指法修为不够，目前还不能使用凌空指穴绝技！\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气现在不够，不能使用凌空指穴！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if (me->query_skill_mapped("finger") != "tiangang-zhi")
		return notify_fail("你没有激发天罡指穴法，不能施展「凌空指穴」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出天罡指穴法绝技「凌空指穴」，左手"
	      "食中二指向$n" HIY "接连戳去，一连七指，全是对向$n"
	      HIY "的胸前大穴。\n";
	ap = me->query_skill("finger");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIG "结果$p" HIG "不及攻敌，拼力躲避$P"
		       HIG "指力顿时动作大乱！"NOR"\n";
		target->start_busy((int)me->query_skill("tiangang-zhi", 1) / 22 + 2);
		me->add("neili", -100);
	} else
	{
		msg += CYN "$p" CYN "情急智生，奋力一跃，退出老远。"NOR"\n";
		me->start_busy(3);
		me->add("neili", -30);
	}
	message_combatd(msg, me, target);

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
