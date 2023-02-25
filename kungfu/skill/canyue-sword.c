// canyue-sword.c
// 华夏玩家xmbai的自创武功：残月剑法
// Modified by smallfish@huaxia Sep.1998
#include <ansi.h>

inherit SKILL;

string is_private_skill() {return "xmbai";}
int can_not_hubo() {return 1;}

mapping *action = ({
([      "skill_name":    "追风逐电",
        "action":  "$N高举手中$w,使出一招「追风逐电」，一剑斜刺$n的$l",
        "dodge" : 80,
        "damage": 180,
        "force" : 330,
        "attack": 130,
        "parry" : 80,
        "lvl"   : 0,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "斩尽杀绝",
        "action":  "$N就地一滚，使一招「斩尽杀绝」，手中$w从一个无法思议的角度挥向$n的$l",
        "dodge" : 90,
        "damage": 190,
        "force" : 340,
        "attack": 135,
        "parry" : 85,
        "lvl"   : 120,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "谁是英雄",
        "action":  "$N手中的$w光芒暴长，使出「谁是英雄」，如雷霆万钧砍向$n的$l",
        "dodge" : 95,
        "damage": 200,
        "force" : 350,
        "attack": 140,
        "parry" : 90,
        "lvl"   : 140,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "空山灵雨",
        "action":  "$N一招看似平淡无奇的「空山灵雨」，$w变的如一团雨丝向$n落去",
        "dodge" : 105,
        "damage": 210,
        "force" : 360,
        "attack": 145,
        "parry" : 95,
        "lvl"   : 160,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "高不胜寒",
        "action":  "$N天人合一，内外交融，手中$w象幽灵般刺向$n的$l",
        "dodge" : 110,
        "damage": 220,
        "force" : 370,
        "attack": 150,
        "parry" : 100,
        "lvl"   : 180,
        "damage_type":  "刺伤"
]),
([      "skill_name":    "重回人间",
        "action":  "$N飞身而起，手中的$w幻出一片剑光，忽然反手一剑横斩$n的$l",
        "dodge" : 115,
        "damage": 230,
        "force" : 380,
        "attack": 155,
        "parry" : 105,
        "lvl"   : 200,
        "damage_type":  "刺伤"
]),
});
int double_attack() { return 3; }
int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力不够，没有办法练残月剑法。\n");


    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
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
    level   = (int) me->query_skill("canyue-sword",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("你的体力不足以练习残月剑法。\n");
    if (me->query("int") < 30)
		return notify_fail("你觉得残月剑法过于艰深，难以理解。\n");
    if ((int)me->query("neili") < 60 )
        return notify_fail("你的内力不够，没有办法练习残月剑法。\n");

    me->receive_damage("qi", 50);
    me->add("neili", -50);

    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canyue-sword/" + action;
}
