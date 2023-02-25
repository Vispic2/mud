// wudu-zhang 五毒掌
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N双手一翻，两掌带着淡淡的蓝光，直向$n拍去",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 50,
	"lvl" : 0,
	"skill_name" : "五毒掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左掌虚晃，右掌直出，犹如毒蛇一般直迫$n的胸前",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 60,
	"lvl" : 10,
	"skill_name" : "五毒掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌翻飞，四周迷茫着一股暗淡的雾气，排向$n的全身",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 70,
	"lvl" : 20,
	"skill_name" : "五毒掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两掌一分，左掌如蝎，右掌似蛇，同时向$n击过去",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 80,
	"lvl" : 30,
	"skill_name" : "五毒掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N默运内力，双掌忽然变黑，带着一股阴风只扑$n的全身",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage":100,
	"lvl" : 40,
	"skill_name" : "五毒掌",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练五毒掌必须空手。\n");
	if ((int)me->query_skill("wudu-xinfa", 1) < 20)
		return notify_fail("你的五毒心法火候不够，无法学五毒掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练五毒掌。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("wudu-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练五毒掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("wudu-zhang")) > 10 )
	victim->apply_condition("wudu_poison",
	 random(me->query_skill("wudu-zhang")/10) + 1 + 
	 victim->query_condition("wudu_poison"));
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
