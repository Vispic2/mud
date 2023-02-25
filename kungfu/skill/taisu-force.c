// taisu-force.c 太素心经
// cleansword
// Modified by Venus Oct.1997
// Updated by Doing Lu for Hell

inherit FORCE;string name() { return HIR "古月太素" NOR; } 

int valid_enable(string usage)
{
	return usage == "force";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("taisu-force", 1);
	return lvl * lvl * 15 * 22 / 100 / 200;
}

int valid_force(string force)
{
	return 1;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("taisu-force", 1);

	if (me->query("gender") == "男性" && me->query("gender")=="男性"&&(int)me->query_skill("taisu-force", 1) > 49)
		return notify_fail("你不是纯正女子或者你的太素心经超过50级，难以领会高深的太素心经。\n");

	if ((int)me->query_skill("force", 1) < 200)
		return notify_fail("你的基本内功火候还不够，还不能学习太素心经。\n");

	if (me->query("family/family_name") != "古墓派" &&
	    me->query("family/family_name") != "古墓派")
return notify_fail("古月太素只有古墓弟子方可修习\n");

                if (me->query("gender") != "女性")return notify_fail("古月太素只有女性方可修习。\n");if (me->query("int") < 25)
		return notify_fail("你觉得太素心经过于艰深，以你的悟性难以理解。\n");

	if (me->query("con") < 25)
		return notify_fail("你的根骨不好，难以运转太素心经。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("太素心经只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taisu-force/" + func;
}

