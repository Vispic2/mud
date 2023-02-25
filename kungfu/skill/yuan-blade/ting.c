//Cracked by Roath

//Ansi 99.12
#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "小楼一夜"ZJBR"听春雨"; }
int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「小楼一夜听春雨」？\n");
       
       if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");

        if(!me->is_fighting())
                return notify_fail("「小楼一夜听春雨」只能在战斗中使用！\n");
        
        // if(me->query("family/family_name")!="魔教")
        //         return notify_fail("不是魔教的不能用「小楼一夜听春雨」！\n");
        
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                        return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("yuan-blade", 1) < 200)
                return notify_fail("你的圆月弯刀修为还不够，使用这一招会有困难！\n");

        if (me->query_skill_mapped("blade") != "yuan-blade")
                return notify_fail("你还没有激发圆月弯刀呢。\n");

       if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");
       
        weapon = me->query_temp("weapon");
     //   if (me->query_skill("yuan-blade", 1) &&
        //    (! objectp(weapon) || weapon->query("id") != "yuan blade"))
           //     return notify_fail("你没有圆月弯刀在手怎么能使出 [小楼一夜听春雨]? \n");


        msg = HBRED "小楼一夜听春雨：圆月落，刀光起。纵横大地十万里。刀光寒如雪，何处听春雨？\n" NOR
              HIY "只听唰的一声，" + weapon->name() + HIY "出手了！一切只能以一个快字去形容，发生在肉眼难看清楚的高速下，\n"
              "$N" HIY "这一刀劈出时，好像也是直直的，但是这笔直劈出来的一刀，竟忽然闪起了一道弯弯的刀光。\n"
              "弯弯的刀，弯弯的刀光，开始时宛如一弯新月，忽然间就变成了一道飞虹。这一道弯弯的刀光闪起时，\n"
              + weapon->name() + HIY "上的妖异之气，使人为之震眩迷惑。\n" NOR;       
        ap = me->query_skill("blade");
        ap = ap;
        dp = target->query_skill("dodge");
	  if (random(ap) / 2 + random(ap) > dp) {
                damage = me->query_skill("blade") * 20 + me->query("jiali");
                if (damage > 5000) damage = target->query("max_qi")/2;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/3);
     target->start_busy(random(4)+2);
                msg += HIR "当$n" HIR "感到$N" HIR "出手时，" + weapon->name() + HIR "早已挥出，化作满月时的月光，划过两丈的虚空劈向$n。\n"
                               "$n" HIR "只感到周遭所有的气流和生气都似被$N" HIR "这惊天动地的一招吸个一丝不剩，一派生机尽绝，\n"
                               "死亡和肃杀的骇人味儿。只听得轻轻的一声响，那道弯弯的刀光却还在，又弯弯地一转。然后美如月光的刀气消失了，\n"
                               "所有的声音都沉寂，所有的动作都停顿。$N" HIR "还是像一瞬前那么样静静地站在那里，好像根本没有动过。可是$N" 
                               HIR "手里的" + weapon->name() + HIR "已经在滴着血。\n" NOR;

        }
        
        else 
                msg += CYN "可是$p" CYN "识破了$P"
                       CYN "这一招，斜斜一跃避开。\n" NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
   
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("neili",-80-me->query("jiali"));
        me->start_busy(3);
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
