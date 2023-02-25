#include <login.h>
#include <ansi.h>


int update_condition(object me, int duration)
{
        int a,b,c;
        me->apply_condition("chunyang_jue", duration - 1);
	    
        if( duration < 1 ) 
        {
        	tell_object(me, BYEL"纯阳决的效果慢慢变弱了。"NOR"\n");
        	return 0;
        }
        
        if (me->query("qi") <= me->query("max_qi"))
        {
        me->add("eff_qi",1000+(me->query_skill("chunyang-jue",1)*10));
        me->add("qi",1000);
        }
        if (me->query("qi") <= me->query("max_qi"))
        {
        me->add("eff_qi",1000+(me->query_skill("chunyang-jue",1)*10));
        me->add("qi",1000+(me->query_skill("chunyang-jue",1)*10));
        }
        if (me->query("neili") <= me->query("max_neili"))
        {
        me->add("eff_neili",1000+(me->query_skill("chunyang-jue",1)*10));
        me->add("neili",1000+(me->query_skill("chunyang-jue",1)*10));
        }        
        if (me->query("jing") <= me->query("max_jing"))
        {
        me->add("eff_jing",1000+(me->query_skill("chunyang-jue",1)*10));
        me->add("jing",1000+(me->query_skill("chunyang-jue",1)*10));
        }
        tell_object(me,BYEL"受到纯阳决的影响，你的气血，内力，精神，有所恢复。"NOR"\n");
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
