#include <ansi.h>
// 明教 guangming-jing
inherit SKILL; 

int is_fmsk() { return 1; }
string family_name() { return "明教"; }

int valid_learn(object me)
{
        if (me->query_skill("jiuyang-shengong", 1) < 120)
                return notify_fail("你九阳神功火候不足，无法研习大云光明经。\n");

        if( me->query("family/family_name") != family_name() )
                return notify_fail("大云光明经只能明教弟子方可研习。\n");

        if (me->query_skill("qiankun-danuoyi", 1) < 150)
                return notify_fail("你乾坤大挪移修为不足，无法继续研习大云光明经。\n");

        return 1;
}

int difficult_level()
{
        return 2000;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
