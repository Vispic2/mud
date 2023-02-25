// hujia-daofa.c
// Designed by host
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w横推，一招「推波助澜」，由上至下向$n砍去",
	"skill_name" : "推波助澜",
	"force"  : 120,
	"attack" : 35,
	"dodge"  : 30,
	"parry"  : 12,
	"lvl"    : 0,
	"damage" : 40,
	"damage_type" : "割伤",
]),
([      "action" : "$N一招「沙鸥掠波」，刀锋自下而上划了个半弧，$w一提一收，平刃挥向$n的颈部",
	"skill_name" : "沙鸥掠波",
	"force"  : 160,
	"attack" : 42,
	"dodge"  : 40,
	"parry"  : 15,
	"lvl"    : 30,
	"damage" : 50,
	"damage_type" : "割伤",
]),
([      "action" : "$N使出一招「天设牢笼」，将$w舞得如白雾一般压向$n",
	"skill_name" : "天设牢笼",
	"force"  : 185,
	"attack" : 51,
	"dodge"  : 45,
	"parry"  : 17,
	"lvl"    : 50,
	"damage" : 60,
	"damage_type" : "割伤",
]),
([      "action" : "$N一招「闭门铁扇」，$w缓缓的斜着向$n推去",
	"skill_name" : "闭门铁扇",
	"force"  : 220,
	"attack" : 55,
	"dodge"  : 55,
	"parry"  : 21,
	"lvl"    : 80,
	"damage" : 70,
	"damage_type" : "割伤",
]),
([      "action" : "$N手拖$w，转身跃起，一招「翼德闯帐」，一道白光射向$n的胸口",
	"skill_name" : "翼德闯帐",
	"force"  : 255,
	"attack" : 65,
	"dodge"  : 60,
	"parry"  : 32,
	"lvl"    : 100,
	"damage" : 80,
	"damage_type" : "割伤",
]),
([      "action" : "$N挥舞$w，使出一招「白鹤舒翅」，上劈下撩，左挡右开，齐齐罩向$n",
	"skill_name" : "白鹤舒翅",
	"force"  : 290,
	"attack" : 70,
	"dodge"  : 70,
	"parry"  : 35,
	"lvl"    : 120,
	"damage" : 90,
	"damage_type" : "割伤",
]),
([      "action" : "$N一招「春风送暖」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"skill_name" : "春风送暖",
	"force"  : 320,
	"attack" : 80,
	"dodge"  : 85,
	"parry"  : 35,
	"lvl"    : 140,
	"damage" : 100,
	"damage_type" : "割伤",
]),
([      "action" : "$N蓦的使一招「八方藏刀」，顿时剑光中无数朵刀花从四面八方涌向$n全身",
	"skill_name" : "八方藏刀",
	"force"  : 340,
	"attack" : 110,
	"dodge"  : 100,
	"parry"  : 50,
	"lvl"    : 160,
	"damage" : 110,
	"damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功火候太浅。\n");

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
	level   = (int) me->query_skill("hujia-daofa", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够，练不了胡家刀法。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够，练不了胡家刀法。\n");

	me->receive_damage("qi", 55);
	me->add("neili", -61);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hujia-daofa/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
