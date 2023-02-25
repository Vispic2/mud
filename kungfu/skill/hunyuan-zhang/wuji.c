// wuji.c 混元无极
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "混元"ZJBR"无极"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「混元无极」只能对战斗中的对手使用。\n");
 
	skill = me->query_skill("hunyuan-zhang", 1);
	if (skill < 60)
		return notify_fail("你的「混元掌」等级不够, 不能使用「混元无极」！\n");

	if (me->query("neili") < 150)
		return notify_fail("你的内力不够，无法运用「混元无极」！\n");
 
	if (me->query_skill_mapped("strike") != "hunyuan-zhang")
		return notify_fail("你没有激发混元掌，不能使用「混元无极」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "潜运「混元无极」，双拳挟着隐隐的风雷之声向$n"
	      HIC "击去。"NOR"\n";
 
	ap = me->query_skill("strike");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -140);
		damage = 100 + random(skill);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
					   HIR "$n" HIR "只觉得胸前一阵剧痛，“哇”的一"
					   "声喷出一口鲜血！"NOR"\n");
		me->start_busy(1 + random(2));
	} else
	{
		me->add("neili", -30);
		msg += CYN "只见$n" CYN "不慌不忙，轻轻一闪，躲过"
		       "了$N" CYN "的必杀一击！"NOR"\n";
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
