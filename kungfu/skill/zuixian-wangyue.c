// zuixian-wangyue.c -醉仙望月
// Modified by name

inherit SKILL;

mapping *action = ({
([     "action" : "$N一式「醉仙望月」",
	"force" : 500,
	"dodge" : 500,
	"damage": 500,
	"lvl"   : 1,
	"skill_name" : "醉仙望月",
	"damage_type" : "瘀伤"
])
});




int valid_enable(string usage) { return  usage == "dodge"; }


int difficult_level()
{
	return 666;
}

int valid_learn(object me)
{
	if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("zuixian-wangyue", 1))
	return notify_fail("你的基本内功水平有限，无法领会更高深的醉仙望月。\n");
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
	level = (int) me->query_skill("zuixian-wangyue",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
		
	return notify_fail("醉仙望月博大精深，无法靠着普通的练习提升。\n");       
    return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zuixian-wangyue/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
