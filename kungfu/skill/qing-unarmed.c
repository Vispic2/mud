// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// 秋意浓
// [35m终南第一女侠[2;37;0m
// 11768727
// 女性
// unarmed
// 秋意掌法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N使出一式「秋雁南回」，一道白光已到$n眼眉，接着$N身形一转，再一式「黄叶仍风雨」，$n全身都笼罩在剑气中。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "秋雁南回"
]),
// ZHAOSHI :1

([
"action" :"只见$N姿势一变，顿时身形若隐若现，「秋意更深」、「北风江上寒」两式接连发出，双掌寒气逼人，$n已无退路",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "秋意更深"
]),
// ZHAOSHI :2

([
"action" :"$N在半空一个漂亮的回旋，接连两式「秋帘梦长」发出，招未至，人已如烟，力已至。一道绿光穿过$n身体",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "秋帘梦长"
]),
// ZHAOSHI :3

([
"action" :"只见$N的身形在空中划出一道优美的弧线，一式「秋叶飘零」，连续拍出九九八十一掌，漫天掌影飘如黄叶飞落，$n被那瞬间的绚美惊呆了",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "秋叶飘零"
]),
// ZHAOSHI :4

([
"action" :"$N低叹一声，单掌微微一扫，一式「秋风乍起」拂出。$n顿时感到天地凄凉，世事琐刹，人生了无生趣，不由身形慢了下来",
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "秋风乍起"
]),
// ZHAOSHI :5

([
"action" :"$N感慨无数，放弃防守，双掌轮挥，秋意掌法二十四式终极招术「秋寒依然」发出，此亦一时，左手往$n左肋下打出三掌，彼亦一时，右手往$n右肋再出三掌",
"force" :210,
"damage" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "秋寒依然"
]),
// ZHAOSHI :6

([
"action" :"$N一招「秋影随形」，左腿踢出，$n却还在三丈开外，但见$N瞬间前移三丈，腿已击到$n胸口，左腿未落右腿又出，一道劲风扫过$n门面",
"force" :240,
"damage" :160,
"damage_type": "瘀伤",
"lvl" : 6,
"skill_name" : "秋影随形"
]),
// ZHAOSHI :7

([
"action" :"但见漫天腿影飞舞，$n的衣衫已被腿风撕成一片片，散落地上，$N身形一跃，一式「往事随风」，半空中左右腿接连踢往$n胸口",
"force" :270,
"damage" :180,
"damage_type": "瘀伤",
"lvl" : 7,
"skill_name" : "往事随风"
]),
// ZHAOSHI :8

([
"action" :"「再扫落叶」！$N左腿横扫$n脑门，$n慌忙中低头避过，但发髻已被扫落，狼狈不堪，但见$N背对$n，躬身弯腰右腿往后一个弯月型反扫，脚底板直击$n下巴",
"force" :300,
"damage" :200,
"damage_type": "瘀伤",
"lvl" : 8,
"skill_name" : "再扫落叶"
]),
// ZHAOSHI :9

([
"action" :"$N的身形在半空急速旋转，蓦然一个旋转，仿佛凤凰陧磐，天！随！人！愿！$N左脚已经踩上$n的胸口，右脚却直踢脑盖，看来要是被踢中，$n非颠即傻",
"force" :330,
"damage" :220,
"damage_type": "瘀伤",
"lvl" : 9,
"skill_name" : "天随人愿"
]),
// ZHAOSHI :10

([
"action" :"忽然，天地间一片寂静，$N一头飞舞的长发在脑后静静散落，小鱼正纳闷，春！随！人！意！$N的长发再次飘了起来，$n竟没看清楚$N的出脚",
"force" :360,
"damage" :240,
"damage_type": "瘀伤",
"lvl" : 10,
"skill_name" : "春随人意"
]),
// ZHAOSHI :11

([
"action" :"只见$N一头长发在脑后飞舞不停，身影飘忽间，秋！随！我！意！接连踢出一十八腿，$n一阵昏眩，却只见$N在原地双手合十，仿佛天上地下，唯秋独尊",
"force" :390,
"damage" :260,
"damage_type": "瘀伤",
"lvl" : 11,
"skill_name" : "秋随我意"
]),
// ZHAOSHI :12

([
"action" :"$n已生怯意，正想逃跑，$N大喝一声：“鼠辈！大胆！”，一招「缺月挂疏桐」，五指张开，直抓$n的天灵盖",
"force" :420,
"damage" :280,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "缺月挂疏桐"
]),
// ZHAOSHI :13

([
"action" :"$n眼看败局已定，正叽叽歪歪中，$N一声喝断：“闭嘴！！”，一式「漏断人初静」，往$n左脸一个耳光聒去",
"force" :450,
"damage" :300,
"damage_type": "瘀伤",
"lvl" : 13,
"skill_name" : "漏断人初静"
]),
// ZHAOSHI :14

([
"action" :"$n往后一跃，已逃到三丈开外，$N一式「幽人独往来」，瞬间拦在$n面前：“没出息！！”，犀利一指点到$n眉间",
"force" :480,
"damage" :320,
"damage_type": "瘀伤",
"lvl" : 14,
"skill_name" : "幽人独往来"
]),
// ZHAOSHI :15

([
"action" :"$N迈起绝世步法「飘渺孤鸿影」，瞬间围绕$n急转九九八十一圈，$n一阵眼花缭乱，晕倒在地",
"force" :510,
"damage" :340,
"damage_type": "瘀伤",
"lvl" : 15,
"skill_name" : "飘渺孤鸿影"
]),
// ZHAOSHI :16

([
"action" :"$N提起真气，施出绝世轻功「惊起却回头」，瞬间在$n身前身后移动，$n一阵昏眩，呕吐起来",
"force" :540,
"damage" :360,
"damage_type": "瘀伤",
"lvl" : 16,
"skill_name" : "惊起却回头"
]),
// ZHAOSHI :17

([
"action" :"$N逆转体内真气，天地骤冷，“去死吧！！！”，$N一式「寂寞沙洲冷」，全部真气化作一股强大的气流，直扑$n",
"force" :570,
"damage" :380,
"damage_type": "瘀伤",
"lvl" : 17,
"skill_name" : "寂寞沙洲冷"
]),
 });
// ZHAOSHI :18
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"秋意掌法"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"秋意掌法"+"。\n");
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
    level = (int)me->query_skill("qing-unarmed",1);
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
