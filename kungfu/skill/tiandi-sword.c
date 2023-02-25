// This is player's own skill (Write by Lonely@nt2)
// Create by 藤原拓海(Ae860) at Fri Jul 24 19:24:52 2020
// 天地一剑(tiandi-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N手中$w放出丝丝微光，$n顿时感觉天地失色，眼前只有那一剑还带有光彩",
	"attack" : 234,
	"damage" : 231,
	"force" : 245,
	"dodge" : 248,
	"parry" : 245,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "锋芒"
 ]),
// ZHAOSHI : 1
([      "action" : "$N似有所感，抬头看天，只见天宫清明，倒映手中$w，刹那间$n$l鲜血喷出",
	"attack" : 234,
	"damage" : 231,
	"force" : 245,
	"dodge" : 248,
	"parry" : 245,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "惊神"
 ]),
// ZHAOSHI : 2
([      "action" : "$N微微一笑，手中$w放阳万寸光芒，$n回过神来时，$l血液喷发而出",
	"attack" : 244,
	"damage" : 241,
	"force" : 255,
	"dodge" : 258,
	"parry" : 255,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "破天"
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
		return notify_fail("你的内力太弱，无法练" + "天地一剑" + "。\n");
		
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
	level = (int)me->query_skill("tiandi-sword",1);
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

	lvl = me->query_skill("tiandi-sword", 1);
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
	return __DIR__ + "tiandi-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
