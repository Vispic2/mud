// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "你的动作太慢,任务被取消了。\n" NOR);
         //     me->delete_temp("assigned_by");
        	 me->delete_temp("zzz_job_target");
           //              me->delete_temp("gb_job_pot");
             //            me->delete_temp("gb_job_exp");
               // me->add("gb_job",-1);
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("zzz_mission", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
