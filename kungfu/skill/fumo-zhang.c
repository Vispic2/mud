inherit SKILL;

mapping *action = ({
([      "action":"$N纵步上前，手中$w自下而上，沉猛无比地向$n的小腹挑去",
	"force" : 180,
	"attack": 24,
	"dodge" : -10,
	"parry" : 10,
	"damage": 15,
	"lvl"   : 0,
	"damage_type":"挫伤"
]),
([      "action":"$N快步跨出，左手平托$w，右掌猛推杖端，顶向$n的胸口",
	"force" : 200,
	"attack": 36,
	"dodge" : -10,
	"parry" : 19,
	"damage": 25,
	"lvl"   : 30,
	"damage_type":"挫伤"
]),
([      "action":"$N高举$w，全身跃起，手中$w朝着$n头盖天灵盖猛然击落下去",
	"force" : 230,
	"attack": 42,
	"dodge" : -5,
	"parry" : 25,
	"damage": 25,
	"lvl"   : 60,
	"damage_type":"挫伤"
]),
([      "action":"$N双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风",
	"force" : 270,
	"attack": 51,
	"dodge" : -5,
	"parry" : 30,
	"damage": 35,
	"lvl"   : 80,
	"damage_type":"挫伤"
]),
([      "action":"$N横持$w，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中",
	"force" : 320,
	"attack": 64,
	"dodge" : -15,
	"parry" : 40,
	"damage": 30,
	"lvl"   : 100,
	"damage_type":"挫伤"
]),
([      "action":"$N全身滚倒，$w盘地横飞，化出漫天杖影，杖影把$n裹了起来",
	"force" : 350,
	"attack": 68,
	"dodge" : 5,
	"parry" : 42,
	"damage": 35,
	"lvl"   : 120,
	"damage_type":"挫伤"
]),
([      "action":"$N双手和十，躬身一递出$w，只见$w自肘弯飞出，拦腰向$n撞去",
	"force" : 380,
	"attack": 70,
	"dodge" : -5,
	"parry" : 52,
	"damage": 40,
	"lvl"   : 140,
	"damage_type":"挫伤"
]),
([      "action":"$N大喝一声，手中$w如飞龙般自掌中跃出，直向$n的胸口穿入",
	"force" : 410,
	"attack": 72,
	"dodge" : -5,
	"parry" : 60,
	"damage": 45,
	"lvl"   : 160,
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够，无法学习二十四路伏魔杖。\n");

	if ((int)me->query_skill("force") < 60)
		return notify_fail("你的内功火候太浅，无法学习二十四路伏魔杖。\n");

	if ((int)me->query_skill("staff", 1) < (int)me->query_skill("fumo-zhang", 1))
		return notify_fail("你的基本杖法水平有限，无法领会更高深的二十四路伏魔杖。\n");

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
	level = (int) me->query_skill("fumo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够练二十四路伏魔杖。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练二十四路伏魔杖。\n");

	me->receive_damage("qi", 65);
	me->add("neili", -68);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fumo-zhang/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
