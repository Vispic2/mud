#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "在呼呼风声中，$N使一招「上步劈坤势」，双手如钩如戢，插向$n的$l",
        "force" : 100,
        "attack": 28,
        "dodge" : 17,
        "parry" : 0,
        "damage": 13,
        "lvl"   : 0,
        "skill_name" : "上步劈坤势" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N身形一跃，费神扑上，使出一招「阴阳劲」，右手直直抓向$n的$l",
        "force" : 130,
        "attack": 35,
        "dodge" : 20,
        "parry" : 5,
        "damage": 20,
        "lvl"   : 20,
        "skill_name" : "阴阳劲" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N双手平伸，十指微微上下抖动，一招「追云手」打向$n的$l",    
        "force" : 160,
        "attack": 39,
        "dodge" : 32,
        "parry" : 10,
        "damage": 25,
        "lvl"   : 40,
        "skill_name" : "追云手" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N使出一招「崩山啸海势」，猛的冲至$n跟前，双爪暴风骤雨般抓向$n",
        "force" : 172,
        "attack": 42,
        "dodge" : 38,
        "parry" : 19,
        "damage": 29,
        "lvl"   : 60,
        "skill_name" : "崩山啸海势" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N双手平提胸前，左手护住面门，一招「奔雷归穹势」右手推向$n的$l",
        "force" : 187,
        "attack": 45,
        "dodge" : 41,
        "parry" : 21,
        "damage": 33,
        "lvl"   : 80,
        "skill_name" : "奔雷归穹势" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N使出「抱残守缺势」，低喝一声，双手化掌为爪，一前一后抓向$n的$l",
        "force" : 203,
        "attack": 51,
        "dodge" : 49,
        "parry" : 22,
        "damage": 36,
        "lvl"   : 100,
        "skill_name" : "抱残守缺势" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N右腿斜插$n二腿之间，一招「紫电穿云势」，上手取目，下手反勾$n的裆部",
        "force" : 245,
        "attack": 56,
        "dodge" : 53,
        "parry" : 27,
        "damage": 41,
        "lvl"   : 140,
        "skill_name" : "紫电穿云势" ,
        "damage_type" : "抓伤"
]),
([      "action": "$N使出「破岳疾劲势」，双爪如狂风骤雨般对准$n的$l连续抓出",
        "force" : 270,
        "attack": 61,
        "dodge" : 58,
        "parry" : 38,
        "damage": 45,
        "lvl"   : 180,
        "skill_name" : "破岳疾劲势" ,
        "damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage == "claw" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "zhenyu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练破岳神爪必须空手。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候不够，无法学破岳神爪。\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练破岳神爪。\n");

        if ((int)me->query_skill("claw", 1) < 20)
                return notify_fail("你的基本爪法等级太低，无法学破岳神爪。\n");

        if ((int)me->query_skill("claw", 1) < (int)me->query_skill("poyue-zhao", 1))
                return notify_fail("你的基本爪法火候水平有限，无法领会更高深的破岳神爪。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action); i > 0; i--)
                if (level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("poyue-zhao",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("破岳神爪必须空手练习！\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练破岳神爪。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -69);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"poyue-zhao/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
