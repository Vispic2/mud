// chilian-shenzhang.c  赤练神掌
// 14/7/2001  Xuanyuan

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N双手一翻，两掌带着淡淡的蓝光，直向$n拍去",
	"force" : 180,
        "dodge" : 15,
        "parry" : 20,
	"damage": 250,
	"lvl" : 0,
	"skill_name" : "赤练神掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左掌虚晃，右掌直出，犹如毒蛇一般直迫$n的胸前",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 360,
	"lvl" : 10,
	"skill_name" : "赤练神掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌翻飞，四周迷茫着一股暗淡的雾气，排向$n的全身",
	"force" : 260,
        "dodge" : 115,
        "parry" : 20,
	"damage": 270,
	"lvl" : 20,
	"skill_name" : "赤练神掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两掌一分，左掌如蝎，右掌似蛇，同时向$n击过去",
	"force" : 300,
        "dodge" : 120,
        "parry" : 30,
	"damage": 280,
	"lvl" : 30,
	"skill_name" : "赤练神掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N默运内力，双掌忽然变黑，带着一股阴风只扑$n的全身",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage":300,
	"lvl" : 40,
	"skill_name" : "赤练神掌",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练赤练神掌必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练赤练神掌。\n");
	return 1;
}

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
	level   = (int) me->query_skill("chilian-shenzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 50)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练赤练神掌。\n");
        me->receive_damage("jing", 25);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
}
        neili=me->query("neili");
        neili2=victim->query("neili");
        if(random(neili)>random(neili2)){
//                message_vision(MAG"$n猛然觉得一阵寒气袭来，身子一晃，头脑微微有些发昏。\n"NOR, me, victim);
                victim->apply_condition("chilian_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("chilian_poison"));
if(me->query_skill("wudu-shengong",1)> 100)
victim->apply_condition("wuhudu_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("wuhudu_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$n忙运内力抵抗，将$N掌上的剧毒逼在体外。\n"NOR,me,victim);

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
