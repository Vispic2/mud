// yi.c 剑意

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "独孤"ZJBR"剑意"; }
string *pfm_type() { return ({ "sword", }); }
//int query_cd() { return 3; }
int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手使用绝招。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("无剑如何运用剑意？\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你现在的真气不够，无法使用剑意！\n");

	if ((int)me->query_skill("lonely-sword", 1) < 120)
		return notify_fail("你的独孤九剑还不到家，无法使用剑意！\n");

	if (me->query_skill_mapped("sword") != "lonely-sword") 
		return notify_fail("你没有激发独孤九剑，无法使用剑意！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "一剑刺出，连自已也不知道要刺往何处。"NOR"\n";
		break;

	case 1:
		msg = HIM "$N" HIM "随手挥洒手中的" + weapon->name() +
		       HIM "，漫无目的，不成任何招式。"NOR"\n";
		break;

	default:
		msg = HIM "$N" HIM "斜斜刺出一剑，准头之差，令人匪夷所思。"NOR"\n";
		break;
	}

	ap = me->query_skill("lonely-sword", 1) + me->query_skill("martial-cognize", 1) / 2;
	dp = target->query_skill("parry", 1) + target->query_skill("martial-cognize", 1) / 2 +
	     target->query_skill("lonely-sword", 1);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap * 3 + random(ap);
		me->add("neili", -180);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
					   HIR "$n" HIR "全然无法领会$P"
					   HIR "这莫名其妙的招数，一个疏神，登时受创！"NOR"\n");
			if(me->query("lonely-sword_zj")){
	if(random(3)){
		me->start_busy(1);
    }
	}else
	{
	me->start_busy(2);
	}
	} else
	if (target->query_skill("martial-cognize", 1) + target->query_skill("lonely-sword", 1) > 150)
	{
		msg += CYN "然而$n" CYN "深通其中奥妙，见招拆招，让$N"
		       CYN "的攻击全然不能发挥作用。\n";
		me->add("neili", -80);
		if(me->query("lonely-sword_zj")){
	if(random(3)){
		me->start_busy(1);
    }
	}else
	{
	me->start_busy(2);
	}
		
		
		
	} else
	{
		msg += CYN "$n" CYN "淡然处之，并没有将$P"
		       CYN "此招放在心上，随手架开，不漏半点破绽。"NOR"\n";
		me->add("neili", -60);
		
		
		

	
	
	if(me->query("lonely-sword_zj")){
	if(random(3)){
		me->start_busy(1);
    }
	}else
	{
	me->start_busy(2);
	}
	
	}
	
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
