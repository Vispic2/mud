// wulun.c 五轮连砸

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "五轮"ZJBR"连砸"; }
string *pfm_type() { return ({ "hammer", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	int count;
 
	if (userp(me) && ! me->query("can_perform/riyue-lun/wulun"))
		return notify_fail("你还不会运用「五轮连砸」这一绝技。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「五轮连砸」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你没有合适的兵器，如何施展「五轮连砸」？\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你的真气不够，无法施展「五轮连砸」！\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，难以施展「五轮连砸」！\n");

	if ((int)me->query_skill("riyue-lun", 1) < 120)
		return notify_fail("你的日月轮法还不到家，无法使用五轮连砸！\n");

	if (me->query_skill_mapped("hammer") != "riyue-lun")
		return notify_fail("你没有激发日月轮法，无法使用「五轮连砸」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "嗔目大喝，手中的" + weapon->name() +
		      HIM "使得犹如数道闪光，飞也似的盘旋压向$n" HIM "！"NOR"\n";
		break;

	case 1:
		msg = HIM "$N" HIM "微微冷笑，跨上一步，将手中的" + weapon->name() +
		      HIM "运转如飞，数道光芒一起压向$n" HIM "！"NOR"\n";
		break;

	default:
		msg = HIM "$N" HIM "扬声吐气，一声大喝，将手中的" + weapon->name() +
		      HIM "飞掷而出，去向飘忽不定！\n只见那" + weapon->name() +
		      HIM "似要在落空，$P" HIM "赶上前去一拨，" + weapon->name() +
		      HIM "却又变了一个方位，盘旋飞向$n" HIM "。"NOR"\n";
		break;
	}

	message_combatd(msg, me, target);
	me->add("neili", -100);

	count = me->query_skill("hammer") / 9;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(5));
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
