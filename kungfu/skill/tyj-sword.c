// This is player's own skill (Write by Lonely@nt2)
// Create by 天谕(Wjb132) at Thu Feb 25 17:19:11 2021
// 天谕剑(tyj-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N帅死了一大片人。",
	"attack" : 283,
	"damage" : 267,
	"force" : 278,
	"dodge" : 267,
	"parry" : 278,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "扶摇直上九万里"
 ]),
// ZHAOSHI : 1
([      "action" : "$N牛逼极了。",
	"attack" : 313,
	"damage" : 297,
	"force" : 308,
	"dodge" : 297,
	"parry" : 308,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "铁马冰河入梦来"
 ]),
// ZHAOSHI : 2
([      "action" : "$N好牛逼啊。",
	"attack" : 323,
	"damage" : 307,
	"force" : 318,
	"dodge" : 307,
	"parry" : 318,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "收取关山五十州"
 ]),
// ZHAOSHI : 3
([      "action" : "$N牛逼",
	"attack" : 331,
	"damage" : 315,
	"force" : 326,
	"dodge" : 315,
	"parry" : 326,
	"lvl" : 30,
	"damage_type" : "刺伤",
	"skill_name" : "位卑未敢忘忧国"
 ]),
// ZHAOSHI : 4
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "天谕剑" + "。\n");
		
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
	level = (int)me->query_skill("tyj-sword",1);
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

	lvl = me->query_skill("tyj-sword", 1);
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
	return __DIR__ + "tyj-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
