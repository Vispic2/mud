// shenlong-mixin.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("medical", 1) < 100)
		return notify_fail("你的基本医术造诣太浅，无"
				   "法领会深奥的神龙秘辛。\n");

	if ((int)me->query_skill("medical", 1) < (int)me->query_skill("shenlong-mixin", 1))
		return notify_fail("你的基本医术水平有限，无"
				   "法掌握更深奥的神龙秘辛。\n");

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
