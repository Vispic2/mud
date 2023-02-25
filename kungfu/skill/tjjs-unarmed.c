// This is player's own skill (Write by Lonely@nt2)
// Create by 先生(Watercup) at Thu Aug 17 10:54:50 2017
// 太极九势拳(tjjs-unarmed.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N抱守元一，脚踩太极。月隐日藏，天地混沌。$n惊诧莫名，心中焦躁，正欲长啸。$N微微一笑，一拳缓缓伸出。混沌深处，乍现万丈光拳，混沌碎，天地分。$n浑身喷血，向后飞出，隐隐有破碎之象",
	"attack" : 130,
	"damage" : 130,
	"force" : 130,
	"dodge" : 130,
	"parry" : 130,
	"lvl" : 0,
	"damage_type" : "瘀伤",
	"skill_name" : "天地初现"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"太极九势拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"太极九势拳"+"。\n");
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
	level = (int)me->query_skill("tjjs-unarmed",1);
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

	lvl = me->query_skill("tjjs-unarmed", 1);
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
	return __DIR__ + "tjjs-unarmed" + "/" + action; 
}

string query_description()
{
	return
 "先生云游之武当，登金顶有感，悟道七日。创太极九
势记之mycmds ofen先生云游之武当，登金顶有感，悟
道七日。创太极九势记之" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
