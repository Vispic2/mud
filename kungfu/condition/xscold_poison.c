#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( !living(me) ) {
                message("vision",HIB + me->name() + "瑟瑟发抖，身上寒气四溢,全身结上一层薄薄的白霜，。\n"NOR, environment(me), me);
        }
        else {

                tell_object(me, HIB "忽然一股寒气优似冰箭，循着手臂，迅速无伦的射入胸膛，你中的雪山寒毒发作了！\n" NOR );
                message("vision", HIY + me->name() + "伤口处寒气四溢 ，嘴唇也紫了，脸色渐渐由青而白。\n"NOR,
                                environment(me), me);

        }
        me->receive_damage("qi", 150);
        if(userp(me))
        me->receive_wound("jing", 120);
        else me->receive_wound("jing", 120);
        me->start_busy(5);
        me->apply_condition("xscold_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
