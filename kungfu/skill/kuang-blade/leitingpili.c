// tie@fengyun
string query_name() { return "雷霆"ZJBR"霹雳"; }
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        if( (int)me->query_skill("kuang-blade",1) < 50)
        return notify_fail("你目前功力还使不出「雷霆霹雳」。\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 200 )
    return notify_fail("你的内力不够。\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［雷霆霹雳］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("kuang-blade",1) / 2;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIY  "$N手中的"+ weapon->name() +"幻出漫天刀云，"+weapon->name() +"划破刀云，千军万马般的击向$n！" NOR;
if( (int)me->query_skill("kuang-blade",1) > 300)
{
if (!target->is_busy()) target->start_busy(1);
if (random(8)==0) target->start_busy(3);
}
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
me->add("neili", -60);
	me->start_busy(2);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
