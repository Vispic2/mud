// This is player's own skill (Write by Lonely@nt2)
// Create by 劝霜(Quanshuang) at Wed Mar  3 12:42:32 2021
// 飞霜剑(feishuang-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N一跃而起，手腕一抖，挽出一个美丽的剑花，飞向$n。只见$N人剑合一，穿向$n，$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！",
	"attack" : 200,
	"damage" : 200,
	"force" : 200,
	"dodge" : 212,
	"parry" : 200,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "悠哉"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "飞霜剑" + "。\n");
		
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
	level = (int)me->query_skill("feishuang-sword",1);
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

	lvl = me->query_skill("feishuang-sword", 1);
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
	return __DIR__ + "feishuang-sword" + "/" + action; 
}

string query_description()
{
	return
 "飞霜剑是劝霜轮回上百次，集众家之所长，化繁为简，
悟道千年，创出的一套剑法。" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
