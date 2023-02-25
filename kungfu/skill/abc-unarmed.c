// This is player's own skill (Write by Lonely@nt2)
// Create by 小孩(Shangyi) at Fri Sep 29 23:08:42 2017
// 市井斗殴拳(abc-unarmed.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N使出蛮近挥出一拳，角度刁钻，力道狠辣!",
	"attack" : 179,
	"damage" : 179,
	"force" : 179,
	"dodge" : 179,
	"parry" : 179,
	"lvl" : 0,
	"damage_type" : "瘀伤",
	"skill_name" : "刁钻一拳"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"市井斗殴拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"市井斗殴拳"+"。\n");
	return 1;
}

int valid_enable(string usage) { 
	return usage == "unarmed" || 
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
	level = (int)me->query_skill("abc-unarmed",1);
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

	lvl = me->query_skill("abc-unarmed", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
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
	return __DIR__ + "abc-unarmed" + "/" + action; 
}

string query_description()
{
	return
 "打架专用" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
