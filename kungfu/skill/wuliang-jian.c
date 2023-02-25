#include <ansi.h>

inherit SKILL;

mapping *action = ({
([   "action" : "$N面露微笑，手中$w一抖，一招「德无量」，剑光暴长，洒向$n的$l",
     "force"  : 50,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 110,
     "lvl"    : 0,
     "skill_name" : "德无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N身形突闪，剑招陡变，一招「心无量」，手中$w从左位反刺$n的$l",
     "force"  : 70,
     "attack" : 25,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 115,
     "lvl"    : 20,
     "skill_name" : "心无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N一招「缘无量」，暴退数尺，低首抚剑，随后手中$w骤然穿上，刺向$n的$l",
     "force"  : 75,
     "attack" : 33,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 120,
     "lvl"    : 40,
     "skill_name" : "缘无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N身形一晃疾掠而上，手中$w龙吟一声，一招「大海无量」，对准$n$l连递数剑",
     "force"  : 90,
     "attack" : 39,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 125,
     "lvl"    : 60,
     "skill_name" : "大海无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N一招「天地无量」扑向$n，如影相随，手中$w“铮”然有声，往$n的$l刺去",
     "force"  : 100,
     "attack" : 43,
     "dodge"  : 60,
     "parry"  : 40,
     "damage" : 125,
     "lvl"    : 80,
     "skill_name" : "天地无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N一个侧身，一招「日月无量」，手中$w疾往斜上挑起，直指$n的$l",
     "force"  : 130,
     "attack" : 51,
     "dodge"  : 50,
     "parry"  : 45,
     "damage" : 130,
     "lvl"    : 100,
     "skill_name" : "日月无量",
     "damage_type":  "刺伤"
]),
([   "action" : "$N微微一个转身，手中$w却已自肋下穿出，一招「乾坤无量」，罩向$n的$l",
     "force"  : 150,
     "attack" : 62,
     "dodge"  : 40,
     "parry"  : 47,
     "damage" : 130,
     "lvl"    : 120,
     "skill_name" : "乾坤无量",
     "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("sword", 1) < 20)
                return notify_fail("你的基本剑法火候不够，无法学习无量剑法。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("wuliang-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的无量剑法。\n");

        return 1;
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
        level   = (int) me->query_skill("wuliang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if ( ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力不够，无法练习无量剑法。\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够，无法练习无量剑法。\n");
        
        me->add("qi", -20);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuliang-jian/" + action;
}
int query_effect_parry(object attacker, object me)
{
        int lvl;
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")))
                return 0;
                
        if ((string)weapon->query("skill_type") != "sword") 
                return 0;
                
        lvl = me->query_skill("wuliang-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
