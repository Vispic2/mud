#include <ansi.h>
inherit SKILL;

mapping *action = ({

([      "action": "$N手中$w中宫直进，一式「地狱道」，无声无息地对准$n的$l刺出一剑",
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,       
        "skill_name" : "地狱道",
        "damage_type": "刺伤"
]),
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{

        // 与12T冲突
        if( me->query_skill("yinyang-shiertian",1) )
                return notify_fail("你感觉体内的阴阳九转真气跌宕起伏，似乎容纳这种技能。\n");
                
        if( me->query("str")<32 )
                return notify_fail("你先天臂力不足。\n");

        if( me->query("int")<32 )
                return notify_fail("你先天悟性不足。\n");

        if( me->query("dex")<32 )
                return notify_fail("你先天身法不足。\n");
                
        if( me->query("con")<32 )
                return notify_fail("你先天根骨不足。\n");                        
                
        if( me->query("max_neili")<2000 )
                return notify_fail("你的内力修为不够，难以修炼地狱道。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功火候太浅，难以修炼地狱道。\n");

        if ((int)me->query_skill("sword", 1) < 300)
                return notify_fail("你的剑法根基不足，难以修炼地狱道。\n");
    
        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("你的武学修养不足，难以修炼地狱道。\n");
                    
        if ((int)me->query_skill("buddhism", 1) < 200)
                return notify_fail("你的禅宗心法修为不足，难以修炼地狱道。\n");
                                            
        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("diyu-dao", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的地狱道。\n");
                                                                
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("diyu-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        if (me->query_skill("diyu-dao", 1) > 180)
                return notify_fail("地狱道博大精深，无法简单的通过练习进步。\n");

        return 1;                
}

int difficult_level()
{
        return 30000;
}

string main_skill() { return "lunhui-sword"; } 