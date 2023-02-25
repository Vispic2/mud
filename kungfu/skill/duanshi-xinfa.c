// duanshi-xinfa.c 段氏心法
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "xiantian-qigong" ||
	       force == "quanzhen-xinfa"  ||
	       force == "kurong-changong";
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("duanshi-xinfa", 1);
    return lvl * lvl * 15 * 10 / 100 / 200;
}

int valid_learn(object me)
{
    	if (me->query("gender") == "无性" &&
	    (int)me->query_skill("duanshi-xinfa") > 49)
    		    return notify_fail("你无根无性，阴阳不调，难以领会高深的段氏心法。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("段氏心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"duanshi-xinfa/" + func;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
