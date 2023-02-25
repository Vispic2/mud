// lingjiu-xinfa.c 灵鹫心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force) { return force == "bahuang-gong"; }

int valid_learn(object me)
{
	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("灵鹫心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"lingjiu-xinfa/" + func;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
