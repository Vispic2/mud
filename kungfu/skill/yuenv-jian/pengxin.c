// pengxin.c 西子捧心

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "西子"ZJBR"捧心"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
	int delta;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「西子捧心」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (userp(me) && ! me->query("can_perform/yuenv-jian/pengxin"))
		return notify_fail("你不会使用「西子捧心」这一绝技！\n");

	if (me->query_dex() < 35)
		return notify_fail("你的身法不够，目前还不能使用这项绝技！\n");

	if (me->query_skill("sword", 1) < 100)
		return notify_fail("你的剑术修为不够，目前不能使用「西子捧心」！\n");

	if (me->query_skill("yuenv-jian", 1) < 100)
		return notify_fail("你的越女剑术的修为不够，不能使用这一绝技！\n");

	if (me->query_skill("dodge") < 150)
		return notify_fail("你的轻功修为不够，无法使用「西子捧心」！\n");
 
	if (me->query("neili") < 200)
		return notify_fail("你的真气不够！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (me->query("gender") == "女性" &&
	    target->query("gender") == "女性")
		delta = target->query("per") - me->query("per");
	else
		delta = 0;

	msg = HIG "$N" HIG "幽幽一声长叹，手中的" + weapon->name() +
	      HIG "就如闪电般刺向$n的胸口。"NOR"\n";
	if (delta > 0)
		msg += HIY "$n" HIY "只觉得$N" HIY "眼神中隐然透出"
		       "一股冰冷的寒意，心中不禁一颤。"NOR"\n";
	else
		delta = 0;

	me->add("neili", -150);
	ap = (me->query_skill("sword") + me->query_skill("dodge")) / 2;
	dp = target->query_skill("dodge");
	me->start_busy(1);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2) + delta * 50;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
					   HIR "$n" HIR "大吃一惊，慌忙躲避，然而剑"
					   "气来的好快，哪里躲得开？\n只听$p" HIR
					   "一声惨叫，胸口已经被剑气所伤！"NOR"\n");
		if (objectp(weapon = me->query_temp("weapon")) &&
		    ap / 4 + random(ap) > dp)
		{
			damage /= 2;
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 100,
						   HIC "$n重创之下不禁破绽迭出，$P"
						   HIC "见状随手刺出" + weapon->name() +
						   HIC "，又是一剑！\n" HIR "就听$p"
						   HIR "又是一声惨叫，痛苦不堪。"NOR"\n");
		}
	} else
	{
		msg += HIC "$n" HIC "见状身形急退，避开了$N"
		       HIC "的无形剑气的凌厉一击！"NOR"\n";
	}

	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
