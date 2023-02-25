
#include <ansi.h>

inherit F_SSERVER;
#include <combat.h>
string query_name() { return HIW"我佛"ZJBR"慈悲"NOR; }

int perform(object me, object target)
{
	int level;
	string msg;
	int ap, dp,damage;
    if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
    level = me->query_skill("rulai-shenzhang", 1);

	if (! target) 
	target = offensive_target(me);
	if (! target || ! me->is_fighting(target))
	return notify_fail("如来神掌的「我佛慈悲」只能对战斗中的对手使用。\n");
	
	if (me->query_skill("rulai-shenzhang", 1) < 300)
	return notify_fail("你的如来神掌不够娴熟，不会使用「我佛慈悲」。(需要300级)\n");

	if (me->query_skill_mapped("strike") != "rulai-shenzhang")
	return notify_fail("你必须激发如来神掌才能使用「我佛慈悲」。(需要300级)\n");
	
	if (me->query("max_neili") < 1000)
	return notify_fail("你的内力修为还不够，无法施展「我佛慈悲」。(需要1000点)\n");
	if (!living(target))
	return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "拈花而笑，轻颂一声「我佛慈悲」，手掌往$n周身大穴轻轻拂去。" "$n明明看透了$N" HIY "手掌的轨迹，却无处可避。"NOR"\n";

	
	ap = me->query_skill("strike") + me->query("str") * 22;
	dp = target->query_skill("dodge") + target->query("dex") * 10;
	damage = ap + random(ap);
	me->add("neili", -1000);
	msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 200+random(101), HBCYN+ "$p" +HBCYN+ "只见一阵旋风影中陡然现出$P"  +HBCYN +"的双掌，根本来不及躲避，被重重击中，\n五" "脏六腑翻腾不休，口中鲜血如箭般喷出！！！"NOR"\n");
	me->start_busy(1);
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
