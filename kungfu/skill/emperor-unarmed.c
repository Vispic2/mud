// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xlssi
// 笑莫问
// 采花小贼
// 8556053
// 男性
// unarmed
// 皇拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一招始皇定天下,双拳平平推向$n的上中下三路,脸上不怒自威,大有横扫六合,平定四方的霸气",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "始皇定天下"
]),
// ZHAOSHI :1

([
"action" :"$N眼中精光大闪,一式高祖斩白蛇,化拳为掌,挟这一股沛不可御内劲,切向$n的$l",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "高祖斩白蛇"
]),


// ZHAOSHI :2

([
"action" :"$N左掌击向右拳,左右互博,忽然双手齐出,攻向$n的$l,一式孟德斗玄德令人耳晕目眩,无从招架.",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "孟德斗玄德"
]),
// ZHAOSHI :3

([
"action" :"$N一式文帝事稼禾,面露慈祥之色,双手缓缓向$n攻去,充满怀柔天下之意",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "文帝事稼禾"
]),
// ZHAOSHI :4

([
"action" :"$N的出手忽然全无半点余地,遇神杀神,遇佛战佛,令$n不寒而慄,这正是?,
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "太宗起玄武"
]),
// ZHAOSHI :5

([
"action" :"$N双腿旋转如风,一招宋太祖棍打天下,$n方圆数丈皆被腿风包围",
"force" :210,
"damage" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "棍打天下"
]),
// ZHAOSHI :6

([
"action" :"$N化腿为箭,直插$n的$l,一式弯弓射雕充满着成吉思汗平定天下的狂傲",
"force" :240,
"damage" :160,
"damage_type": "瘀伤",
"lvl" : 6,
"skill_name" : "弯弓射雕"
]),
// ZHAOSHI :7

([
"action" :"忽然天地一片萧杀,$N的朱元璋杀意已然发动,无数杀气内劲直冲$n的$l",
"force" :270,
"damage" :180,
"damage_type": "瘀伤",
"lvl" : 7,
"skill_name" : "杀意"
]),
// ZHAOSHI :8

([
"action" :"$N的内息流转全身,无处发泄,大喝一声,无意中使出了皇拳的不谜之传----康乾盛世,",
"force" :300,
"damage" :200,
"damage_type": "瘀伤",
"lvl" : 8,
"skill_name" : "康乾盛世"
]),
// ZHAOSHI :9

([
"action" :"$N发前人未发,创出了自己的皇拳,快意无比,一拳轰向$n的$l",
"force" :330,
"damage" :220,
"damage_type": "瘀伤",
"lvl" : 9,
"skill_name" : "皇拳"
]),
// ZHAOSHI :10

([
"action" :"$N一招君,皇道霸气冲天而出,直指$n",
"force" :360,
"damage" :240,
"damage_type": "瘀伤",
"lvl" : 10,
"skill_name" : "君"
]),
// ZHAOSHI :11

([
"action" :"$N一招临,$n只觉得$N的气势无处不在,正惊讶时,身上已中数招",
"force" :390,
"damage" :260,
"damage_type": "瘀伤",
"lvl" : 11,
"skill_name" : "临"
]),
// ZHAOSHI :12

([
"action" :"$N一招天,已经和天地化为一体,无缝无隙,漫天掌力罩向$n",
"force" :420,
"damage" :280,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "天"
]),
// ZHAOSHI :13

([
"action" :"$N一招下,身形拔高数丈,借下落之势,双拳轰向$n的顶门",
"force" :450,
"damage" :300,
"damage_type": "瘀伤",
"lvl" : 13,
"skill_name" : "下"
]),
// ZHAOSHI :14

([
"action" :"$N低头冥想，一招号,由内力发出,震向$n",
"force" :480,
"damage" :320,
"damage_type": "瘀伤",
"lvl" : 14,
"skill_name" : "号"
]),
// ZHAOSHI :15

([
"action" :"$N一招令双掌晃出千万掌影将$n的$l笼罩在掌力之下",
"force" :510,
"damage" :340,
"damage_type": "瘀伤",
"lvl" : 15,
"skill_name" : "令"
]),
// ZHAOSHI :16

([
"action" :"$N错步上前，一招众,招招抢先，以快打慢，一个转身已经转到了$n的身后，运指如风点向$n的全身要穴",
"force" :540,
"damage" :360,
"damage_type": "瘀伤",
"lvl" : 16,
"skill_name" : "众"
]),
// ZHAOSHI :17

([
"action" :"$N一招生,$n本无退路,忽然$N让出生门一丝",
"force" :570,
"damage" :380,
"damage_type": "瘀伤",
"lvl" : 17,
"skill_name" : "生"
]),
// ZHAOSHI :18

([
"action" :"$N一招天下无敌,双拳轰向$n的$l",
"force" :600,
"damage" :400,
"damage_type": "瘀伤",
"lvl" : 18,
"skill_name" : "天下无敌"
]),
// ZHAOSHI :19

([
"action" :"$N一招武后理朝,做女人状,$n看在眼里,心中一阵恶心,已经中了严重内伤",
"force" :630,
"damage" :420,
"damage_type": "瘀伤",
"lvl" : 19,
"skill_name" : "武后理朝"
]),
 });
// ZHAOSHI :20
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"皇拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"皇拳"+"。\n");
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
    level = (int)me->query_skill("emperor-unarmed",1);
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
