// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hwz
// 缘随雲
// 丐帮第十八代弟子
// 3563217
// 男性
// unarmed
// 缘





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「缘起缘灭缘了时」，二掌直出，攻向$n的上中下三路",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "缘起缘灭"
]),
// ZHAOSHI :1

([
"action" :"$N纵身一跃，一招「奈何此缘却是梦」对准$n的$l直直击出一拳",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "缘了时"
]),
// ZHAOSHI :2

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「花开花谢花了时」，二掌直出，攻向$n的上中下三路",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "奈何此缘"
]),
// ZHAOSHI :3

([
"action" :"$N双手迅速的画出一个半圆，后腿脚尖点地，一式「缘定三生花结果」，二掌直出，攻向$n的心脏",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "却是梦"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"缘"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"缘"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("hwz-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
