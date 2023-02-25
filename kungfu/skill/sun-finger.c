// sun-finger.c 一阳指 book: 一阳指诀

inherit SKILL;

mapping *action = ({
([	"action": "$N一式「"+HIR+"阳关三叠"+NOR+"」，真气自指间喷薄而出，连出三指，快如电"
		   "闪，点向$n的$l",
	"force" : 350,
	"attack": 90,
	"dodge" : 75,
	"parry" : 55,
	"damage": 60,
	"skill_name" : HIR"阳关三叠"NOR,
	"damage_type" : "内伤"
]),
([	"action": "$N身形一转，一步跨到$n身后。$n急忙转身，$N又如闪电般跃回，"
		   "一式「"+YEL+"鲁阳返日"+NOR+"」，右手食指疾出，指向$n的$l",
	"force" : 390,
	"attack": 75,
	"dodge" : 45,
	"parry" : 60,
	"damage": 78,
	"skill_name" : YEL"鲁阳返日"NOR,
	"damage_type" : "内伤"
]),
([	"action": "$N向左踏出一步，左手轻扬，右手食指挟着雄浑内力疾点$n的$l，"
		   "招式光明坦荡，正是一式「"+WHT+"阳春白雪"+NOR+"」",
	"force" : 330,
	"attack": 69,
	"dodge" : 80,
	"parry" : 70,
	"damage": 66,
	"skill_name" : WHT"阳春白雪"NOR,
	"damage_type" : "内伤"
]),
([	"action": "$N身影飘起，一式「"+CYN+"阳钩挥天"+NOR+"」，自上而下，左脚弯曲如钩，踹"
		   "向$n的右肩，$n侧身相避，$N右手趁势点向$n的$l",
	"force" : 380,
	"attack": 72,
	"dodge" : 50,
	"parry" : 55,
	"damage": 85,
	"skill_name" : CYN"阳钩挥天"NOR,
	"damage_type" : "内伤"
]),
([	"action": "只见$N脸上忽地一红，左手一收，一式「"+HIY+"烈日骄阳"+NOR+"」，右手食指"
		   "斜指，向$n的$l点去",
	"force" : 370,
	"attack": 75,
	"dodge" : 65,
	"parry" : 60,
	"damage": 71,
	"skill_name" : HIY"烈日骄阳"NOR,
	"damage_type" : "内伤"
]),
([	"action": "$N左掌斜削，突然间变掌为指，嗤的一声响，一式「"+HIM+"丹凤朝阳"+NOR+"」，"
		   "使出一阳指力，疾点$n的$l",
	"force" : 400,
	"attack": 64,
	"dodge" : 60,
	"parry" : 45,
	"damage": 85,
	"skill_name" : HIM"丹凤朝阳"NOR,
	"damage_type" : "内伤"
]),
([	"action": "$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式「"+HIR+"阴"
		   "阳交错"+NOR+"」，射向$n的后脑",
	"force" : 420,						  
	"attack": 60,
	"dodge" : 55,
	"parry" : 60,
	"damage": 95,
	"skill_name" : HIR"阴阳交错"NOR,
	"damage_type" : "内伤"
]),
([      "action": "$N一声大吼, 一式「"+HIY+"三阳开泰"+NOR+"」，用尽全力向$n的$l点去",
	"force" : 440,
	"attack": 75,
	"dodge" : 45,
	"parry" : 45,
	"damage": 98,
	"skill_name" : HIY"三阳开泰"NOR,
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");

	if (me->query("gender") != "男性")
		return notify_fail("你阳气不足，无法学一阳指。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练一阳指。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法学一阳指。\n");

	if ((int)me->query_skill("finger", 1) < 100)
		return notify_fail("你的基本指法火候不够，无法学一阳指。\n");

	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("tanzhi-shentong", 1))
		return notify_fail("你的基本指法水平有限，无法领会更高深的一阳指。\n");

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
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练一阳指!\n");

	me->receive_damage("qi", 55);
	me->add("neili", -65);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sun-finger/" + action;
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
