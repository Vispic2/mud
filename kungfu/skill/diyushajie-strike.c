// diyushajie-strike.c
// 华夏玩家sker的自创武功：地狱杀劫掌法
// Modified by smallfish@huaxia Sep.1998
#include <ansi.h>

inherit SKILL;

string is_private_skill() {return "sker";}
int can_not_hubo() {return 1;}

mapping *action = ({
([      "skill_name":    "修罗杀",
        "action":  "$N向前斜跨一步，一招「修罗杀」，招招不离$n的$l",
        "dodge" : 80,
        "damage": 190,
        "force" : 340,
        "attack": 150,
        "parry" : 80,
        "lvl"   : 0,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "罗刹杀",
        "action":  "$N双手连环成爪，爪爪钩向$n，「罗刹杀」已向$n的$l抓去",
        "dodge" : 90,
        "damage": 200,
        "force" : 350,
        "attack": 185,
        "parry" : 85,
        "lvl"   : 120,
        "damage_type":  "抓伤"
]),
([      "skill_name":    "阎王杀",
        "action":  "$N左拳虚晃，右指蓄力，一招「阎王杀」直插向$n的$1",
        "dodge" : 95,
        "damage": 210,
        "force" : 360,
        "attack": 200,
        "parry" : 90,
        "lvl"   : 140,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "冥王杀",
        "action":  "$N大叫一声，骨骼一阵暴响，双臂忽然暴长数尺，一招「冥王杀」直直攻向$n的$l",
        "dodge" : 105,
        "damage": 220,
        "force" : 370,
        "attack": 2400,
        "parry" : 95,
        "lvl"   : 160,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "饿鬼杀",
        "action":  "$N飞身一跃而起，一声怪叫，一招「饿鬼杀」，双掌铺天盖地般拍向$n",
        "dodge" : 110,
        "damage": 230,
        "force" : 380,
        "attack": 240,
        "parry" : 100,
        "lvl"   : 180,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "风魔杀",
        "action":  "$N使出一招「风魔杀」，双掌急运内力，带着凛冽的掌风直拍$n的$l",
        "dodge" : 115,
        "damage": 240,
        "force" : 390,
        "attack": 245,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "凶冥杀",
        "action":  "$N双掌血红，一式「凶冥杀」，幻成漫天鬼影，雨点般向$n击去",
        "dodge" : 115,
        "damage": 260,
        "force" : 410,
        "attack": 255,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
([      "skill_name":    "天雷杀",
        "action":  "$N惨然一声长啸，一招「天雷杀」，双掌猛然击下，九天雷电直击$n的$l",
        "dodge" : 115,
        "damage": 300,
        "force" : 450,
        "attack": 255,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "瘀伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不够，没有办法练地狱杀劫掌。\n");

   

    if( (ob = me->query_temp("weapon")) || 
        (ob = me->query_temp("handing")) )
        return notify_fail("你只有空着双手才能修炼掌法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="strike" || usage=="parry";
}
int double_attack() { return 2; }


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
    level   = (int) me->query_skill("diyushajie-strike",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("你的体力不足以练习地狱杀劫掌。\n");

    if ((int)me->query("neili") < 60 )
        return notify_fail("你的内力不够，没有办法练习地狱杀劫掌。\n");

    me->receive_damage("qi", 50);
    me->add("neili", -50);

    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"diyushajie-strike/" + action;
}
