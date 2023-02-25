// This program is a part of NITAN MudLIB
// moon-blade.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([      "action" : "$N挥舞$w，使出一招「圆月弯刀」，上劈下撩，左挡右开，齐齐罩向$n",
        "skill_name" : "圆月弯刀",
        "force"  : 500,
        "attack" : 500,
        "dodge"  : 500,
        "parry"  : 500,
        "lvl"    : 1,
        "damage" : 500,
        "damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me){ return 1; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int difficult_level()
{
	return 666;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yuan-blade", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{        
        return notify_fail("圆月弯刀博大精深，无法靠着普通的练习提升。\n");       
        return 1;
}
mixed hit_ob(object me, object victim, int damage)
{
        mixed result;
        if (damage < 100) return 0;
                result = ([ "damage" : damage ]);
                result += ([ "msg" : HIW "$N" HIW "仰天一啸，刀劲迸发，满天具是雪亮的刀光，犹如满月的月光般美丽，\n""但却让人感到落入森罗地狱般，全身止不住的战抖，\n"HIR "霎时一股冰寒的刀气掠过$n" HIR "全身，$n" HIR "全身顿时鲜血淋漓，摇摇欲倒。\n" NOR ]);
                return result;  
}

string perform_action_file(string action)
{
        return __DIR__"yuan-blade/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
