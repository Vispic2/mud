// This program is a part of NITAN MudLIB

inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
       if( me->query_skill("tiandao-shengong",1))
                return notify_fail("你不散了天道神功，无法专心研习蚩尤狂战决。\n");
            return ::valid_learn(me);
}

int practice_skill(object me)
{
            return notify_fail("蚩尤狂战决只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
            return __DIR__"chiyou-kuangzhanjue/" + func;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
