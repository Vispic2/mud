// This is player's own skill (Write by Lonely@nt2)
// Create by 武媚儿(Ouyanwen) at Sun Sep 24 23:12:44 2017
// 萌萌哒之音剑(look-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "[1;37m萌萌哒之音[32m可爱不是罪[31m卐两眼发光卍[1;37m只见$N看见$N如同世界上最美的东西，双手一伸，一支遮天大手，[31m横抓而来[1;37m，$N娇喝道[32m【好卡哇伊！】[1;37m啪的冲了过来，[31m[啊啊][1;37m$N一阵挣扎，$n哇的哭了起来，武媚儿双手一抱！$N突的进入他怀中!",
	"attack" : 166,
	"damage" : 166,
	"force" : 166,
	"dodge" : 166,
	"parry" : 166,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "萌萌哒之爱"
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
		return notify_fail("你的内力太弱，无法练" + "萌萌哒之音剑" + "。\n");
		
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
	level = (int)me->query_skill("look-sword",1);
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

	lvl = me->query_skill("look-sword", 1);
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
	return __DIR__ + "look-sword" + "/" + action; 
}

string query_description()
{
	return
 "Y武媚儿太喜欢动物而创的的恐怖剑法。" ; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
