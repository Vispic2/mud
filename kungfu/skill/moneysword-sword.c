// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xnono
// 菩提老猪
// 火焰教　第三代弟子
// 6550749
// 男性
// sword
// 发财剑法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N左手虚晃，右手的奋力甩出，一招眨种械某そＶ毕?n的腹部扎去",
"force" :60,
"dodge" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "招财进宝"
]),
// ZHAOSHI :1

([
"action" :"$N纵身一跃，右手的$w迅速交换到左手，一招停Ｒ砸灰庀氩坏降慕嵌却滔?n的某部",
"force" :90,
"dodge" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "偷梁换柱"
]),
// ZHAOSHI :2

([
"action" :"look",
"force" :120,
"dodge" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "千山流水"
]),
// ZHAOSHI :3

([
"action" :"$N使出「万佛归宗」，手中$w挽出三个剑花，绵绵不断划向$n的左臂！",
"force" :150,
"dodge" :100,
"damage_type": "刺伤",
"lvl" : 3,
"skill_name" : "万佛归宗"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"发财剑法"+"。\n");
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
    level = (int)me->query_skill("moneysword-sword",1);
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
