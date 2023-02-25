// 飞天御剑流

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N左手捏了个剑诀，右手$w平平递出，一式看似普普通通的"+(order[random(13)])+"「唐竹」"NOR"直刺$n的前胸",
        "force" : 150,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 5,
        "damage_type" : "刺伤"
]),
([      "action" : "$N纵身向前，$w从一个想不到的角度突然弹出，一式看似平淡无奇的"+(order[random(13)])+"「袈裟斩」"NOR"直刺$n的左肋",
        "force" : 180,
        "dodge" : 15,
        "damage" : 85,
        "lvl" : 25,
        "damage_type" : "刺伤"
]),
([      "action" : "$N侧对$n一招"+(order[random(13)])+"「逆袈裟」"NOR"，$w横削而出?，直向$n的头部，普通的剑招之中透着一股霸气",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑身斜挥，剑尖指向$n的腹部，一招"+(order[random(13)])+"「左刺」"NOR"，自下而上，刺向$n，隐约竟然是上古密剑飞天御剑流的剑意",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 95,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手持剑，斜飞而出，一招"+(order[random(13)])+"「右刺」"NOR"，$w刺向$n的腹部",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 125,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长啸一声，横剑轻挥隐隐透出，一招普通的日式"+(order[random(13)])+"「左切上」"NOR"，但剑风罩住$n的全身",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 165,
        "damage_type" : "刺伤"

]),
([  "action" : "$N向前跨上一步，一招"+(order[random(13)])+"「右切上」"NOR"，手中$w自左向右向$n的$l
缓缓划去",
    "force" : 150,
    "dodge" : 130,
    "damage" : 25,
    "lvl" : 0,
    "skill_name" : "右切上",
    "damage_type" : "刺伤"
]),
([  "action" : "$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式"+(order[random(13)])+"「逆风」"NOR"直刺$n的$l",
    "force" : 300,
    "dodge" : 115,
    "damage" : 200,
    "lvl" : 90,
    "skill_name" : "逆风",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招"+(order[random(13)])+"「刺突剑」"NOR"，$w闪起数道寒光，自下而上反挑$n的$l",
    "force" : 500,
    "dodge" : 115,
    "damage" : 500,
    "lvl" : 150,
    "skill_name" : "刺突剑",
    "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("你的内力不够。\n");
//    if ((int)me->query_skill("feitian-xinfa", 1) < 20)
//       return notify_fail("你的飞天御剑流心法不熟。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("feitian-sword",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
       return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
       return notify_fail("你的体力不够练飞天御剑流。\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"feitian-sword/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
