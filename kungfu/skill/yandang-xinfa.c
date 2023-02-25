
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
//        return force == "murong-xinfa";
        return 1;
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("yandang-xinfa", 1);
                return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_learn(object me)
{

        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候还不够，还不能学习雁荡心法。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("雁荡心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"yandang-xinfa/" + func;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
