// jiuyang-shengong.c 九阳神功
// cleansword
// Modified by Venus Oct.1997
// Updated by Doing Lu for Hell

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("jiuyang-force", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang-force", 1);

	if (me->query("gender") == "无性" && (int)me->query_skill("jiuyang-force", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");

	if ((int)me->query_skill("force", 1) < 1)
		return notify_fail("你的基本内功火候还不够，还不能学习九阳神功。\n");

        if (me->query("int") < 1)
                return notify_fail("你觉得九阳神功过于艰深，难以理解。\n");

        if (me->query("con") < 1)
                return notify_fail("你的根骨不好，难以运转九阳神功。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("九阳神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-force/" + func;
}

