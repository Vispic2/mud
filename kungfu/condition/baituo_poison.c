#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "baituo_poison"; }

string chinese_name() { return "白驼怪蛇粉"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + YEL"全身痉挛，不住的颤抖，全身无力，昏昏欲倒。\n"NOR, environment(me), me);
                tell_object(me, YEL "全身痉挛，不住的颤抖，全身无力，昏昏欲倒!看来是白驼怪蛇粉发作了！\n" NOR );

        me->set_temp("apply/attack", -50);
  tell_object(me,HIG"你的攻击力减低了!\n"NOR);
        me->set_temp("apply/dodge", -50);
  tell_object(me,HIG"你的躲闪力减低了!\n"NOR);
        me->set_temp("apply/defense", -50);
  tell_object(me,HIG"你的防御力减低了!\n"NOR);

        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
