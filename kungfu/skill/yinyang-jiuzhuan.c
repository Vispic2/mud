// yinyang-jiuzhuan.c -阴阳九转
// Modified by name

inherit SKILL;

mapping *action = ({
([     "action" : "$N一式「阴阳九转」",
	"force" : 500,
	"dodge" : 500,
	"damage": 500,
	"lvl"   : 1,
	"skill_name" : "阴阳九转",
	"damage_type" : "瘀伤"
])
});




int valid_enable(string usage) { return  usage == "parry"; }


int difficult_level()
{
	return 666;
}

int valid_learn(object me)
{
	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("yinyang-jiuzhuan", 1))
	return notify_fail("你的基本内功水平有限，无法领会更高深的阴阳九转。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action)-1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("yinyang-jiuzhuan",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
		
	return notify_fail("阴阳九转博大精深，无法靠着普通的练习提升。\n");       
    return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yinyang-jiuzhuan/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
