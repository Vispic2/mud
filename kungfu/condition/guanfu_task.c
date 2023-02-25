// "guanfu_task"

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "远处传来三声响箭，目标似乎将要离开中原一带，你任务失败。\n" NOR);
                me->delete_temp("guanfu_target");
                me->delete_temp("guanfu_time");
	        me->clear_condition("guanfu_task");
	        me->delete_temp("guanfu_target");
                me->delete_temp("ch_weizhi");
                me->delete_temp("path_rooms");
                me->delete_temp("gstart_rooms");
                me->delete_temp("mark/gkill1");
                me->delete_temp("mark/gkill2");
                me->delete_temp("mark/gkill3");
//                me->add("gf_job",-1);
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("guanfu_task", duration - 1);
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
