// 太素明月式，一种成长性武功

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一招「明月熙照」，拳势凌厉，猛攻而前，打向$n的$l",
	"lvl" : 0,       
	"damage_type" : "内伤"
]),
([
	"action" : "$N柳眉微起，双拳直出，一招「明月天涯」，拳劲股股透出，击向$n的$l",
	"lvl" : 10,
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N使一招「河中明月」，右手向上一扬，左手向下握拳，上下奔出的拳劲不断涌$n的$l",
	"lvl" : 20,
	"damage_type" : "内伤"
]),
([
	"action" : "$N一式「明月海角」向$n的$l击去，劲道之猛,宛若猛龙",
	"lvl" : 30,
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N一个后空翻跳起，一招「明月高空照」，双拳便压向$n",
	"lvl" : 40,
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
//int lvl =me->query_skill("taisu-moon",1);
//if (lvl <150)
		//return notify_fail("你的太素心经等级＜150级，难以领会高深的太素心经。\n");
if (me->query("family/family_name") != "古墓派" &&
	    me->query("family/family_name") != "古墓派")
return notify_fail("古月太素只有古墓弟子方可修习\n");

                if (me->query("gender") != "女性")return notify_fail("古月太素只有女性方可修习。\n");
if (me->query("int") < 25)
		return notify_fail("你觉得太素明月式过于艰深，以你的悟性难以理解。\n");

	

if (me->query("con") < 25)
		return notify_fail("你觉得太素明月式过于艰深，以你的根骨难以理解。\n");



if (me->query("dex") < 25)
		return notify_fail("你觉得太素明月式过于艰深，以你的身法难以理解。\n");



if (me->query("str") < 25)
		return notify_fail("你觉得太素明月式过于艰深，以你的臂力难以理解。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太素明月式必须空手。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法修炼太素明月式。\n");
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
	int i, level, j;
	level   = (int) me->query_skill("taisu-moon",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	level/2,
				"dodge":	level/2,
				"parry":	level/2,
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练太素明月式。\n");
//	me->receive_damage("jingli", 50);
me->receive_damage("qi",50);
	me->add("neili", -50);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taisu-moon/" + action;
}

int diffcult_level() { return 200; }