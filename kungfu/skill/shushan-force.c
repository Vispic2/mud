// huntian-qigong.c   混天气功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)
{
	int lvl;
        lvl = (int)me->query_skill("shushan-force", 1);
        return lvl / 10 * lvl / 10 * 15 * 28 / 10 / 20;
}

int valid_learn(object me)
{
        int level;
        
        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以领会高深的蜀山"
                                   "心法。\n");

        if( me->query("int")<30 )
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if( me->query("dex")<30 )
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

        if( me->query("con")<30 )
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");

        if( me->query("str")<30 )
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

        level = me->query_skill("shushan-force", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("你觉得蜀山心法过于深奥，以自己的武学修养"
                                   "全然无法明白。\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的基本内功修为不足，难以运转蜀山心法。\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续领会更"
        
                           "高深的蜀山心法。\n");
return ::valid_learn(me);
        
}

int practice_skill(object me)
{
	    return notify_fail("蜀山心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"shushan-force/" + func;
}
