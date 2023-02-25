inherit SKILL;

int valid_learn(object me)
{
        object ob;

        if( me->query("max_neili")<500 )
                return notify_fail("你的内力不够，没有办法练含沙射影。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够，没有办法练含沙射影。\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("hansha-sheying", 1))
                return notify_fail("你的基本暗器水平有限，无法领会更高深的含沙射影。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "throwing";
}

int practice_skill(object me)
{
        if( me->query("qi")<40 )
                return notify_fail("你的气不够，没有办法练习含沙射影。\n");

        if( me->query("neili")<50 )
                return notify_fail("你的内力不够，没有办法练习含沙射影。\n");

        me->receive_damage("qi", 35);
        me->add("neili", -48);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hansha-sheying/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
