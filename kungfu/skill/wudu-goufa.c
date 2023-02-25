// wudu-goufa.c 五毒钩法

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"\n$N手中$w一抖，一式"+(order[random(13)])+"「灵蛇吐信」"NOR"，闪电般的疾刺向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 315,
	"lvl" : 0,
	"skill_name" : "灵蛇吐信",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一式"+(order[random(13)])+"「柔丝轻系」"NOR"，剑意绵绵不绝，化做一张无形的大网将$n困在当中",
	"force" : 240,
        "dodge" : 10,
	"damage": 325,
	"lvl" : 10,
	"skill_name" : "柔丝轻系",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一声阴笑，飞身纵起，一式"+(order[random(13)])+"「张牙舞爪」"NOR"，手中$w狂舞，幻出千万条\n手臂，合身扑向$n",
       "force" : 380,
        "dodge" : 15,
	"damage": 340,
	"lvl" : 25,
	"skill_name" : "张牙舞爪",
	"damage_type":	"刺伤"
]),
([	"action":"$N足尖点地，身形一旋看似欲走，手中$w却倏的从腋下穿过，疾刺向$n的$l,\n好一式"+(order[random(13)])+"「天蝎藏针」"NOR"",
       "force" : 480,
        "dodge" : 40,
	"damage": 350,
	"lvl" : 35,
	"skill_name" : "天蝎藏针",
	"damage_type":	"刺伤"
]),
([	"action":"$N脚步踉跄，身形忽的向前跌倒，一式"+(order[random(13)])+"「井底望月」"NOR"，掌中$w自下而上直\n刺$n的?+(order[random(13)])+"「?,
       "force" : 580,
        "dodge" : 40,
	"damage": 360,
	"lvl" : 50,
	"skill_name" : "井底望月",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形一晃，一式"+(order[random(13)])+"「金蛇缠腕」"NOR"，手中$w如附骨之蛆般无声无息地刺向$n\n的手腕",
       "force" : 680,
        "dodge" : 70,
	"damage": 380,
	"lvl" : 60,
	"skill_name" : "金蛇缠腕",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一声厉啸，身形冲天而起，一式"+(order[random(13)])+"「神蟾九变」"NOR"，掌中$w如鬼魅般连刺\n$n全身九道大穴",
	"force" : 450,
        "dodge" : 80,
	"damage": 400,
	"lvl" : 70,
	"skill_name" : "神蟾九变",
	"damage_type":	"刺伤"
]),
([	"action":"$N深吸一口起，双手握钩，招演"+(order[random(13)])+"「万毒至尊」"NOR"，$w尖端透出一条强劲的黑\n气，闪电般的袭向$n",
       "force" : 780,
        "dodge" : 45,
	"damage": 550,
	"lvl" : 80,
	"skill_name" : "万毒至尊",
	"damage_type":	"内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("你的五毒神功火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
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
	level   = (int) me->query_skill("wudu-goufa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练五毒钩法。\n");
	me->receive_damage("qi", 20);
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
if (damage_bonus <10) damage_bonus=10;
  if( random(damage_bonus/2) > victim->query_con() ) {
		victim->receive_wound("qi", damage_bonus/ 3 );
        return HIM "$n身中巨毒，闷哼一声,身子晃了两晃！\n" NOR;
	}
    if ( victim->query("family/family_name")!= "五毒教" && me->query_skill("wudu-shengong",1)>40) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
   }
}
string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
