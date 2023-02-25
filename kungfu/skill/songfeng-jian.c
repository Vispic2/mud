// sonfeng-jian.c 松风剑法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N虚步提腰，一招"MAG"「彩蝶穿花」"NOR"，手中$w轻轻颤动，一剑剑点向$n的$l",
	"lvl" : 0,
	"skill_name" : "彩蝶穿花"
]),
([	"action" : "$N向前跨上一步，左手剑诀，右手$w使出一式"HIM"「凤凰夺窝」"NOR"直刺$n的$l",
	"lvl" : 10,
	"skill_name" : "凤凰夺窝"
]),
([	"action" : "$N身形往右一挫，左手剑诀，右手$w使出一式"GRN"「分花拂柳」"NOR"刺向$n的$l",
	"lvl" : 20,
	"skill_name" : "分花拂柳"
]),
([	"action" : "$N双膝下沉，右手$w使出一式"RED"「力划鸿沟」"NOR"，由下而上疾刺$n的$l",
	"lvl" : 50,
	"skill_name" : "力划鸿沟"
]),
([	"action" : "$N一招"HIB"「颠倒阴阳」"NOR"，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"lvl" : 60,
	"skill_name" : "颠倒阴阳"
]),
([	"action" : "$N上身往左侧一拧，一招"HIW"「玉女投梭」"NOR"，右手$w反手向$n的$l挥去",
	"lvl" : 80,
	"skill_name" : "玉女投梭"
]),
([	"action" : "$N一招"BLU"「八方风雨」"NOR"，剑锋平指，一气呵成横扫$n的$l",
	"lvl" : 100,
	"skill_name" : "八方风雨"
]),
([	"action" : "$N左腿提膝，手中$w斜指，一招"HIY"「平沙落雁」"NOR"刺向$n的$l",
	"lvl" : 120,
	"skill_name" : "平沙落雁"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("qingming-xuangong", 1) < 20)
		return notify_fail("你的青冥玄功火候太浅。\n");

	if ((int)me->query_skill("chuanhua", 1) < 50)
		return notify_fail("你的穿花绕树火候太浅。\n");

	if ((int)me->query_skill("wuying-leg", 1) < 50)
		return notify_fail("你的无影腿火候太浅。\n");

	if ((int)me->query_skill("cuixin-strike", 1) < 50)
		return notify_fail("你的摧心掌火候太浅。\n");		
		
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练松风剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 10;
	int d_e2 = 35;
	int p_e1 = 20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 200;
	int m_e2 = 390;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songfeng-jian", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"songfeng-jian/" + action;

}
int help(object me)
{
	write(HIC"\n松风剑法："NOR"\n");
	write(@HELP

    松风剑法是青城派剑法。

	学习要求：
		青城基本武功50级
		青冥神功20级
		内力10
HELP
	);
	return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("songfeng-jian",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIC "「摧心诀!!」$N猛地一个侧身一闪，转到$n身后，右掌往$n后心印了下去。\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "摧心诀!! $n后心一震只觉得喉头一甜一条血丝从嘴角挂了下来！\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("songfeng-jian", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 180){
         msg = RED"$N的左足反踢而起，直撩$n的下阴！不待$n退开站稳，右足连环反踢，将$n踢得一时无法还手！\n"NOR;
         msg += RED"「撩阴脚!!」。$N如影随形的踢出几脚，$n吐出一口鲜血!!。\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
