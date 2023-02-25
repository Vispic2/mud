

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
           tell_object(me, HIY "你巡城时间已过，如果四处查看完毕，可以回去覆命（task ok)了！\n" NOR);
            return 0;
        }
        if (!duration) return 0;
        me->apply_condition("wudu_xunshan2", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "job";
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
