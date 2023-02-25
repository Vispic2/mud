// zhengqijue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

//string type() { return "knowledge"; }

int practice_skill(object me)
{
        return notify_fail("正气决只能靠学(learn)来提高。\n");
}
void skill_improved(object me)
{
    tell_object(me, HIR "你心里鼓荡着一股侠义之气！\n" NOR );
    me->add("shen", 200);
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
