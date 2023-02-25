// count.c

inherit SKILL;

//string type() { return "knowledge"; }

void skill_improved(object me)
{
}

int valid_learn(object me)
{
	object ob;

	if ((int)me->query_skill("mathematics", 1) < 50)
		return notify_fail("你的算术知识太差，无法理解阴阳八卦的奥妙。\n");
	if ((int)me->query_skill("mathematics", 1) < (int)me->query_skill("count", 1))
		return notify_fail("你的算术知识有限，无法理解更深奥的阴阳八卦。\n");
	if ((int)me->query_skill("count", 1) > (int)me->query("int")*10)
		return notify_fail("你的先天悟性不够，无法理解更深奥的阴阳八卦。\n");

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
