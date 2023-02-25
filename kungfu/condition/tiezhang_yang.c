#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tiezhang_yang"; }

string chinese_name() { return "铁掌纯阳劲"; }



int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + RED"闷哼一声，双目凸出，嘴角渗出几丝鲜血。\n"NOR, environment(me), me);
                tell_object(me, RED "你只觉丹田处有如火焚，便似有千万钢针一齐扎入体内。！\n" NOR );
me->add("neili",-me->query("neili")/4);
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
