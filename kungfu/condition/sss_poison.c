// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + HIG"凄惨地哼了一声。\n", environment(me), me);
   }
   else {
      message("vision", me->name() + "八荒气劲内伤发作，样子显然十分难受。\n",
            environment(me), me);
   }
      me->receive_wound("qi",500 + random(200));
	  me->receive_damage("qi", 300 + random(200));
      me->receive_wound("jing", 20 + random(100));
      me->apply_condition("sss_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
