//zhongping-qiang.c 中平枪法

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N双手一别，尽力前伸，使出一招「中平无敌」，手中$w平平直出，刺向$n的$l",
		"force":		400,
                "damage":               200,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "中平无敌",
	"damage_type": "刺伤"
]),
([	"action": "$N手中$w盘旋回转，风响阵阵，屈身下蹲，反手一招「夜叉探海」自下向$n的$l刺去",
                "damage":               200,
		"force":		300,
                "dodge" : 30,
                "lvl" : 0,
	"skill_name" : "夜叉探海",
	"damage_type": "刺伤"
]),
([	"action": "$N举起$w，抖出一朵枪花，一招「灵蛇出洞」向$n分心扎去",
		"force":		100,
                "damage":               200,
                "dodge" : 50,
                "lvl" : 0,
	"skill_name" : "灵蛇出洞",
	"damage_type": "刺伤"
]),
([	"action": "$N一招「反身拿枪」，手中$w划个小圈消去$n的后招，而后$w微抬，指向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 60,
                "lvl" : 0,
	"skill_name" : "反身拿枪",
	"damage_type": "刺伤"
]),
});

int valid_enable(string usage) { return usage=="club" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练中平枪法。\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"zhong-qiang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zhong-qiang",1);
        level2= (int) me->query_skill("zhong-qiang",1);

level2= (int) me->query_skill("zhong-qiang",1);             
	if (random(3)==1 && me->query_skill("zhong-qiang",1)>300)
	{
	if( damage_bonus > 20 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N飞起一枪! 一道霸气划过了$n的$l。结果鲜血狂奔!\n"NOR;
        }
}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
