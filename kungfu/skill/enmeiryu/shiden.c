 //mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "紫电"ZJBR"四连脚"; }
int begin_perform(object me,object target,int count,int extra);
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("enmeiryu",1);
        if(extra<100) return notify_fail("你陆奥圆明流拳术的修为不够，无法使出紫电四连脚的绝招。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("紫电四连脚只能对战斗中的对手使用。\n");
        extra = me->query_skill("enmeiryu",1) / 3;
        message_vision(HIY"$N突然一笑，右手在$n的眼前一晃，跃向另一侧。$n一时无法看清$N的身影。
「紫电四连脚！」 \n",me,target);
        begin_perform(me,target,4,extra);
        me->add("neili",-100);
        return 1;

}
string *perform_msg=({
        HIY"$N单手在地上一撑，身体不可思议地再次弹起，双脚蹬向$n的膝关节。\n"NOR,
        HIY"$N借着下落之势，再次转身，脚以迅雷不及掩耳之势，扫向$n的颈部。\n"NOR,
        HIY"$N高高跃起，空中一个拧腰，居然以脚作刀猛地自$n的头顶斩了下来。\n"NOR,
        HIY"$N猛地从侧面跃向$n，趁着$n不知所措之时，一个高踢踹向$n的面门。\n"NOR,
        });
int begin_perform(object me,object target,int count,int extra)
{
        string msg;
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target)
        ||environment(target)!=environment(me)          )
                return 0;
if (random(2)==0)                 target->start_busy(3);
        if(count)
        {
                msg=perform_msg[--count];
//         me->stop_busy();
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/unarmed_damage", extra);

                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/unarmed_damage", -extra);
                begin_perform(me,target,count,extra);
        }
        else
                me->start_busy(3);
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
