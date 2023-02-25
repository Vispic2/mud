inherit SKILL;

string *dodge_msg = ({
        "$n身形微微一晃，双足连环踢出，将$N硬生生迫退。\n",
        "$n错步上前，单足忽的一抬，将$N的攻势全部挡回，只能自保。\n",
        "$n双足轻轻点地，猛的拔地而起，躲开了$N的招式。\n",
});

mapping *action = ({
([      "action" : "$N双手虚晃，左脚猛地飞起，一式「风起云涌」，脚尖踢向$n的$l",
        "force" : 80,
        "attack": 10,
        "dodge" : 45,
        "parry" : 45,
        "damage": 10,
        "lvl"   : 0,
        "damage_type" : "瘀伤",
        "skill_name" : "风起云涌"
]),
([      "action" : "$N别转身来抽身欲走，刹那间回身，右脚一式「空谷足音」猛踹$n",
        "force" : 100,
        "attack": 20,
        "dodge" : 50,
        "parry" : 50,
        "damage": 15,
        "lvl"   : 40,
        "damage_type" : "瘀伤",
        "skill_name" : "空谷足音"
]),
([      "action" : "$N右脚同时踹出，既猛且准，一式「碧渊腾蛟」，踢中的$n的胸口",
        "force" : 160,
        "attack": 30,
        "dodge" : 55,
        "parry" : 55,
        "damage": 18,
        "lvl"   : 80,
        "damage_type" : "瘀伤",
        "skill_name" : "碧渊腾蛟"
]),
([      "action" : "$N突然跃起，双足连环圈转，一式「秋风落叶」，足带风尘，攻向$n",
        "force" : 190,
        "attack": 35,
        "dodge" : 60,
        "parry" : 60,
        "damage": 20,
        "lvl"   : 120,
        "damage_type" : "瘀伤",
        "skill_name" : "秋风落叶"
]),
([      "action" : "$N两手护胸，双脚交叉踢起，一式「风扫残云」，脚脚不离$n周围",
        "force" : 220,
        "attack": 35,
        "dodge" : 70,
        "parry" : 70,
        "damage": 25,
        "lvl"   : 140,
        "damage_type" : "瘀伤",
        "skill_name" : "风扫残云"
]),
([      "action" : "$N突然侧身，右脚自上而下一式「流星坠地」，照$n的面门直劈下来",
        "force" : 260,
        "attack": 40,
        "dodge" : 90,
        "parry" : 90,
        "damage": 30,
        "lvl"   : 160,
        "damage_type" : "瘀伤",
        "skill_name" : "流星坠地"
]),
([      "action" : "$N使一式「朔风吹雪」，全身突然飞速旋转，双足迅猛无及的踹向$n",
        "force" : 290,
        "attack": 40,
        "dodge" : 100,
        "parry" : 100,
        "damage": 30,
        "lvl"   : 180,
        "damage_type" : "瘀伤",
        "skill_name" : "朔风吹雪"
]),
([      "action" : "$N抽身跃起，开声吐气，陡然一式「雷动九天」，双脚如旋风般踢向$n",
        "force" : 340,
        "attack": 45,
        "dodge" : 115,
        "parry" : 115,
        "damage": 35,
        "lvl"   : 200,
        "damage_type" : "瘀伤",
        "skill_name" : "雷动九天"
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" ||  usage == "parry" ||  usage == "dodge";
}

int valid_combine(string combo)
{
	return combo == "pikong-zhang";
}

int valid_learn(object me)
{
    	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        	return notify_fail("学习旋风扫叶腿必须空手。\n");

    	if ((int)me->query_skill("force") < 100)
        	return notify_fail("你的内功火候不够，无法学旋风扫叶腿。\n");

    	if ((int)me->query("max_neili") < 800)
        	return notify_fail("你的内力太弱，无法练旋风扫叶腿。\n");

    	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("xuanfeng-tui", 1))
        	return notify_fail("你的基本拳脚水平有限，无法领会更高深的旋风扫叶腿。\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("xuanfeng-tui", 1))
                return notify_fail("你的基本轻功水平有限，无法领会更高深的旋风扫叶腿。\n");

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
        level = (int)me->query_skill("xuanfeng-tui", 1);
        for(i = sizeof(action); i > 0; i--)
            if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    	if ((int)me->query("qi") < 60)
       		return notify_fail("你的体力太低了。\n");

    	if ((int)me->query("neili") < 60)
       		return notify_fail("你的内力不够练旋风扫叶腿。\n");

    	me->receive_damage("qi", 45);
    	me->add("neili", -51);
    	return 1;
}

string perform_action_file(string action)
{
    	return __DIR__"xuanfeng-tui/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
