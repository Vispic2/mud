// SKILL zhemei-shou.c

inherit SKILL;

mapping *action = ({
([	"action": "$N一招「"+HIG+"吹梅笛怨"+NOR+"」，双手横挥，抓向$n",
	"force" : 80,
	"attack": 25,
	"dodge" : 20,
	"parry" : 25,
	"damage": 10,
	"lvl"   : 0,
	"skill_name" : HIG "吹梅笛怨" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N一招「"+RED+"黄昏独自愁"+NOR+"」，身子跃然而起，抓向$n的头部",
	"force" : 100,
	"attack": 28,
	"dodge" : 20,
	"parry" : 27,
	"damage": 20,
	"lvl"   : 30,
	"skill_name" : RED "黄昏独自愁" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N一招「"+GRN+"寒山一带伤心碧"+NOR+"」，双手纷飞，$n只觉眼花缭乱",
	"force" : 120,
	"attack": 32,
	"dodge" : 30,
	"parry" : 28,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : GRN "寒山一带伤心碧" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N一招「"+YEL+"梅花雪落覆白苹"+NOR+"」，双手合击，$n只觉无处可避",
	"force" : 150,
	"attack": 33,
	"dodge" : 30,
	"parry" : 33,
	"damage": 35,
	"lvl"   : 80,
	"skill_name" : YEL "梅花雪落覆白苹" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N一招「"+HIC+"砌下落梅如雪乱"+NOR+"」，双手飘然抓向$n",
	"force" : 180,
	"attack": 36,
	"dodge" : 30,
	"parry" : 37,
	"damage": 45,
	"lvl"   : 100,
	"skill_name" : HIC "砌下落梅如雪乱" NOR,
	"damage_type" : "瘀伤"
]),

([	"action": "$N双手平举，一招「"+HIW+"云破月来花弄影"+NOR+"」击向$n",
	"force" : 210,
	"attack": 42,
	"dodge" : 35,
	"parry" : 45,
	"damage": 40,
	"lvl"   : 120,
	"skill_name" : HIW "云破月来花弄影" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N一招「"+WHT+"花开堪折直须折"+NOR+"」，拿向$n，似乎$n的全身都被笼罩",
	"force" : 240,
	"attack": 47,
	"dodge" : 30,
	"parry" : 41,
	"damage": 45,
	"lvl"   : 140,
	"skill_name" : WHT "花开堪折直须折" NOR,
	"damage_type" : "内伤"
]),

([	"action": "$N左手虚晃，右手一记「"+MAG+"红颜未老恩先绝"+NOR+"」击向$n的头部",
	"force" : 260,
	"attack": 46,
	"dodge" : 30,
	"parry" : 47,
	"damage": 50,
	"lvl"   : 160,
	"skill_name" : MAG "红颜未老恩先绝" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N施出「"+RED+"虚妄笑红"+NOR+"」，右手横扫$n的$l，左手攻向$n的胸口",
	"force" : 280,
	"attack": 58,
	"dodge" : -10,
	"parry" : 55,
	"damage": 50,
	"lvl"   : 170,
	"skill_name" : RED "虚妄笑红" NOR,
	"damage_type" : "瘀伤"
]),
([	"action": "$N施出「"+YEL+"玉石俱焚"+NOR+"」，不顾一切扑向$n",
	"force" : 330,
	"attack": 62,
	"dodge" : -20,
	"parry" : 52,
	"damage": 80,
	"lvl"   : 180,
	"skill_name" : YEL "玉石俱焚" NOR,
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="parry"|| usage=="hand"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山折梅手必须空手。\n");

	if ((int)me->query("max_neili") < 900)
		return notify_fail("你的内力太弱，无法练天山折梅手。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，无法练天山折梅手。\n");

	if ((int)me->query_skill("hand", 1) < 100)
		return notify_fail("你的基本手法火候不够，无法练天山折梅手。\n");

	if ((int)me->query_skill("hand", 1) < (int)me->query_skill("zhemei-shou", 1))
		return notify_fail("你的基本手法水平有限，无法领会更高深的天山折梅手。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("zhemei-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练天山折梅手。\n");

	me->receive_damage("qi", 65);
	me->add("neili", -62);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
