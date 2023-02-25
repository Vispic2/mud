// ding-force.c 小丁气功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("小丁气功只能跟小丁学来增加熟练度。\n");
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
