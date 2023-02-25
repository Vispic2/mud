// wu.c 群魔乱舞

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "群魔"ZJBR"乱武"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int lvl;
	int i;
 int sss;
 sss=me->query("khmg")*50;
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("群魔乱舞只能对战斗中的对手使用。。\n");
 
	if (me->query("neili")  < (500+sss))
		return notify_fail("你的真气不够"+(500+sss)+"点，无法施展群魔乱舞！\n");

	if ((lvl = me->query_skill("kuihua-mogong", 1)) < 180)
		return notify_fail("你的葵花魔功火候不够，无法施展群魔乱舞！不足180级\n");

	if (weapon = me->query_temp("weapon"))
	{
		if (weapon->query("skill_type") != "sword" &&
		    weapon->query("skill_type") != "pin")
			return notify_fail("你手里拿的不是剑，怎么施"
					   "展群魔乱舞？\n");
	} else
	{
		if (sizeof(me->query_skill_prepare()) &&
		    me->query_skill_prepared("finger") != "kuihua-mogong" &&
		    me->query_skill_prepared("unarmed") != "kuihua-mogong")
			return notify_fail("你并没有准备使用葵"
					   "花魔功，如何施展群魔乱舞？\n");
	}

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "默运葵花魔功，身形变得奇快无比，接连向$n"HIR "攻出数招！"NOR"\n";
	
	if(me->query("khmg") >= 1)
	{
	i=9;
	msg += HIR "$n" HIR "只觉得眼前一花，发现四周都是$N"HIR "的身影，不由暗生惧意，接连后退。"NOR"\n";
	count = me->query_skill("kuihua-mogong", 1) / 10;
	me->add_temp("apply/attack", count);
	i += me->query("khmg");
	}
	else
	{
	i = 6;
	if (lvl / 2 + random(lvl) > (int)target->query_skill("dodge", 1))
	{
		msg += HIR "$n" HIR "只觉得眼前一花，发现四周都是$N"HIR "的身影，不由暗生惧意，接连后退。"NOR"\n";
		count = me->query_skill("kuihua-mogong", 1) / 7;
		me->add_temp("apply/attack", count);
		i += random(7);
	} else
	{
		msg += CYN "$n" CYN "见$N" CYN "身法好快，哪里"
		       "敢怠慢，连忙打起精神小心应对。"NOR"\n";
		count = 0;
	}
	}

	message_combatd(msg, me, target);
	if(me->query("khmg") >= 10)
	{
	me->add("neili", -i * 10);
	}else
	{
	me->add("neili", -i * 20);
	}
if(me->query("khmg") >= 5)
{
	while (i--)
	{
		if (! me->is_fighting(target))
			break;
		if (i > 10 && ! target->is_busy())
		target->start_busy(me->query("khmg"));
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
}
else
{
	while (i--)
	{
		if (! me->is_fighting(target))
			break;
		if (i > 10 && ! target->is_busy())
		target->start_busy(1);
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
	
}
	me->add_temp("apply/attack", -count);
	if(me->query("khmg") >= 5)
	{
	me->start_busy(1+random(2));
	}
	else
	{
	me->start_busy(1 + random(5));
	}
	return 1;
}
//首次进阶技能 [群魔乱舞]必定连续攻击10次，后续每进阶一次加一连。
//进阶次数大于等于5次消耗内力等于攻击次数*10，否则次数*20。
//进阶次数大于等于5次大概率busy对方，busy时间等于进阶次数。
//进阶次数大于等于5次自busy固定1秒。

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
