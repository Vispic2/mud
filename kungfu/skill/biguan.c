// biguan.c

inherit SKILL;

void skill_improved(object me)
{}
int valid_learn(object me)
{
	return notify_fail("你只有通过用biguan打通任督二脉。才会这门功夫.\n");
}
int practice_skill(object me)
{
	return notify_fail("你只有通过用biguan打通任督二脉。才会这门功夫。\n");
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
