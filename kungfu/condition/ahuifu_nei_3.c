#include <login.h>
#include <ansi.h>


int update_condition(object me, int duration)
{
 int a,b,c;

        me->apply_condition("ahuifu_nei_3", duration - 1);
	    
        if( duration < 1 ) 
        {
        	tell_object(me, HIR"持续恢复内力的药效逐渐消失。。"NOR"\n");
        	return 0;
        }
        
        if (me->query("neili") <= me->query("max_neili"))
        {
        me->add("eff_neili",2000);
        me->add("neili",2000);
        tell_object(me,HIR"受药效影响你的内力恢复2000点"NOR"\n");
        }else
        {
        tell_object(me,HIR"受药效影响你的内力恢复2000点，但由于你现在内力充足所以没有任何效果。"NOR"\n");
        }
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
