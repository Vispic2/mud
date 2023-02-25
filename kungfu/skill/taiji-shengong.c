// taiji-shengong.c 太极神功
// By Xiang
// Modified by Hop

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "hunyuan-yiqi" ||
	       force == "yijinjing" ||
	       force == "wudang-xinfa" ||
	       force == "shaolin-xinfa";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("taiji-shengong", 1);
	return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_learn(object me)
{
	if (me->query("gender") == "无性" && (int)me->query_skill("taiji-shengon", 1) > 19)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的基本内功火候还不够。\n");

	if ((int)me->query_skill("taoism", 1) < 100)
		return notify_fail("你对道家心法领悟的太浅，无法理解太极神功。\n");

	if ((int)me->query_skill("taoism", 1) < 500 &&
	    (int)me->query_skill("taoism", 1) <(int)me->query_skill("taiji-shengong", 1))
		return notify_fail("你对道家心法领悟的有限，无法理解更高深太极神功。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
