#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "天外"ZJBR"飞仙"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 1500 )
                return notify_fail("你的真气不够！\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够！\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("feixian-sword", 1) < 240)
                return notify_fail("你的飞仙剑法等级不够，无法使用『天外飞仙』！\n");
        if((int)me->query_skill("zuoyou-hubo", 1) > 7)
        	    return notify_fail("此诀本身威力就及其大，还想配合互博之术？！\n");
 
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N飞身跃起，使出飞仙剑终极绝技「天外飞仙」!n"NOR, me);
           message_vision(HIB"\n突然只见$N使出飞仙剑终极绝技『天外飞仙』！\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N飞身跃起，使出飞仙剑终极绝技「天外飞仙」!\n"NOR,me,target);
message_vision(HBMAG"$N引剑长吟：“天！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HBMAG"$N引剑长吟：“外！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N引剑长吟：“飞！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N引剑长吟：“仙！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N乘招势未收,劲吐内力，狂风暴雨之剑气向$n卷去！\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N旧力未消,新力又生.剑法忽左忽右,飘摇四起”！\n"NOR,me,target);  
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);


           me->add("neili", -700);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


