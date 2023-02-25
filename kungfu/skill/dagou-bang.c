// dagou-bang.c 打狗棒法
// Modified by Venus Oct.1997
// write by Xiang

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
	"force" : 280,
	"attack": 98,
	"dodge" : 120,
	"parry" : 100,
	"damage": 80,
	"damage_type": "挫伤"
]),
([      "action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
	"force" : 300,
	"attack": 100,
	"dodge":  100,
	"parry" : 120,
	"damage": 100,
	"damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
	"force" : 290,
	"attack": 99,
	"dodge":  120,
	"parry" : 100,
	"damage": 70,
	"damage_type": "挫伤"
]),
([      "action": "$N施出「拨狗朝天」，$w由下往上向$n撩去",
	"force" : 310,
	"attack": 105,
	"dodge" : 80,
	"parry" : 140,
	"damage": 90,
	"damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够，无法学习打狗棒法。\n");

	if ((int)me->query_int() < 30)
		return notify_fail("你现在悟性不够，难以领会打狗棒法。\n");

	if ((int)me->query_skill("staff", 1) < 100)
		return notify_fail("你的基本杖法火候不够，无法学习打狗棒法。\n");

	if ((int)me->query_skill("staff", 1) < (int)me->query_skill("dagou-bang", 1))
		return notify_fail("你的基本杖法水平有限，无法领会更高深的打狗棒法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够练打狗棒法。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练打狗棒法。\n");

	me->receive_damage("qi", 64);
	me->add("neili", -71);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
