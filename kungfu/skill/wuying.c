// suodi.c 飞天御剑流.抄刃止刃

#include <ansi.h>
string query_name() { return "无影脚"; }

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;
int extra;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("无影脚只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「无影脚」开始时不能拿着兵器！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("你的碧波神功不够！\n");

	if( (int)me->query_skill("luoying-zhang",1) < 100 ||
	    me->query_skill("xuanfeng-leg",1) < 100)
		return notify_fail("你的腿掌功夫还不到家，无法使用无影脚！\n");
        if (me->query_skill_mapped("unarmed") != "xuanfeng-leg")
                return notify_fail("你没有激发旋风扫叶腿，难以施展。\n");
	if( (int)me->query("neili") < 200  )
		return notify_fail("你的内力不够。\n");

	extra = me->query_skill("xuanfeng-leg",1) / 10;
	extra += me->query_skill("luoying-zhang",1) /20;
         attack_time = (int)me->query_skill("xuanfeng-leg", 1) / 30;
        if (attack_time< 2)attack_time=2;
        if (attack_time> 12)attack_time=12;
        msg = HIC "$N高高跃起，双腿连环，无影无踪。\n";
if (!target->is_busy() && random(6)==0 ) target->start_busy(2);
        message_combatd(msg, me, target);

        for(i = 0; i < attack_time; i++){
         msg =  HIC "第"+chinese_number(i+1)+"脚!" NOR;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra*2);
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
                                        }
	me->add("neili", - 20*i);
        me->start_busy(2);
        return 1;
}

