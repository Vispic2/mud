// Last Modified by Winder on May. 29 2001
// boluomi-hand.c 波罗蜜手 和寂灭爪互备 截自佛经中之“六度”。

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action":"$N双手合十做鞠，第一式"BLU"「布施式」"NOR"打出，内劲已逼得衣带翻飞，将$n层层笼罩",
	"lvl"   : 0,
	"skill_name" : "布施式"
]),
([	"action":"$N右手伸出，上翻下压，左挥右劈，在$n眼前连连变幻，这招叫做"RED"「持戒式」"NOR"，最是变化无穷",
	"lvl"   : 10,
	"skill_name" : "持戒式"
]),
([	"action":"$N低头垂肩，使"YEL"「忍辱式」"NOR"这招，对眼前$n不闻不问，暗地里却聚力双手，伺机拍出",
	"lvl"   : 20,
	"skill_name" : "忍辱式"
]),
([	"action":"$N得理不饶人，一招"GRN"「精进式」"NOR"，双臂晃动，打出片片掌影，一步步向$n进逼过去",
	"lvl"   : 40,
	"skill_name" : "精进式"
]),
([	"action":"$N一式"HIY"「禅定式」"NOR"，单臂凌空悬垂，心中平静如水，一点点向着$n顶门压将下来",
	"lvl"   : 80,
	"skill_name" : "禅定式"
]),
([	"action":"$N双臂挥动，幻出一莲花般手印，以"MAG"「般若式」"NOR"向$n推来，不紧不慢，却又凝重异常",
	"lvl"   : 100,
	"skill_name" : "般若式"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"  || usage=="unarmed";}
int valid_combine(string combo){ return combo=="jingang-strike"; }
 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练波罗蜜手必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 40)
		 return notify_fail("你的站桩功火候不够，无法学波罗蜜手。\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("你的少林弹腿和少林南拳火候不够。\n");

	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("你的一苇渡江火候不够。\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力太弱，无法练波罗蜜手。\n");
	if ((me->query_skill("qianye-shou", 1) < 40) ||
		me->query_skill("sanhua-zhang", 1) < 40)
		return notify_fail("你的千叶手和散花掌火候不够，无法学波罗蜜手。\n");
	return 1;
}
 
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练波罗蜜手。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
	int d_e2 = 25;
	int p_e1 = 20;
	int p_e2 = 65;
	int f_e1 = 510;
	int f_e2 = 610;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("boluomi-hand", 1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"boluomi-hand/" + action;
}

int help(object me)
{
	write(HIC"\n波罗蜜手："NOR"\n");
	write(@HELP

    波罗蜜手是南少林手法，和大金钢掌互备。
    出自佛经中之“六度”。

	学习要求：
		站桩功40级
		散花掌40级
		如来千叶手40级
		内力修为400
HELP
	);
	return 1;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("boluomi-hand",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->start_busy(3);
        return HIC "「般若式!!」！$N突然舞出一片掌影!! $n不知所措!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "劈!!一阵掌影！！！一股鲜血从$n的身子喷出!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("boluomi-hand", 1);

        if( damage < 10 ) return 1;

            if ( random(12) == 0 || random(level) > 150){
         msg = RED"$N面对$n的攻势。突然舞出一片掌影!!。\n"NOR;
         msg += YEL"「禅定式!」。$N手法一变，$n不知所措!!。\n"NOR;
             ob->start_busy(3);

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
