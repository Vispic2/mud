// This is player's own skill (Write by Lonely@nt2)
// Create by 静无(Mingben) at Mon Jun 05 23:30:42 2017
// 万剑归宗剑(wuming-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N纵身一跃，手握着$w,顿时一招【风云变幻】刺向$n的胸膛。",
	"attack" : 169,
	"damage" : 169,
	"force" : 169,
	"dodge" : 169,
	"parry" : 169,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "风云变幻"
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
		return notify_fail("你的内力太弱，无法练" + "万剑归宗剑" + "。\n");
		
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
	level = (int)me->query_skill("wuming-sword",1);
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

	lvl = me->query_skill("wuming-sword", 1);
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
	return __DIR__ + "wuming-sword" + "/" + action; 
}

string query_description()
{
	return
 "万剑归宗创自于无名的绝世剑法，招式霸道勇猛。" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
