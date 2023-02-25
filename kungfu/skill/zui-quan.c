// zui-quan.c 少林醉拳

#define CN_NAME "醉拳"

inherit SHAOLIN_SKILL;

mapping *action = ({
([      "action": "$N左手握拳，翻转挽一大圈，右掌上托，正是一招「只手擎天」",
	"force" : 150,
	"attack": 30,
	"dodge" : 5,
	"parry" : 5,
	"lvl"   : 0,
	"skill_name"  : "只手擎天",
	"damage_type" : "瘀伤"
]),
([      "action": "$N顺势一招「怪鸟搜云」，仰跌在地，手足齐发击向$n，随即跳起",
	"force" : 200,
	"attack": 33,
	"dodge" : 10,
	"parry" : 5,
	"lvl"   : 20,
	"skill_name"  : "怪鸟搜云",
	"damage_type" : "瘀伤"
]),
([      "action": "$N脚步欹斜，双手乱舞，声东击西，指前打后，跌跌撞撞，一拳「醉里乾坤」向$n打去",
	"force" : 150,
	"attack": 38,
	"dodge" : 15,
	"parry" : 5,
	"lvl"   : 40,
	"skill_name"  : "醉里乾坤",
	"damage_type" : "瘀伤"
]),
([      "action": "$N下盘若虚而稳，拳招似懈实精，翻滚跌扑，顾盼生姿，缓缓发出一招「如痴如醉」",
	"force" : 200,
	"attack": 55,
	"dodge" : 10,
	"parry" : 10,
	"lvl"   : 60,
	"skill_name"  : "如痴如醉",
	"damage_type" : "瘀伤"
]),
([      "action": "$N一个飞腾步，全身凌空，落下来足成绞花，一招「铁牛耕地」，右拳冲击$n$l",
	"force" : 250,
	"attack": 70,
	"dodge" : 25,
	"parry" : 15,
	"lvl"   : 80,
	"skill_name"  : "铁牛耕地",
	"damage_type" : "瘀伤"
]),
([      "action": "$N一个「鹞子翻身」，顺势上跃，同时身形舒展，步履踉跄，似醉非醉，攻向$n身前",
	"force" : 200,
	"attack": 66,
	"dodge" : 20,
	"parry" : 25,
	"lvl"   : 100,
	"skill_name"  : "鹞子翻身",
	"damage_type" : "瘀伤"
]),
([      "action": "$N飞身而起，从空中俯击而下，一拳「雁落长空」直取$n的$l",
	"force" : 20,
	"attack": 80,
	"dodge" : 25,
	"parry" : 30,
	"lvl"   : 120,
	"skill_name"  : "雁落长空",
	"damage_type" : "瘀伤"
]),
([      "action": "$N拦住$n退路，晃动中双拳翻飞，一招「金龙探爪」连环击向$n$l",
	"force" : 300,
	"attack": 86,
	"dodge" : 30,
	"parry" : 45,
	"lvl"   : 140,
	"skill_name"  : "金龙探爪",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练" + CN_NAME + "必须空手。\n");

	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练" + CN_NAME + "。\n");

	if (me->query_skill("unarmed", 1) < me->query_skill("zui-quan", 1))
		return notify_fail("你的基本拳脚水平有限，无法领悟更高深的" + CN_NAME + "。\n");

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
	level = (int) me->query_skill("zui-quan", 1);
	for (i = sizeof(action); i > 0; i--)
		if(level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练" + CN_NAME + "。\n");

	me->receive_damage("qi", 55);
	me->add("neili", -48);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zui-quan/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
