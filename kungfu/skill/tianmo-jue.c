// tianmojue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{
    return notify_fail("天魔诀只能靠学(study)来提高。\n");
}

void skill_improved(object me)
{
    int sklv = me->query_skill("tianmo-jue", 1);
    tell_object(me, HIR "你感觉自己内心充满了杀戮的欲望！\n" NOR );
    me->add("shen", -(sklv * sklv));
}

int valid_learn(object me)
{
    return ::valid_learn(me);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
