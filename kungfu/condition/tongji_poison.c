#include <ansi.h>

int update_condition(object me, int duration)
{

if (me->query("eff_qi") > 100)
	me->receive_wound("qi", me->query("eff_qi")/8);
if (me->query("qi") > 100)
	me->receive_damage("qi", me->query("qi")/8);
if (me->query("eff_jing") > 100)
	me->receive_wound("jing", me->query("eff_jing")/8);
if (me->query("jing") > 100)
	me->receive_damage("jing", me->query("jing")/8);

      me->add_temp("apply/strength",-1);
      if (me->query_str() <0)
              me->add_temp("apply/strength",1);

      me->add_temp("apply/dexerity",-1);
      if (me->query_dex() <0)
              me->add_temp("apply/dexerity",1);

    me->start_busy(6);
        me->apply_condition("tongji_poison", duration - 1);
        message_vision(WHT"$N感到身后发凉，背后好像有个批头散发混身是血的鬼魂。\n"NOR, me);
        tell_object(me, WHT "你全身一阵发抖！头昏眼花!\n" NOR );

        if( duration < 1 ) return 0;
        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
