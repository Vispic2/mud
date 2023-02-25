// This is player's own skill (Write by Lonely@nt2)
// Create by 灵鹫宫主(Qq2558215667) at Tue Feb 23 18:54:55 2021
// 狠人剑(henren-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N一跃而起，一招「人鬼同途」，衣裳爆开，手中的$w朝着心脏捅去，鲜血飙出，$n只觉一股寒流穿心而过，喉头一甜，鲜血狂喷而出，倒地身亡！",
	"attack" : 266,
	"damage" : 251,
	"force" : 261,
	"dodge" : 252,
	"parry" : 261,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "人鬼同途"
 ]),
// ZHAOSHI : 1
([      "action" : "$N一个滑铲，一招「人鬼同途」，手中的$w自敌人胯下迅速划过，$n直觉胯下一凉！",
	"attack" : 266,
	"damage" : 251,
	"force" : 261,
	"dodge" : 252,
	"parry" : 261,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "天地同寿"
 ]),
// ZHAOSHI : 2
([      "action" : "$N拥入$n怀中，说时迟那时快，一招「玉碎昆冈」，手中$w疾刺，这招却是两败俱伤！",
	"attack" : 266,
	"damage" : 251,
	"force" : 261,
	"dodge" : 252,
	"parry" : 261,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "玉碎昆冈"
 ]),
// ZHAOSHI : 3
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "狠人剑" + "。\n");
		
	return 1;
}

int valid_enable(string usage) { 
	return usage == "sword" || 
	       usage == "parry"; 
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
	level = (int)me->query_skill("henren-sword",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("henren-sword", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) || 
		(string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");     
	
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
		
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
		
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} 

string perform_action_file(string action) 
{
	return __DIR__ + "henren-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
