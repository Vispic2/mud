// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "十万"ZJBR"神魔"; }
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
        extra = me->query_skill("ittouryu",1);

        if ( extra < 50) return notify_fail("你的［一刀流剑术］还不够纯熟！\n");
		if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［十万神魔］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = MAG  "$N凝聚起天地间十万妖魔的无边力量，一式－十－万－神－魔 －如急电般劈向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N手中"+ weapon->name()+  "幻出奇异的光华刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N手中"+ weapon->name()+  "发出摄人心魄的呼啸向$n劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "$N手中"+ weapon->name()+  "竟然发出妙不可言的奇香扑向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC  "十万诸魔齐在云端隐现，$N手中"+ weapon->name()+  "鬼神莫测已然到了$n的眼前！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->start_busy(2);
me->add("neili",-100);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
