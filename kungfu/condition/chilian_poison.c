//Cracked by Kafei
//May 10th Modified by haowen to enforce poison
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "忽然一阵晕旋使你急欲作呕，你中的赤炼掌毒发作了！\n" NOR );
if (environment(me) && me)
{
      message("vision", me->name() + "头重脚轻，身子突然晃了两晃。\n",
            environment(me), me);
}
   }
      me->receive_damage("qi", random(me->query("qi"))/5+80);
      me->receive_damage("jing", random(me->query("jing"))/5+80);
      me->apply_condition("chilian_poison", duration - 1);
	
   if( duration == 1) me->delete("poisoner");

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
