//fumozhang.c 【伏魔掌】by yushu@SHXY
//2000/11
inherit SKILL;
#include <ansi.h>
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
        ([      "action":
"$N前腿踢出，后腿脚尖点地，一式"HIC"「伏魔天下」"NOR"，二掌直出，攻向$n的上中下三路",
        "lvl" : 0,
        "skill_name" : "伏魔天下"

        ]),
        ([      "action":
"$N左掌划一半圆，一式"HIR"「铁血丹心」"NOR"，右掌斜穿而出，疾拍$n的胸前大穴",
        "lvl" : 30,
        "skill_name" : "铁血丹心"
        ]),
        ([      "action":
"$N使一式"HIM"「荡尽群魔」"NOR"，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "lvl" : 60,
        "skill_name" : "荡尽群魔"

        ]),
        ([      "action":
"$N左掌护胸，右拳凝劲后发，一式"HIY"「横空出世」"NOR"，缓缓推向$n的$l",
        "lvl" : 90,
        "skill_name" : "横空出世"
        ]),
        ([      "action":
"$N使一式"HIG"「力拔千钧」"NOR"，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
        "lvl" : 120,
        "skill_name" : "力拔千钧"

        ]),
        ([      "action":
"$N合掌抱球，猛吸一口气，一式"HIW"「群魔伏首」"NOR"，双掌疾推向$n的肩头",
        "lvl" : 150,
        "skill_name" : "群魔伏首"

        ]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
   int level; 

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练伏魔掌必须空手。\n");

        if( me->query("int")<30 )
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if( me->query("dex")<30 )
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

        if( me->query("con")<30 )
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");

        if( me->query("str")<30 )
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

         level = me->query_skill("fumozhang", 1);

   if ((int)me->query_skill("unarmed", 1) < 180)
               return notify_fail("你的基本拳脚火候不够，无法学习伏魔掌。\n");

       if ((int)me->query_skill("unarmed", 1) < level)
               return notify_fail("你的基本拳脚水平有限，无法领会更高深的伏魔掌。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = -30;
        int d_e2 = -20;
        int p_e1 = -10;
        int p_e2 = 5;
        int f_e1 = 260;
        int f_e2 = 320;
        int a_e1 = me->query_skill("fumozhang", 1);
        int a_e2 = me->query_skill("fumozhang", 1);

        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("fumozhang", 1);
        seq = random(ttl);       /* 选择出手招数序号 */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "attack"       : a_e1 + (a_e2 - a_e1) * seq / ttl,
                "damage"       : a_e1 + (a_e2 - a_e1) * seq / ttl,
                "damage_type" : random(2) ? "内伤" : "瘀伤",
        ]);
}
int practice_skill(object me)
{
	    return notify_fail("伏魔掌只能用学(learn)的来增加熟练度。\n");
}
string perform_action_file(string action)
{
        return __DIR__"fumozhang/" + action;
}