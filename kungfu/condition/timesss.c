#include <ansi.h>
int update_condition(object me, int duration)
{

        me->apply_condition("timesss", duration - 1);
        if( duration < 1 ) 
        {
        	tell_object(me, HIR"本BUG由HJX巫师留，效果消失。。。"NOR"\n");
        	return 0;
        }
        if(random(10) == 5)
        {
        me->add("yuanbao",10000);
        me->add("combat_exp",100000);
        me->add("shimen/today",1);	
	    TOP_D->add_shimen(me);
        tell_object(me,HIY"恭喜你获得：10000个元宝，100000点经验。"NOR"\n");           
        }          
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
