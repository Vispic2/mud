// This program is a part of NITAN MudLIB
// yinlong-shou.c 银龙手

inherit SKILL;

mapping *action = ({
([      "action" : "$N的身行飘忽不定，如同幻影一般，闪到了$n的身后，一招「无影无踪」拍向$n的$l",
        "force" : 130,
        "dodge" : 20,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "无影无踪",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌如同龙神一般，绽放开来，正是一招「龙神探影」，击向$n的$l",
        "force" : 150,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 20,
        "skill_name" : "龙神探影",
        "damage_type" : "内伤"
]),
([      "action" : "$N身行绕着$n急速转动，忽然出掌，正是一招「飞天幻掌」打向$n的$l",
        "force" : 150,
        "dodge" : 30,
        "damage" : 35,
        "lvl" : 30,
        "skill_name" : "飞天幻掌",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌上下番飞，如同化成了千万个手掌，正是一招「九天千幻」拍向$n的$l处",
        "force" : 250,
        "dodge" : 20,
        "damage" : 10,
        "lvl" : 40,
        "skill_name" : "九天千幻",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练银龙手必须空手。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练银龙手。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yinlong-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练银龙手。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinlong-shou/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
