// luoyan-hand.c 大落雁手
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIC"「江边斜雁」"NOR"，以掌化爪，五指如钩，直逼$n的膻中要穴",
	"lvl" : 0,
	"skill_name" : "江边斜雁"
]),
([	"action" : "$N左手虚晃，一式"CYN"「雁过无痕」"NOR"，右手上下直击，反扣$n的肩井大穴
",
	"lvl" : 10,
	"skill_name" : "雁过无痕"
]),
([	"action" : "$N使一式"BLU"「铁雁霜翎」"NOR"，掌指齐出，拍拿并施，拿向$n的三路要害",
	"lvl" : 20,
	"skill_name" : "铁雁霜翎"
]),
([	"action" : "$N左手鹰抓，右手蛇举，一式"MAG"「雁过留声」"NOR"疾扣$n的中节大脉",	
	"lvl" : 30,
	"skill_name" : "雁过留声"
]),
([	"action" : "$N使一式"YEL"「秋飞雁舞」"NOR"，四面八方出现无数掌影，一爪突出，抓向$n
的胸口",
	"lvl" : 50,
	"skill_name" : "秋飞雁舞"
]),
([	"action" : "$N两手环扣，全身关节啪啪作响，一式"HIM"「雁字回时」"NOR"，击向$n的$l",
	"lvl" : 80,
	"skill_name" : "雁字回时"
]),
([	"action" : "$N一式"HIB"「断鸿零雁」"NOR"，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"lvl" : 100,
	"skill_name" : "断鸿零雁"
]),
([	"action" : "$N岳立霆峙，一式"HIG"「雁回兰舟」"NOR"，在一阵暴雷声中，双手同时拍中$n
的七道死穴",
	"lvl" : 150,
	"skill_name" : "雁回兰舟"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="biluo-zhang"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大落雁手必须空手。\n");
	if ((int)me->query_skill("huiyan-xinfa", 1) < 20)
		return notify_fail("你的回雁心法火候不够，无法学大落雁手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练大落雁手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大落雁手。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 40;
	int d_e2 = 10;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 110;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoyan-hand", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"luoyan-hand/" + action;
}

int help(object me)
{
	write(HIC"\n大落雁手："NOR"\n");
	write(@HELP

    大落雁手为衡山派绝技之一。
    可与碧罗掌互备。
    
	学习要求：
		回雁心法20级
HELP
	);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
