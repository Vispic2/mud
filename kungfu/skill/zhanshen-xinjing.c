inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
        return force == "tianchi-neigong" ||
               force == "honghua-xinfa" ;
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("zhanshen-xinjing", 1);
    if (me->query("family/family_name") == "红花会")
        return lvl * lvl * 15 * 20 / 100 / 200;
    else
        return lvl * lvl * 15 * 15 / 100 / 200;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的基本内功火候还不够。\n");

        if (me->query("gender") == "无性" && (int)me->query_skill("zhanshen-xinjing", 1) > 19)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的战神心经。\n");

        //if (me->query("con") < 30)
        if (me->query("con") < 25)
                return notify_fail("你先天根骨孱弱，无法学习战神心经。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("战神心经只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhanshen-xinjing/" + func;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
