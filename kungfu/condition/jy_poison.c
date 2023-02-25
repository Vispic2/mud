#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的九阴白骨爪毒发作了！\n" NOR );
if (environment(me) &&  me)
{
      message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
            environment(me), me);
}
   }
      me->receive_wound("qi",10 + random(40));
      me->receive_wound("jing", 10);
      me->start_busy(2);
      me->apply_condition("jy_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
