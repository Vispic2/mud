#include <login.h>
#include <ansi.h>


int update_condition(object me, int duration)
{
 int a,b,c;

        me->apply_condition("ahuifu_jing_3", duration - 1);
	    
        if( duration < 1 ) 
        {
        	tell_object(me, HIR"持续恢复精力的药效逐渐消失。。"NOR"\n");
        	return 0;
        }
        
        if (me->query("jing") <= me->query("max_jing"))
        {
        me->add("eff_jing",2000);
        me->add("jing",2000);
        tell_object(me,HIR"受药效影响你的精力恢复2000点"NOR"\n");
        }else
        {
        tell_object(me,HIR"受药效影响你的精力恢复2000点，但由于你现在精力充足所以没有任何效果。"NOR"\n");
        }
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
