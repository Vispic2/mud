 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "四门"ZJBR"朱雀"; }
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［四门-朱雀］只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");

        if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");

        if((int)me->query("qi")*100/(int)me->query("max_qi") > 30
                && (int)me->query("eff_qi")*100/(int)me->query("max_qi") > 30
               )
                return notify_fail("还不到使这招的时候。\n");
        extra = me->query_skill("enmeiryu",1) ;
        if(extra <= 200 ) return notify_fail("你的陆奥圆明流拳术不够熟练，还不能出四门-朱雀！\n");
        msg = HIR "$N口中喃喃说道：“只有那一招了。”，绝望中$N使出了最后的一招「四门.朱雀」!
$n一时以为自己眼花，居然看到四个$N的身影!
$n身后的一个$N猛地冲向$n，用膝部顶住$n的腰，单手揪住$n
的头，用力向地面磕去，同时肘部击向$n的眉心。" NOR;
        weapon = me->query_temp("weapon");
        extra=extra-150;
if (extra>200) extra=200;
        me->add_temp("apply/unarmed_damage",extra*10);
        me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/unarmed_damage",-extra*10);
        me->add_temp("apply/attack",-extra*4);
if (random(me->query("combat_exp",1)) >= target->query("combat_exp",1)/2)

{
	if (userp(target)) target->unconcious();
else target->start_busy(10);

message_vision(HIR"$N突然觉得胸口一阵巨痛，接着眼前一黑。 \n"NOR,target);
me->start_busy(3);
}
else
{
me->start_busy(10);
}

me->add("neili",-300);
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
