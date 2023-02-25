// taiji-quan.c 太极拳 
// 增加不同技能级别相应的学习和能使出的招数名, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
// Updated by Doing

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「"+RED+"揽雀尾"+NOR+"」，双手划了个半圈，按向$n的$l",
	"force" : 20,
	"dodge" : 50,
	"parry" : 38,
	"skill_name" : RED"揽雀尾"NOR,
	"lvl" : 0,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「"+GRN+"单鞭"+NOR+"」，左手向外挥出，劈向$n的$l",
	"force" : 25,
	"dodge" : 48,
	"parry" : 57,
	"skill_name" : GRN"单鞭"NOR,
	"lvl" : 5,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「"+YEL+"提手上式"+NOR+"」，向$n的$l打去",
	"force" : 25,
	"dodge" : 46,
	"parry" : 49,
	"skill_name" : YEL"提手上式"NOR,
	"lvl" : 10,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手划弧，使一招「"+HIC+"白鹤亮翅"+NOR+"」，分击$n的面门和$l",
	"force" : 25,
	"dodge" : 44,
	"parry" : 71,
	"skill_name" : HIC"白鹤亮翅"NOR,
	"lvl" : 15,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身体微转，使一招「"+HIW+"搂膝拗步"+NOR+"」，击向$n的$l",
	"force" : 25,
	"dodge" : 44,
	"parry" : 58,
	"skill_name" : HIW"搂膝拗步"NOR,
	"lvl" : 20,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手由下上挑，右手内合，一招「"+MAG+"手挥琵琶"+NOR+"」，向$n的$l打去",
	"force" : 30,
	"dodge" : 48,
	"parry" : 62,
	"skill_name" : MAG"手挥琵琶"NOR,
	"lvl" : 25,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右拳由肘下穿出，一招「"+RED+"肘底看锤"+NOR+"」，锤向$n的$l",
	"force" : 30,
	"dodge" : 54,
	"parry" : 71,
	"skill_name" : RED"肘底看锤"NOR,
	"lvl" : 30,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚前踏半步，右手使一招「"+YEL+"海底针"+NOR+"」，指由下向$n的$l戳去",
	"force" : 30,
	"dodge" : 76,
	"parry" : 65,
	"skill_name" : YEL"海底针"NOR,
	"lvl" : 35,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N招「"+GRN+"闪通臂"+NOR+"」，左脚一个弓箭步，右拳向$n的$l挥去",
	"force" : 30,
	"dodge" : 79,
	"parry" : 76,
	"skill_name" : GRN"闪通臂"NOR,
	"lvl" : 40,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N两手由相对，右手使一招「"+HIC+"斜飞式"+NOR+"」，挥向$n的$l",
	"force" : 35,
	"dodge" : 82,
	"parry" : 52,
	"skill_name" : HIC"斜飞式"NOR,
	"lvl" : 45,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右手使一招「"+YEL+"白蛇吐信"+NOR+"」，向$n的$l插去",
	"force" : 35,
	"dodge" : 70,
	"parry" : 82,
	"skill_name" : YEL"白蛇吐信"NOR,
	"lvl" : 50,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「"+HIC+"双峰贯耳"+NOR+"」打向$n的$l",
	"force" : 35,
	"dodge" : 88,
	"parry" : 51,
	"skill_name" : HIC"双风贯耳"NOR,
	"lvl" : 55,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记「"+WHT+"指裆锤"+NOR+"」击向$n的裆部",
	"force" : 40,
	"dodge" : 86,
	"parry" : 71,
	"skill_name" : WHT"指裆锤"NOR,
	"lvl" : 60,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N施出「"+MAG+"伏虎式"+NOR+"」，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 40,
	"dodge" : 84,
	"parry" : 81,
	"skill_name" : MAG"伏虎式"NOR,
	"lvl" : 65,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N由臂带手，缓缓划过，一招「"+RED+"云手"+NOR+"」，挥向$n的$l",
	"force" : 45,
	"dodge" : 82,
	"parry" : 87,
	"skill_name" : RED"云手"NOR,
	"lvl" : 70,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左腿收起，右手使一招「"+YEL+"金鸡独立"+NOR+"」，向$n的$l击去",
	"force" : 50,
	"dodge" : 90,
	"parry" : 51,
	"skill_name" : YEL"金鸡独立"NOR,
	"lvl" : 75,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右手由钩变掌，双手掌心向上，推出一招「"+HIC+"高探马"+NOR+"」",
	"force" : 55,
	"dodge" : 68,
	"parry" : 90,
	"skill_name" : HIC"高探马"NOR,
	"lvl" : 80,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右手使一式招「"+MAG+"玉女穿梭"+NOR+"」，扑身向$n的$l插去",
	"force" : 60,
	"dodge" : 76,
	"parry" : 92,
	"skill_name" : MAG"玉女穿梭"NOR,
	"lvl" : 85,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右手经腹前撇出，使一招「"+HIG+"反身撇锤"+NOR+"」，向$n的$l锤去",
	"force" : 65,
	"dodge" : 84,
	"parry" : 95,
	"skill_name" : HIG"反身撇锤"NOR,
	"lvl" : 90,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右腿使一招「"+HIB+"反身蹬腿"+NOR+"」，向$n的$l踢去",
	"force" : 70,
	"dodge" : 42,
	"parry" : 99,
	"skill_name" : HIB"反身蹬腿"NOR,
	"lvl" : 100,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手向上划弧，右手使一招「"+RED+"白蛇吐信"+NOR+"」，向$n的$l锤去",
	"force" : 75,
	"dodge" : 81,
	"parry" : 102,
	"skill_name" : RED"白蛇吐信"NOR,
	"lvl" : 120,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「"+YEL+"栽锤"+NOR+"」，左手搂左膝，右手向下锤向$n的$l",
	"force" : 80,
	"dodge" : 88,
	"parry" : 115,
	"skill_name" : YEL"栽锤"NOR,
	"lvl" : 140,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手先抱成球状，，一招「"+MAG+"野马分鬃"+NOR+"」，向$n的$l和面门打去",
	"force" : 85,
	"dodge" : 86,
	"parry" : 119,
	"skill_name" : MAG"野马分鬃"NOR,
	"lvl" : 160,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手由胸前向下，右臂微曲，一招「"+HIC+"抱虎归山"+NOR+"」，向$n的$l推去",
	"force" : 90,
	"dodge" : 94,
	"parry" : 115,
	"skill_name" : HIC"抱虎归山"NOR,
	"lvl" : 180,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手于胸前，成十字状，一式「"+HIY+"十字手"+NOR+"」，向$n的$l打去",
	"force" : 95,
	"dodge" : 102,
	"parry" : 122,
	"skill_name" : HIY"十字手"NOR,
	"lvl" : 200,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚踏虚步，双手交成十字拳，一招「"+HIM+"进步七星"+NOR+"」，向$n的$l锤去",
	"force" : 100,
	"dodge" : 110,
	"parry" : 133,
	"skill_name" : HIM"进步七星"NOR,
	"lvl" : 210,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身体向后腾出，使一招「"+HIG+"倒撵猴"+NOR+"」，向$n的$l和面门打去",
	"force" : 115,
	"dodge" : 132,
	"parry" : 121,
	"skill_name" : HIG"倒撵猴"NOR,
	"lvl" : 220,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N以腰为轴，一招「"+HIC+"转身摆莲"+NOR+"」，将$n笼罩掌影之中",
	"force" : 120,
	"dodge" : 154,
	"parry" : 145,
	"skill_name" : HIC"转身摆莲"NOR,
	"lvl" : 230,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，拳意如箭，一招「"+HIR+"弯弓射虎"+NOR+"」，直奔$n心窝而去",
	"force" : 115,
	"dodge" : 166,
	"parry" : 175,
	"skill_name" : HIR"弯弓射虎"NOR,
	"lvl" : 240,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手推出，一招「"+GRN+"如封似闭"+NOR+"」，一股劲风直逼$n",
	"force" : 120,
	"dodge" : 178,
	"parry" : 185,
	"skill_name" : GRN"如封似闭"NOR,
	"lvl" : 250,
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_combine(string combo)
{
	return combo == "wudang-zhang" || combo == "paiyun-shou";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");

	if ((int)me->query_skill("force") < 180)
		return notify_fail("你的内功火候不够，无法学太极拳。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练太极拳。\n");

	if ((int)me->query_skill("unarmed", 1) < 100)
		return notify_fail("你的基本拳脚火候不够，无法学太极拳。\n");

	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("taiji-quan", 1))
		return notify_fail("你的基本拳脚水平有限，无法领会更高深的太极拳。\n");

	return 1;
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
	level = (int) me->query_skill("taiji-quan", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 5, level / 5)];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if ((int)me->query_skill("taiji-quan", 1) < 100 ||
	    ! living(me) || me->query_temp("weapon"))
		return;

	mp = ob->query_skill("count", 1);
	ap = ob->query_skill("force") + mp;
	dp = me->query_skill("parry", 1) / 2 +
	     me->query_skill("taiji-quan", 1);

	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIC "$n" HIC "面含微笑，双手齐出，划出了"
					    "一个圆圈，竟然让$N" +
					    HIC "的攻击全不着力。"NOR"\n"]);
			break;

		case 1:
			result += (["msg" : HIC "$n" HIC "左右格档，使出四两拨千斤的手法，"
					    "化解$N" HIC "的攻势于无形。"NOR"\n"]);
			break;

		default:
			result += (["msg" : HIC "$n" HIC "慢慢出拳"
					    HIC "，动作虽然缓慢，却让$N"
					    HIC "感到浑身粘滞，甚不舒畅。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(3))
		{
		case 0:
			result = HIY "$n" HIY "面含微笑，双手齐出，划出了"
				 "一个圆圈，然而$N" +
				 HIY "理也不理，随手挥招直入，进袭$n"
				 HIY "！"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "左右格档，使出四两拨千斤的手法，"
				 "可是$N" HIY "攻势却是变化无方，不遵循常理。"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "慢慢出拳"
				 HIY "，动作缓慢却让$N"
				 HIY "感到粘滞，可是$N"
				 HIY "立刻变化节奏，出奇招快速进击$n"
				 HIY "！"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("taiji-quan", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练太极拳。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -80);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
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
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
