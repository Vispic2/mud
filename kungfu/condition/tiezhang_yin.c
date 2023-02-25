#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tiezhang_yin"; }

string chinese_name() { return "铁掌阴寒劲"; }


int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIB"面色惨白，嘴皮乌紫，冷不丁打了一个寒战。\n"NOR, environment(me), me);
                tell_object(me, HIB "你感到胸口处传来阵阵刺痛，全身血液竟似要凝结住一般\n" NOR );
me->add("qi",-me->query("qi")/7);
        if (!me->is_busy())
        me->start_busy(3);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
