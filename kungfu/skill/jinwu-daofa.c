// jinwu-dao.c 金乌刀

inherit SKILL;

mapping *action = ({
([      "action" : "$N藏刀内收，一招「开门楫盗」，刀锋自下而上划了个半弧，向$n的$l挥去",
	"force" : 20,
	"dodge" : -10,
	"parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "开门楫盗",
	"damage_type" : "割伤"
]),
([      "action" : "$N左掌虚托右肘，一招「梅雪逢夏」，手中$w笔直划向$n的$l",
	"force" : 30,
	"dodge" : -10,
	"parry" : 10,
	"damage": 15,
	"lvl" : 10,
	"skill_name" : "梅雪逢夏",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「千钧压驼」，$w绕颈而过，刷地一声自上而下向$n猛劈",
	"force" : 40,
	"dodge" : -5,
	"parry" : 5,
	"damage": 20,
	"lvl" : 20,
	"skill_name" : "千钧压驼",
	"damage_type" : "割伤"
]),
([      "action" : "$N右手反执刀柄，一招「赤日金鼓」，猛一挫身，$w直向$n的颈中斩去",
	"force" : 60,
	"dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 30,
	"skill_name" : "赤日金鼓",
	"damage_type" : "割伤",
]),
([      "action" : "$N一招「汉将当关」，无数刀尖化作点点繁星，向$n的$l挑去",
	"force" : 80,
	"dodge" : 10,
	"parry" : 5,
	"damage": 30,
	"lvl" : 40,
	"skill_name" : "汉将当关",
	"damage_type" : "割伤"
]),
([      "action" : "$N双手合执$w，一招「鲍鱼之肆」，拧身急转，刀尖直刺向$n的双眼",
	"force" : 110,
	"dodge" : 15,
	"parry" : 15,
	"damage": 35,
	"lvl" : 50,
	"skill_name" : "鲍鱼之肆",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「旁敲侧击」，手中$w划出一个大平十字，向$n纵横劈去",
	"force" : 140,
	"dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "旁敲侧击",
	"damage_type" : "割伤"
]),
([      "action" : "$N反转刀尖对准自己，一招「长者折枝」，全身一个翻滚，$w向$n拦腰斩去",
	"force" : 180,
	"dodge" : 20,
	"parry" : 10,
	"damage": 50,
	"lvl" : 70,
	"skill_name" : "长者折枝",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「赤日炎炎」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
	"force" : 220,
	"dodge" : 10,
	"parry" : 20,
	"damage": 55,
	"lvl" : 80,
	"skill_name" : "赤日炎炎",
	"damage_type" : "割伤"
]),
([      "action" : "$N刀尖平指，一招「大海沉沙」，一片片切骨刀气如飓风般裹向$n的全身",
	"force" : 270,
	"dodge" : 5,
	"parry" : 25,
	"damage": 60,
	"lvl" : 90,
	"skill_name" : "大海沉沙",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry")
; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 120)
		return notify_fail("你的内力不够。\n");
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
	level   = (int) me->query_skill("jinwu-daofa",1);
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

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练金乌刀法。\n");

	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练金乌刀法。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -31);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
