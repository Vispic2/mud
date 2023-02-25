// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "wuhudu_poison"; }

string chinese_name() { return "五虎奇毒"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIY"五种奇毒攻心，手按胸口，面色泛黑，痛苦万分。\n"NOR, environment(me), me);
                tell_object(me, HIY "你忽觉心口疼痛万分，犹如万千虫蚁噬心穿骨！\n" NOR );
if (random(3)==0 && (int)me->query("qi")< 100000)
{
        me->receive_wound("jing", me->query("jing")/8);
        me->receive_damage("jing", me->query("jing")/8);
tell_object(me,HIG"你的精力减低了!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->receive_wound("qi", me->query("qi")/8);
        me->receive_damage("qi", me->query("qi")/8);
tell_object(me,HIG"你的气血减低了!\n"NOR);
}
if (random(3)==0 && (int)me->query("max_neili") > 100)        
{
        me->add("max_neili", -60);
  tell_object(me,HIG"你的内力减低了!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->add("neili", -me->query("neili")/7);
  tell_object(me,HIG"你的内力减低了!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->set_temp("apply/attack", -80);
  tell_object(me,HIG"你的攻击力减低了!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->set_temp("apply/defense", -80);
  tell_object(me,HIG"你的防御力减低了!\n"NOR);
}
        //if (!me->is_busy())
        me->start_busy(6);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
