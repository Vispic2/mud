#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N手中$w抡开，挟着呼呼风声，一招「树喧每每」，直取$n的各处要害",
    "damage": 600,
    "force": 300,
    "dodge" : 50,
    "damage_type" : "砍伤",
    "lvl" : 0,
    "skill_name" : "树喧每每"
]),
([  "action" : "$N纵身一跃，手中$w锤风呼啸，一招「月现长空」，横空向$n$l劈去",
    "damage": 600,
    "force": 300,
    "dodge" : 45,
    "damage_type" : "割伤",
    "lvl" : 10,
    "skill_name" : "月现长空"
]),
([  "action" : "$N手中$w接连劈出，，一招「渊源不尽」，旋风般砍向$n$l",
    "damage": 600,
    "force": 300,
    "dodge" : 40,
    "damage_type" : "砍伤",
    "lvl" : 20,
    "skill_name" : "渊源不尽"
]),
([  "action" : "$N使出一招「万派朝宗」，手中$w舞动，身随锤势，化作一溜烟尘，滚滚奔向$n的$l",
    "damage": 600,
    "force": 500,
    "dodge" : 35,
    "damage_type" : "砸伤",
    "lvl" : 30,
    "skill_name" : "万派朝宗"
]),
([  "action" : "$N不急不缓地转身微蹲，$N见$n露出破绽，急忙抢攻",
    "damage": 680,
    "force": 500,
    "dodge" : 30,
    "parry" : 54,
    "damage_type" : "割伤",
    "lvl" : 55,
    "skill_name" : "回风转云"
]),
([  "action" : "$N身形微动，就在同一时间自上中下左右砍出五锤砍向$n",
    "damage": 640,
    "force": 500,
    "dodge" : 25,
    "parry" : 66,
    "damage_type" : "砍伤",
    "lvl" : 68,
    "skill_name" : "五锤夺命"
]),
});

int valid_enable(string usage) { return usage=="hammer" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 50)
   return notify_fail("你的内功心法火候不够，无法学铁雪锤法。\n");
    if ((int)me->query("max_neili") < 150)
   return notify_fail("你的内力太弱，无法练铁雪锤法。\n");
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
    level = (int)me->query_skill("tiexue-hammer", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "hammer")
   return notify_fail("你使用的武器不对。\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 50)
    return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练铁雪锤法。\n");
    me->receive_damage("qi", 25);
return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tiexue-hammer/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

victim->start_busy(3);

                return msg;
}
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("tiexue-hammer",1);             
if (weapon)
{

        if (random(3)==1 && me->query_skill("tiexue-hammer",1)>100
        && (string)weapon->query("skill_type") == "hammer"
        && me->query_skill_mapped("force") == "guiyuan-tunafa"
        )
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIY"$N狂舞大锤,$n无法近身，也无法进攻!!\n"NOR;
        }
        if( damage_bonus > 30 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa"
        && random(2)==0) {
        victim->receive_wound("qi", (random(damage_bonus)+150));
        return HIY"$n被锤中$l要害，血贱了一地!!\n"NOR;
        }
}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
