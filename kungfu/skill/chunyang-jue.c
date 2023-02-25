// chunyang-jue.c -纯阳决
// Modified by name

inherit FORCE;

mapping *action = ({
([      "action" : "$N一式「纯阳决」",
	"force" : 500,
	"dodge" : 500,
	"damage": 500,
	"lvl"   : 1,
	"skill_name" : "纯阳决",
	"damage_type" : "瘀伤"
])
});


int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("chunyang-jue", 1);
	return lvl * lvl * 20 * 18 / 100 / 200;
}



int valid_enable(string usage) { return  usage == "force"; }
int valid_force(string force) { return 1; }

int difficult_level()
{
	return 666;
}
int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < (int)me->query_skill("chunyang-jue", 1))
	return notify_fail("你的基本内功水平有限，无法领会更高深的纯阳决。\n");
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
	level = (int) me->query_skill("chunyang-jue",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
		
	return notify_fail("纯阳决博大精深，无法靠着普通的练习提升。\n");       
    return 1;
}


string exert_function_file(string action)
{
	return __DIR__"chunyang-jue/exert/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
