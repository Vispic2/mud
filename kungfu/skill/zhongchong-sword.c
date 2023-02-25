// six-fingers.c 六脉神剑 - 中冲剑
#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([ "name":   "中冲剑",
	   "action": "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，"
		     "无形剑气直指$n的$l",
	   "force":  490,
	   "dodge":  -15,
	   "damage": 110,
	   "damage_type": "刺伤"
	]),
});

string main_skill() { return "six-finger"; }

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练中冲剑必须空手。\n");

	if ((int)me->query("max_neili") < 2250)
		return notify_fail("你的内力太弱，无法学中冲剑。\n");

	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("zhongchong-sword", 1))
		return notify_fail("你的基本指法水平有限，无法无法领会更高深的中冲剑。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action); i > 0; i--)
		if (level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
	object* ob, obj;
	int i, skill, damage;

	if ((int)me->query_skill("six-finger", 1))
		return notify_fail("你已经学齐六脉神剑了。\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的内力不够练中冲剑。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -80);
	return 1;
}
					  
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/4) > victim->query_str() )
	{
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！"NOR"\n";
	}
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
