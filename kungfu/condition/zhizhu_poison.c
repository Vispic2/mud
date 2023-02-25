// zhizhu_poison.c
// by star  98.12.4
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;
       
	me->receive_wound("qi", 15+random(50));
	me->receive_damage("jing", 15+random(40));
        me->start_busy(random(3));
	me->apply_condition("zhizhu_poison", duration - 1);
//       if(environment(me)==find_object("/d/city/wumiao") 
//        ||environment(me)==find_object("/d/city/wujiaochang"))
//	me->apply_condition("zhizhu_poison", duration);
	tell_object(me, HIG "你中的蜘蛛毒发作了！\n" NOR );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
