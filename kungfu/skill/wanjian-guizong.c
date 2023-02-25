// wanjian-guizong.c
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name"  : "万剑归宗",
	"action": "$N使一招「万剑归宗」，手中$w剑光暴长，向$n的$l刺去",
	"force" : 300,
	"attack": 300,
	"parry" : 300,
	"dodge" : 300,
	"damage": 300,
	"lvl"   : 1,
	"damage_type":  "刺伤"
]),

});

int valid_learn(object me)
{
	object ob;
	
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够，没有办法练万剑归宗。\n");
	
	if (! (ob = me->query_temp("weapon"))
	||  (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能学习剑法。\n");
	
	if (me->query_skill("sword", 1) < me->query_skill("wanjian-guizong", 1))
		return notify_fail("你的基本剑法火候有限，无法领会更高深的万剑归宗。\n");
	
	return 1;
}
int difficult_level()
{
	return 666;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action)-1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("wanjian-guizong", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{        
        return notify_fail("万剑归宗博大精深，无法靠着普通的练习提升。\n");       
        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;
	int i;

	lvl = me->query_skill("wanjian-guizong", 1);			
	victim->receive_wound("qi", damage_bonus / 2);
	return HIW "$N" HIW "默运内功，剑光四射攻向""$n" HIW "！"NOR"\n";
	
	
}

string perform_action_file(string action)
{
	return __DIR__"wanjian-guizong/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
