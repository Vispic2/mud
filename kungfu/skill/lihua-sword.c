// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lting
// 風動梨花
// 翠蕊梨花阁　梨花仙子
// 5007289
// 女性
// sword
// 翠雨梨花





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N素手斜斜一划，雪光初闪，$n竟闻到淡淡梨花清香，恍惚间心驰神往，一朵白里透红的梨花瓣已飘到眼前。",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "【梨花惊现】"
]),
// ZHAOSHI :1

([
"action" :"$N轻吟：“有女郎携婢，拈梨花一枝，笑容可鞠，容华绝代”，漫天剑意中忽现一女子，提手若舞，然劲风凌厉直至$n，原是狐仙婴宁。",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "【素手拈花】"
]),
// ZHAOSHI :2

([
"action" :"$N玉齿微露，但觉一阵香风迎面而来，$n双眼沉重，将醉未醉之间，风中惊现四朵梨花，或绿或翠，花瓣四周竟似刀一般锋利。",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "【风动梨花】"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"翠雨梨花"+"。\n");
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
    level = (int)me->query_skill("lihua-sword",1);
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
