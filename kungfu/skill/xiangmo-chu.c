// xiangmo-chu.c 金刚降魔杵

inherit SKILL;

mapping *action = ({
([      "action": "$N高举手中$w，使出一招「金刚在世」，直劈$n的$l  ",
	"force" : 100,
	"dodge" : -5,
	"parry" : 20,
	"lvl"   : 0,
	"damage": 30,
	"skill_name" : "金刚在世",
	"damage_type": "挫伤",
]),
([      "action": "$N使出「金刚伏魔」，单手舞动$w，一伏身，$w横扫$n的下盘  ",
	"force" : 130,
	"attack": 5,
	"dodge" : 5,
	"parry" : 25,
	"lvl"   : 40,
	"damage": 40,
	"skill_name" : "金刚伏魔",
	"damage_type": "挫伤",
]),
([      "action": "$N反身仰面，使出一式「金刚宣法」，双手握$w，一棍直刺$n的$l  ",
	"force" : 150,
	"attack": 8,
	"dodge" : 10,
	"parry" : 25,
	"lvl"   : 80,
	"damage": 45,
	"skill_name" : "金刚宣法",
	"damage_type": "挫伤",
]),
([      "action": "$N使出一招「引趣众生」，双手举棍撩向$n的裆部  ",
	"force" : 160,
	"attack": 15,
	"dodge" : 0,
	"parry" : 31,
	"lvl"   : 100,
	"damage": 50,
	"skill_name" : "引趣众生",
	"damage_type": "挫伤",
]),
([      "action": "$N舞动手中$w，使出「歌舞阎罗」，顿时罩住$n的全身  ",
	"force" : 190,
	"attack": 22,
	"dodge" : 10,
	"parry" : 35,
	"lvl"   : 120,
	"damage": 55,
	"skill_name" : "歌舞阎罗",
	"damage_type": "挫伤",
]),
([      "action": "$N使出一招「浮游血海」，全身贴地而飞，一棍直捣$n的$l  ",
	"force" : 230,
	"attack": 28,
	"dodge" : 15,
	"parry" : 38,
	"lvl"   : 130,
	"damage": 60,
	"skill_name" : "浮游血海",
	"damage_type": "挫伤",
]),
([      "action": "$N使出一式「驱鬼御魔」，以棍支地，双足飞揣$n的面门  ",
	"force" : 260,
	"attack": 33,
	"dodge" : 20,
	"parry" : 32,
	"lvl"   : 140,
	"damage": 70,
	"skill_name" : "驱鬼御魔",
	"damage_type": "挫伤",
]),
([      "action": "$N运力于掌，使出「荡魔除妖」，飞身疾进，手中$w横扫$n的$l  ",
	"force" : 300,
	"attack": 35,
	"dodge" : 20,
	"parry" : 33,
	"lvl"   : 150,
	"damage" : 80,
	"skill_name" : "荡魔除妖",
	"damage_type": "挫伤",
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 90)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("staff", 1) < (int)me->query_skill("xiangmo-chu", 1))
		return notify_fail("你的基本杖法水平有限，无法领会更高深的降魔杵法。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("xiangmo-chu",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) || 
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了金刚降魔杵。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够，练不了金刚降魔杵。\n");

	me->receive_damage("qi", 42);
	me->add("neili", -54);

	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"xiangmo-chu/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
