// This is player's own skill (Write by Lonely@nt2)
// Create by 燕常归(Yxsyyr) at Mon Mar  8 11:15:41 2021
// 天遁剑(tiandun-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N手腕一抖，挽出一个美丽的剑花，穿向$n，$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "鲸饮未吞海"
 ]),
// ZHAOSHI : 1
([      "action" : "$N手掐剑诀，信手挥舞，剑气撕裂空气，$n闪避不及，$N的剑气顿时透体而入，$n口中鲜血狂喷，连退数步!",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "十步杀一人"
 ]),
// ZHAOSHI : 2
([      "action" : "$N拔剑出鞘，一道弧形剑光划过，$n只觉得腰部一凉！一股血箭喷涌而出,$N剑指向天冷冷的站着，一滴滴鲜血从手中剑上滴下!",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "白首太玄经"
 ]),
// ZHAOSHI : 3
([      "action" : "$N身外化身，剑外化剑，手中宝剑便似蛟龙腾空，拨云见日，天地为之失色。",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 30,
	"damage_type" : "刺伤",
	"skill_name" : "纵死侠骨香"
 ]),
// ZHAOSHI : 4
([      "action" : "$N一声长叹，左手捏着剑诀，身形微晃，顿时幻出十数个身影，十数柄剑齐向$n刺去。",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 40,
	"damage_type" : "刺伤",
	"skill_name" : "救赵挥金锤"
 ]),
// ZHAOSHI : 5
([      "action" : "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩,漫天剑影化为一剑直刺$n前胸，快捷无伦，只有一剑！",
	"attack" : 310,
	"damage" : 309,
	"force" : 307,
	"dodge" : 316,
	"parry" : 307,
	"lvl" : 50,
	"damage_type" : "刺伤",
	"skill_name" : "脱剑膝前横"
 ]),
// ZHAOSHI : 6
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "天遁剑" + "。\n");
		
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
	level = (int)me->query_skill("tiandun-sword",1);
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

	lvl = me->query_skill("tiandun-sword", 1);
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
	return __DIR__ + "tiandun-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
