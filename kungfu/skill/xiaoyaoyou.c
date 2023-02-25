// xiaoyaoyou.c 逍遥游
// modified by Venus Oct.1997
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
    "$n一个「蜻蜓点水」，躲过了$N这一招。\n",
    "$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。\n",
    "$n使出「虚怀若谷」，恰好躲过了$N的攻势。\n"
    "但是$n身形飘忽，轻轻一纵，早已避开。\n",
    "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

mapping *action = ({
([  "action": "$N一掌轻出，一招「清风斜雨」直袭$n的$l，了无半点痕迹",
    "force" : 30,
    "dodge" : 30,
    "lvl" : 0,
    "skill_name" : "清风斜雨",
    "damage_type" : "瘀伤"
]),
([  "action": "$N转过身来，正是一招「垂钓江畔」，左脚轻点，右掌挥向$n的脸部",
    "force" : 50,
    "dodge" : 40,
    "damage" : 5,
    "lvl" : 10,
    "skill_name" : "垂钓江畔",
    "damage_type" : "瘀伤"
]),
([  "action": "$N虚步侧身，一招「落叶雅意」，手腕一转，劈向$n",
    "force" : 60,
    "dodge" : 45,
    "damage" : 10,
    "lvl" : 20,
    "skill_name" : "落叶雅意",
    "damage_type" : "瘀伤"
]),
([  "action": "$N一招「归路未晓」，双掌化作无数掌影，轻飘飘的拍向$n",    
    "force" : 70,
    "dodge" : 55,
    "damage" : 15,
    "lvl" : 34,
    "skill_name" : "归路未晓",
    "damage_type" : "瘀伤"
]),
([  "action": "$N一招「春风拂柳」，左掌手指微微张开，拂向n的手腕",    
    "force" : 90,
    "dodge" : 70,
    "damage" : 20,
    "lvl" : 45,
    "skill_name" : "春风拂柳",
    "damage_type" : "瘀伤"
]),
([  "action": "$N转身侧头，轻轻一笑，使出一招「逍遥世间」，一掌拍出，仿佛不食半点人间烟火",  
    "force" : 110,
    "dodge" : 75,
    "damage" : 25,
    "lvl" : 59,
    "skill_name" : "逍遥世间",
    "damage_type" : "瘀伤"
]),
([  "action": "$N身形飘忽，一招「我心犹怜」，双掌软绵绵的拍向$n",
    "force" : 120,
    "dodge" : 80,
    "damage" : 30,
    "lvl" : 80,
    "skill_name" : "我心犹怜",
    "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage)
{
    return (usage == "dodge") ||
	   (usage == "parry") ||
	   (usage == "strike") ||
	   (usage == "move");
}

int valid_learn(object me) { return 1; }

int valid_combine(string combo) { return combo=="jueming-tui"; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
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

    	level = (int)me->query_skill("xiaoyaoyou", 1);
    	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 50)
	return notify_fail("你的体力太差了，不能练逍遥游。\n");

    if ((int)me->query("neili") < 30)
	return notify_fail("你的内力太差了，不能练逍遥游。\n");

    me->receive_damage("qi", 40);
    me->add("neili", -13);
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
