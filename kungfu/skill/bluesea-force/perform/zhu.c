// zhu.c 诛仙决
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;

string query_name() { return "诛仙诀"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("诛仙决只能对战斗中的对手使用。\n");
 
	if (me->query_skill("bluesea-force", 1) < 120)
		return notify_fail("你的南海玄功还不够娴熟，不能使用诛仙决！\n");

	if (me->query("neili") < 200)
		return notify_fail("你的内力不够，不能使用诛仙决！\n");
 
       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "随手拍出一掌，疾若奔马，如箭一般飞向$n"
	      HIC "速度快的不可思议！"NOR"\n";
 
	ap = me->query_skill("bluesea-force", 1) * 4 / 2 + me->query("con") * 20 +
	     me->query_skill("martial-cognize", 1);
	dp = target->query_skill("parry") + target->query("int") * 30 +
	     target->query_skill("martial-cognize", 1);

	me->start_busy(2);
	me->add("neili", -50);
	if (ap / 2 + random(ap) < dp)
	{
		msg += HIG "然而$n" HIG "看破了$N" HIG
		       "的掌势，不慌不忙的躲过了这一击！"NOR"\n";
	} else
	{
		me->add("neili",-75);
		damage = ap / 2 + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
					   HIR "$n" HIR "正在思虑这一掌的后势，掌力已至"
					   "胸前，只听“噗”的一声，$n吐血三尺！"NOR"\n");
	}

	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
