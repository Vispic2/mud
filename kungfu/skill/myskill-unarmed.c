// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wall
// 天籁绝音
// 桃花岛第二代弟子
// 3205831
// 男性
// unarmed
// 将进酒





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N突地腾空而起,吟出一首李白的将进酒。“君不见,黄河之水天上来......”一式?空中掌影如黄河浪涛一样涌向$n的上三路.",
"force" :60,
"dodge" :40,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "君不见"
]),
// ZHAOSHI :1

([
"action" :"$N撤身回走,却凝神聚气游走全身上下,一股白色气体笼罩全身上下,$N突地双手向前疾退,使出一式薄Ａ降腊缘赖木⑵?n的头部击去.",
"force" :90,
"dodge" :60,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "悲白发"
]),
// ZHAOSHI :2

([
"action" :"$N看准空隙,向后一跃,随着将进酒的第三句“人生得意需尽欢,莫使金樽空对月”使出第三式浚趾铣删俦?由下而上拍向$n的胸口.",
"force" :120,
"dodge" :80,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "空对月"
]),
// ZHAOSHI :3

([
"action" :"$N一招「燕子三抄水」纵身跃起，倏忽已落至$n身后。双手疾拂,喝一声“天生我材必有用,千金散尽还复来.”掌力一层一层的推向$n的背部.正是一式?",
"force" :150,
"dodge" :100,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "还复来"
]),
// ZHAOSHI :4

([
"action" :"$N面露微笑,似乎看穿人世间的一切,$n正觉奇怪之时,一招?一股强劲的内力绵绵不断已攻向$n的下三盘,$n却不知$N何时出招.$N喃喃念道“烹羊宰牛且为乐,会须一饮三百杯”.",
"force" :180,
"dodge" :120,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "且为乐"
]),
// ZHAOSHI :5

([
"action" :"$N手做杯状，将前几式和而为一，各招互补，一式「将进酒」，$N郎声念道：“岑夫子，丹丘生，将进酒，君莫停！”$n只觉此招威力巨大，正犹豫之时，几股强劲掌力已经攻向$n的全身上下",
"force" :210,
"dodge" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "将进酒"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"将进酒"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"将进酒"+"。\n");
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
    level = (int)me->query_skill("myskill-unarmed",1);
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
