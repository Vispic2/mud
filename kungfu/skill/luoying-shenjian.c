// luoying-shenjian.c 落英神剑

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "skill_name": HIB"落英缤纷"NOR,
	"action" : "$N使一招「"+HIB+"落英缤纷"+NOR+"」，身形向上飘起，手中$w虚虚实实幻出万点剑花纷纷扬扬撒向$n$l",
	"force"  : 100,
	"parry"  : 15,
	"damage" : 40,
	"lvl"    : 0,
	"damage_type": "刺伤"
]),
([      "skill_name": HIM"人面桃花"NOR,
	"action" : "$N舞动$w，一式「"+HIM+"人面桃花"+NOR+"」，左手向$n面门一晃，右手$w抖出几朵剑花挟着虎虎剑气刺向$n的$l",
	"force"  : 150,
	"parry"  : 20,
	"damage" : 50,
	"lvl"    : 20,
	"damage_type": "刺伤"
]),
([      "skill_name": HIR"急风骤雨"NOR,
	"action" : "$N身形绕$n一转，手中$w望空一指，一式「"+HIR+"急风骤雨"+NOR+"」幻出满天剑影，向$n$l接连挥出数剑",
	"force"  : 180,
	"dodge"  : 20,
	"damage" : 60,
	"lvl"    : 40,
	"damage_type": "割伤"
]),
([      "skill_name": GRN"江城飞花"NOR,
	"action" : "$N身形飘然而起，在半空中身子一旋，悠然一式「"+GRN+"江城飞花"+NOR+"」手中$w若有若无淡淡刺向$n的$l",
	"force"  : 210,
	"dodge"  : 30,
	"damage" : 70,
	"lvl"    : 60,
	"damage_type": "刺伤"
]),
([      "skill_name": MAG"万花齐落"NOR,
	"action" : "$N纵起丈余，一招「"+MAG+"万花齐落"+NOR+"」手中$w舞成一个光球罩向$n的$l",
	"force"  : 250,
	"dodge"  : 35,
	"damage" : 80,
	"lvl"    : 80,
	"damage_type": "刺伤"
]),
([      "skill_name": CYN"漫天花雨"NOR,
	"action" : "$N一声大喝使出「"+CYN+"漫天花雨"+NOR+"」，手中$w幻出漫天花瓣，迅若奔雷射向$n的$l",
	"force"  : 280,
	"dodge"  : 35,
	"damage" : 90,
	"lvl"    : 100,
	"damage_type": "刺伤"
]),
([      "skill_name": HIY"落花无意"NOR,
	"action" : "$N轻叹一声，手中$w怀中一抱，一时「"+HIY+"落花无意"+NOR+"」，$w锵然跃出倏的化作几点带露的桃花，飘然飞向$n的$l",
	"force"  : 300,
	"dodge"  : 30,
	"damage" : 110,
	"lvl"    : 120,
	"damage_type": "刺伤"
]),

});

int valid_learn(object me)
{
	object ob;

	if ((int)me->query_skill("force") < 45)
		return notify_fail("你的内功火候还不够。\n");

	if ((int)me->query("max_neili") < 250)
		return notify_fail("你的内力不够，不能练落英神剑。\n");

	if (! objectp(ob = me->query_temp("weapon")) ||
	    (string)ob->query("skill_type") != "sword")
		return notify_fail("你必须先找一把剑才能学习剑法。\n");
	 if (me->query_skill("sword",1) <= me->query_skill("luoying-shenjian",1) )
	return notify_fail("你的基本剑法不够，无法领会更高深的落英神剑。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int)me->query_skill("luoying-shenjian", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}

int practice_skill(object me)
{
	object ob;

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低，没有办法练习落英神剑。\n");

	if ((int)me->query("neili") < 35)
		return notify_fail("你的内力不够，没有办法练习落英神剑。\n");

	if (! objectp(ob = me->query_temp("weapon")) ||
	    (string)ob->query("skill_type") != "sword")
		return notify_fail("你必须先找一把剑才能习练剑法。\n");

	me->receive_damage("qi", 45);
	me->add("force", -41);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
