// This is player's own skill (Write by Lonely@nt2)
// Create by 道士(Daoshi) at Wed Aug 16 23:21:38 2017
// 发呆神拳(qwe-unarmed.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "[1;37m$N呆呆得站在那里，谁也料想不到，$N抬手就是一拳！打在$n的脸上，[31m$n翻滚着飞了出去，口中吐出一颗带血的后槽牙[31m",
	"attack" : 160,
	"damage" : 160,
	"force" : 160,
	"dodge" : 160,
	"parry" : 160,
	"lvl" : 0,
	"damage_type" : "瘀伤",
	"skill_name" : "发呆一拳"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"发呆神拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"发呆神拳"+"。\n");
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
	level = (int)me->query_skill("qwe-unarmed",1);
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

	lvl = me->query_skill("qwe-unarmed", 1);
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
	return __DIR__ + "qwe-unarmed" + "/" + action; 
}

string query_description()
{
	return
 "发呆的时候练成的武功。" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
