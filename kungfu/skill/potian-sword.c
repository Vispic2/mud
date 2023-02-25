// This is player's own skill (Write by Lonely@nt2)
// Create by 小孩(Shangyi) at Sat Sep 30 23:42:34 2017
// 破天一剑(potian-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "刂—═╋【[1;35m∝╬══→::=破==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "破天剑气"
 ]),
// ZHAOSHI : 1
([      "action" : "刂—═╋【[1;33m∝╬══→::=惊==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "惊天剑气"
 ]),
// ZHAOSHI : 2
([      "action" : "刂—═╋【[1;36m∝╬══→::=裂==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "裂天剑气"
 ]),
// ZHAOSHI : 3
([      "action" : "刂—═╋【[1;32m∝╬══→::=逆==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 30,
	"damage_type" : "刺伤",
	"skill_name" : "逆天剑气"
 ]),
// ZHAOSHI : 4
([      "action" : "刂—═╋【[1;31m∝╬══→::=开==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 40,
	"damage_type" : "刺伤",
	"skill_name" : "开天剑气"
 ]),
// ZHAOSHI : 5
([      "action" : "刂—═╋【[37m∝╬══→::=碎==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 50,
	"damage_type" : "刺伤",
	"skill_name" : "碎天剑气"
 ]),
// ZHAOSHI : 6
([      "action" : "刂—═╋【[1;34m∝╬══→::=斩==>┈>═☆┣▇▇※フ",
	"attack" : 429,
	"damage" : 429,
	"force" : 429,
	"dodge" : 429,
	"parry" : 429,
	"lvl" : 60,
	"damage_type" : "刺伤",
	"skill_name" : "斩天剑气"
 ]),
// ZHAOSHI : 7
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "破天一剑" + "。\n");
		
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
	level = (int)me->query_skill("potian-sword",1);
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

	lvl = me->query_skill("potian-sword", 1);
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
	return __DIR__ + "potian-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
