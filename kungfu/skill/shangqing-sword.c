// This is player's own skill (Write by Lonely@nt2)
// Create by 火炎风(Hongmi) at Tue Jun 06 00:12:15 2017
// 上清破云剑(shangqing-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N持剑站立，$w剑气颤动。一道剑光笔直朝$n小腹冲去",
	"attack" : 130,
	"damage" : 130,
	"force" : 130,
	"dodge" : 130,
	"parry" : 130,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "剑荡苍穹"
 ]),
// ZHAOSHI : 1
([      "action" : "$N身影如月影一般迅捷，$w剑光闪耀，一道残影向$n上身横切",
	"attack" : 130,
	"damage" : 130,
	"force" : 130,
	"dodge" : 130,
	"parry" : 130,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "皎月初升"
 ]),
// ZHAOSHI : 2
([      "action" : "$N剑指苍穹，只见天上金光闪耀，$n全身都笼罩在剑光之下",
	"attack" : 130,
	"damage" : 130,
	"force" : 130,
	"dodge" : 130,
	"parry" : 130,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "云丛剑影"
 ]),
// ZHAOSHI : 3
([      "action" : "$N轻挥$w，上天降下万道星辉，笼罩$n全身要害，直冲$I，无法闪避。",
	"attack" : 150,
	"damage" : 150,
	"force" : 150,
	"dodge" : 150,
	"parry" : 150,
	"lvl" : 30,
	"damage_type" : "刺伤",
	"skill_name" : "天穹破云"
 ]),
// ZHAOSHI : 4
([      "action" : "$N双手持剑向前一斩，凌厉的剑气伴随着破空的声音直冲$n，一式「月转星移」让$n感受到了绝望的恐惧。",
	"attack" : 150,
	"damage" : 150,
	"force" : 150,
	"dodge" : 150,
	"parry" : 150,
	"lvl" : 40,
	"damage_type" : "刺伤",
	"skill_name" : "月转星移"
 ]),
// ZHAOSHI : 5
([      "action" : "$N用$w在地上画下一个圈，使出「风动云影」，数把光剑冲宵而去，蓦然从不知名的地方穿出，从$n胸膛对穿而出",
	"attack" : 160,
	"damage" : 160,
	"force" : 160,
	"dodge" : 160,
	"parry" : 160,
	"lvl" : 50,
	"damage_type" : "刺伤",
	"skill_name" : "风动云影"
 ]),
// ZHAOSHI : 6
([      "action" : "$N将$w舞得密不透风，剑影遮住了天上的月光，但从剑影中透出的森森剑气还是扑面而来，$n的嘴角口鼻沁出血花",
	"attack" : 160,
	"damage" : 160,
	"force" : 160,
	"dodge" : 160,
	"parry" : 160,
	"lvl" : 60,
	"damage_type" : "刺伤",
	"skill_name" : "闭月式"
 ]),
// ZHAOSHI : 7
([      "action" : "$N举剑念咒，只见$w一分为二，二分为四，刹那间铺天盖地的神剑从地底穿出，从各个方向向$n刺去，直插云霄",
	"attack" : 160,
	"damage" : 160,
	"force" : 160,
	"dodge" : 160,
	"parry" : 160,
	"lvl" : 80,
	"damage_type" : "刺伤",
	"skill_name" : "震月惊天"
 ]),
// ZHAOSHI : 8
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "上清破云剑" + "。\n");
		
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
	level = (int)me->query_skill("shangqing-sword",1);
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

	lvl = me->query_skill("shangqing-sword", 1);
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
	return __DIR__ + "shangqing-sword" + "/" + action; 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
