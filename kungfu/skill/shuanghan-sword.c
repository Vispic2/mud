// This is player's own skill (Write by Lonely@nt2)
// Create by 寒江雪(Xuekui) at Wed Feb 24 20:06:49 2021
// 霜寒剑(shuanghan-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N手握$w，一跃而起，轻描谈写的向$n挥出一剑，正是传说中的剑招一剑霜寒十四州！",
	"attack" : 282,
	"damage" : 266,
	"force" : 280,
	"dodge" : 280,
	"parry" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "一剑霜寒十四州"
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
		return notify_fail("你的内力太弱，无法练" + "霜寒剑" + "。\n");
		
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
	level = (int)me->query_skill("shuanghan-sword",1);
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

	lvl = me->query_skill("shuanghan-sword", 1);
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
	return __DIR__ + "shuanghan-sword" + "/" + action; 
}

string query_description()
{
	return
 "飞雪剑是创自寒江雪的绝世剑法，招式轻盈灵动，迅
捷如风，以剑招百样玲珑而著称，当初移花宫主阿颜
带领十大掌门围攻寒江雪的时候，情势万分危机，寒
江雪在千钧一发悟出这套剑法，顿时风云突变，化险
为夷的同时还将移花宫主阿颜斩杀……" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
