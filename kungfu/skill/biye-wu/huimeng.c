// meng.c 碧叶随风舞「回梦」

#include <ansi.h>
string query_name() { return "回梦"; }
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
object weapon;
weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「回梦」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon"))
	&& (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你必须空手才能使用「回梦」！\n");

	if( (int)me->query_skill("biye-wu", 1) < 40 )
		return notify_fail("你的碧叶随风舞不够娴熟，不会使用「回梦」。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 30 )
		return notify_fail("你的碧云心法不够高，不能用来反震伤敌。\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用「回梦」。\n");

	msg = CYN "$N默念口诀，使出碧叶随风舞之「回梦」，意欲以内力震晕$n。\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		if (!target->is_busy())
		target->start_busy(2);
		damage = (int)me->query_skill("biyun-xinfa", 1);

                damage = damage/2 + random(damage)*2+300;

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                me->add("neili", -damage/3);

		if( damage < 20 )
			msg += HIY"结果$n受到$N的内力反震，闷哼一声，看上去很是疲惫。\n"NOR;
        else if( damage < 40 )
			msg += HIY"结果$n被$N以内力反震，只觉得胸中烦闷，只想好好休息休息。\n"NOR;
        else if( damage < 80 )
			msg += RED"结果$n被$N以内力一震，脑中嗡嗡作响，意识开始模糊起来！\n"NOR;
		else
			msg += HIR"结果$n被$N的内力一震，眼前一黑，向后便倒，眼看就要不醒人事了！\n"NOR;

	}
	else
	{
			msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(2);

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
