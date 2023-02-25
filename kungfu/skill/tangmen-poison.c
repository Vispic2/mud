// xingxiu-qishu.c

inherit SKILL;

//string type() { return "knowledge"; }

int valid_enable(string usage)
{
        return usage == "poison";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 50)
                return notify_fail("你的基本毒技造诣太浅，无"
                                   "法领会深奥的唐门奇毒。\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("tangmen-poison", 1))
                return notify_fail("你的基本毒技水平有限，无"
                                   "法掌握更深奥的唐门奇毒。\n");

        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
