//by system_2
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("「醉」字决只能对战斗中的对手使用。\n");
if ( (string)me->query("family/family_name") != "逍遥派") 
     return notify_fail("只有逍遥弟子才能使用该PFM。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
    if( (int)me->query("neili") < 1200 )
        return notify_fail("你的真气不够！\n");
                if(me->query_skill_mapped("dodge") != "lingbo-weibu") 
               return notify_fail("你的凌波微步没激发在轻功上吧? \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经忙不得了！\n");
                
        if( (int)me->query_skill("zuixin-sword", 1) < 200 )
                return notify_fail("你还没得到逍遥醉心剑的精髓，使不出「醉」字决。\n");

    msg = HIM "$N身形飘渺，以手中剑器舞出一套「醉」字决剑法，将$n耍的头晕眼花。\n";

if( random( me->query_skill("zuixin-sword",1)+me->query_skill("sword",1) ) > (me->query_skill("unarmed",1)*2)/3 ) {
   msg += HIB "$p看着迷幻的剑光在周围闪烁，竟已痴醉。\n" NOR;
             target->start_busy( (int)me->query("jym_level/level") /2 + 1);
   me->add("neili", -1000);
        } else {
        me->start_busy(2);
           me->add("neili",-800);        
                msg += HIY "$p定住心神，以一股内力压下心中邪意。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

