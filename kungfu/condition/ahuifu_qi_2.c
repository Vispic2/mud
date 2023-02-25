#include <login.h>
#include <ansi.h>


int update_condition(object me, int duration)
{
 int a,b,c;

        me->apply_condition("ahuifu_qi_2", duration - 1);
	    
        if( duration < 1 ) 
        {
        	tell_object(me, HIR"持续恢复气血的药效逐渐消失。。"NOR"\n");
        	return 0;
        }
        
        if (me->query("qi") <= me->query("max_qi"))
        {
        me->add("eff_qi",1000);
        me->add("qi",1000);
        tell_object(me,HIR"受药效影响你的气血恢复1000点"NOR"\n");
        }else
        {
        tell_object(me,HIR"受药效影响你的气血恢复1000点，但由于你现在气血充足所以没有任何效果。"NOR"\n");
        }
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
