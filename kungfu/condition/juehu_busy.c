#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
            return 0;
        }
        if (!duration) return 0;
        me->apply_condition("juehu_busy", duration - 1);
        return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
