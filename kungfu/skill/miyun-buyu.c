// dragon-strike.c 降龙十八掌 密云不雨
// modified by Venus Oct.1997
// modified by Doing 1999

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",     
	"dodge"  : 30,
	"parry"  : 25,
	"force"  : 200,
	"damage" : 40,
	"damage_type": "震伤"
]),
});

string main_skill() { return "dragon-strike"; }

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
	if (me->query_skill("dragon_strike", 1) > 0)
		return notify_fail("你已经学全十八掌了，不必再单独学习。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练降龙十八掌必须空手。\n");

	if ((int)me->query("str") < 30)
		return notify_fail("就你这身子骨还练降龙十八掌？小心弄折了胳膊。\n");

	if ((int)me->query_skill("force") < 90)
		return notify_fail("你的内功火候不够无法学习降龙十八掌。\n");

	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太差无法学习降龙十八掌。\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("你的基本掌法火候不够，无法学习降龙十八掌。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("miyun-buyu", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 120)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练降龙十八掌。\n");

	me->receive_damage("qi", 80);
	me->add("neili", -40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"miyun-buyu/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
