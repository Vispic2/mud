// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// anima
// 侯希风
// 桃花岛第二代弟子
// 3485243
// 男性
// sword
// 花间十二支





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N仿佛置身于血雨腥风之外,嘴角露出一个可迷倒天下所有人的微笑,$n看呆了,电光火石间,$n以被$N手中$w刺中某部",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "花间戏貂蝉"
]),
// ZHAOSHI :1

([
"action" :"$w临空飞起在空中画出一个六芒星阵,与此同时,$N狂运魔攻,瞬间将功力提升至顶峰,$n感觉自己仿佛置身于阿鼻地狱不能动弹,$w雷霆万钧的射穿$n的胸膛.",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "六芒星阵"
]),
// ZHAOSHI :2

([
"action" :"魔功的范围还在不断扩大,$N和手中的$w已化作地狱的勾魂使者,$n身上又多添了数道伤口.",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "魔影深锁"
]),
// ZHAOSHI :3

([
"action" :"$w冲天而起,消失得无影无踪....,$n和$N瞬间交手了八拳十二腿,似乎势均力敌,可就在这最要命的关头$w如堕落天使般从天而降刺穿$n的脑门.",
"force" :150,
"damage" :100,
"damage_type": "刺伤",
"lvl" : 3,
"skill_name" : "堕落天使"
]),
// ZHAOSHI :4

([
"action" :"$w再次从$N手中飞出,快!$n以为$N故伎重演,暗运内功准备接这雷霆一击,$w快,$N更快!!!一只灌满魔功的黑手压向$n胸膛,击破护体真气,同是$w插如胸口.",
"force" :180,
"damage" :120,
"damage_type": "刺伤",
"lvl" : 4,
"skill_name" : "谁最快"
]),
// ZHAOSHI :5

([
"action" :"無閒有三,时無閒,空無閒,受者無閒,犯五逆界者,永堕此狱,尽受终级之無閒.$N如判管一样看着$w几乎摧毁了$n.",
"force" :210,
"damage" :140,
"damage_type": "刺伤",
"lvl" : 5,
"skill_name" : "无间道"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"花间十二支"+"。\n");
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
    level = (int)me->query_skill("flowers-sword",1);
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
