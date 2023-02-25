// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hwz
// 缘随雲
// 丐帮第十八代弟子
// 3563217
// 男性
// sword
// 缘





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，手中$w一招「缘起缘灭缘了时」对准$n的$l斜斜刺出一剑",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "缘起缘灭"
]),
// ZHAOSHI :1

([
"action" :"$N身子一斜，手中$w一招「奈何此缘却是梦」对准$n的$l画出一个半圆，剑尖直击$n的心脏",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "缘了时"
]),
// ZHAOSHI :2

([
"action" :"$N手持$w，迅速的往$n冲了过去，一招「缘定三生花结果」对准$n的$l直直刺出一剑",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "却是梦"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"缘"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("hwzsword-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
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
