// libie.c 离别

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>


inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{
        mapping exits;
        string *dirs;
        //duration--;
        //if( duration < 0 )      return 0; 
        me->receive_wound("jing", 60);
        if(mapp(exits = environment(me)->query("exits"))) { 
                dirs = keys(exits);
                tell_object(me, WHT"你心中忽然涌起莫名伤感，只觉悲苦凄凉，茫然不知何往。\n"NOR); 
                message("vision", me->name() + "面容凄苦，失神一般漫无目的地乱走。\n", 
                        environment(me), me); 
if (userp(me))                
{
               GO_CMD->do_flee(me);
}
else
{
me->start_busy(6);
}
        }
      me->apply_condition("libie", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}    

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
