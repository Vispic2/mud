// dragon-strike.c 降龙十八掌
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N双掌平平提到胸前，神色沉重的缓缓施出「"+HIY+"亢龙有悔"+NOR+"」推向$n的$l",
	"force"  : 640,
	"attack" : 220,
	"dodge"  : 10,
	"parry"  : 100,
	"damage" : 130,
	"skill_name" : HIY"亢龙有悔"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N突然身形飞起，双掌居高临下一招「"+HIB+"飞龙在天"+NOR+"」拍向$n的$l",     
	"force"  : 580,
	"attack" : 200,
	"dodge"  : 5,
	"parry"  : 80,
	"damage" : 100,
	"skill_name" : HIB"飞龙在天"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N右掌一招「"+HIG+"见龙在田"+NOR+"」，迅捷无比地劈向$n的$l",
	"force"  : 520,
	"attack" : 150,
	"dodge"  : 40,
	"parry"  : 145,
	"damage" : 100,
	"skill_name" : HIG"见龙在田"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N双掌施出一招「"+HIC+"鸿渐于陆"+NOR+"」，隐隐带着风声拍向$n的$l",
	"force"  : 560,
	"attack" : 180,
	"dodge"  : 15,
	"parry"  : 130,
	"damage" : 110,
	"skill_name" : HIC"鸿渐于陆"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N左掌聚成拳状，右掌一招「"+HIM+"潜龙勿用"+NOR+"」缓缓推向$n的$l",
	"force"  : 580,
	"attack" : 190,
	"dodge"  : 10,
	"parry"  : 130,
	"damage" : 90,
	"skill_name" : HIM"潜龙勿用"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N施出一招「"+GRN+"利涉大川"+NOR+"」，右掌插腰，左掌劈向$n的$l",
	"force"  : 550,
	"attack" : 150,
	"dodge"  : 20,
	"parry"  : 180,
	"damage" : 110,
	"skill_name" : GRN"利涉大川"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+HIR+"突如其来"+NOR+"」，右掌从不可能的角度向$n的$l推出",
	"force"  : 520,
	"attack" : 160,
	"dodge"  : 40,
	"parry"  : 150,
	"damage" : 90,
	"skill_name" : HIR"突如其来"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N大吼一声，双掌使出「"+YEL+"震惊百里"+NOR+"」，不顾一切般击向$n",
	"force"  : 690,
	"attack" : 220,
	"dodge"  : -10,
	"parry"  : 75,
	"damage" : 120,
	"skill_name" : YEL"震惊百里"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+MAG+"或跃在渊"+NOR+"」，向$n的$l连拍数掌",
	"force"  : 530,
	"attack" : 150,
	"dodge"  : 30,
	"parry"  : 140,
	"damage" : 140,
	"skill_name" : MAG"或跃在渊"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N身形滑动，双掌使一招「"+GRN+"双龙取水"+NOR+"」一前一后按向$n的$l",
	"force"  : 560,
	"attack" : 170,
	"dodge"  : 50,
	"parry"  : 115,
	"damage" : 100,
	"skill_name" : GRN"双龙取水"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+HIB+"鱼跃于渊"+NOR+"」，身形飞起，双掌并在一起向$n的$l劈下",     
	"force"  : 550,
	"attack" : 185,
	"dodge"  : 30,
	"parry"  : 100,
	"damage" : 110,
	"skill_name" : HIB"鱼跃于渊"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N双掌立起，使出「"+HIG+"时乘六龙"+NOR+"」向$n连砍六下",
	"force"  : 570,
	"attack" : 180,
	"dodge"  : 50,
	"parry"  : 110,
	"damage" : 110,
	"skill_name" : HIG"时乘六龙"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+HIC+"密云不雨"+NOR+"」，左掌封住$n的退路，右掌斜斜地劈向$l",     
	"force"  : 560,
	"attack" : 170,
	"dodge"  : 15,
	"parry"  : 120,
	"damage" : 100,
	"skill_name" : HIC"密云不雨"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+WHT+"损则有孚"+NOR+"」，双掌软绵绵地拍向$n的$l",
	"force"  : 590,
	"attack" : 175,
	"dodge"  : 15,
	"parry"  : 100,
	"damage" : 80,
	"skill_name" : WHT"损则有孚"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N脚下一转，突然欺到$n身前，一招「"+HIR+"龙战于野"+NOR+"」拍向$n的$l",     
	"force"  : 580,
	"attack" : 180,
	"dodge"  : 10,
	"parry"  : 95,
	"damage" : 110,
	"skill_name" : HIR"龙战于野"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N门户大开，一招「"+HIM+"履霜冰至"+NOR+"」向$n的$l劈去",
	"force"  : 660,
	"attack" : 200,
	"dodge"  : -20,
	"parry"  : 90,
	"damage" : 100,
	"skill_name" : HIM"履霜冰至"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N使出「"+GRN+"羝羊触蕃"+NOR+"」，双掌由下往上击向$n的$l",
	"force"  : 520,
	"attack" : 160,
	"dodge"  : 40,
	"parry"  : 130,
	"damage" : 110,
	"skill_name" : GRN"羝羊触蕃"NOR,
	"damage_type": "震伤"
]),
([      "action" : "$N左掌护胸，右掌使一招「"+HIR+"神龙摆尾"+NOR+"」上下晃动着击向$n的$l",     
	"force"  : 520,
	"attack" : 150,
	"dodge"  : 60,
	"parry"  : 120,
	"damage" : 80,
	"skill_name" : HIR"神龙摆尾"NOR,
	"damage_type": "震伤"
]),
});

string main_skill() { return "dragon-strike"; }

mapping sub_skills = ([
	"kanglong-youhui"  : 80,	// 1
	"feilong-zaitian"  : 80,	// 2
	"jianlong-zaitian" : 80,	// 3
	"hongjian-yulu"    : 80,	// 4
	"qianlong-wuyong"  : 80,	// 5
	"lishe-dachuan"    : 80,	// 6
	"turu-qilai"       : 80,	// 7
	"zhenjing-baili"   : 80,	// 8
	"huoyue-zaiyuan"   : 80,	// 9
	"shuanglong-qushui": 80,	// 10
	"yuyue-yuyuan"     : 80,	// 11
	"shicheng-liulong" : 80,	// 12
	"miyun-buyu"       : 80,	// 13
	"sunze-youfu"      : 80,	// 14
	"longzhan-yuye"    : 80,	// 15
	"lvshuang-bingzhi" : 80,	// 16
	"diyang-chufan"    : 80,	// 17
	"shenlong-baiwei"  : 80,	// 18
]);

int get_ready(object me)
{
	return 1;
}

int get_finish(object me)
{
	if (me->query("str") < 30 || me->query_str() < 45)
	{
		tell_object(me, "你演练完毕，手臂又酸又软，几乎抬不起来。\n");
		return 0;
	}

	if (me->query("con") < 22 || me->query_con() < 37)
	{
		tell_object(me, "你演练完毕，就觉得眼前金星乱冒，太阳穴突突的跳。\n");
		return 0;
	}

	if ((int)me->query_skill("force") < 150)
	{
		tell_object(me, "你演练完毕，几乎虚脱，自己的内功水平看来还有待提高。\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 1500)
	{
		tell_object(me, "你演练完毕，丹田提不起半点力来，看来应该继续锻炼内力。\n");
		return 0;
	}

	if (random(10) < 5)
	{
		tell_object(me, "你对十八掌的奥妙颇有领悟，或许再演练一次就能够融会贯通。\n");
		return 0;
	}

	tell_object(me, HIY "你一气呵成，将十八掌从头到尾演练了一变，心中顿悟，通\n"
			    "晓了降龙十八掌的奥妙精髓，融会贯通了掌法的精微之处，\n"
			    "再也非拆开使用那么那么简单。"NOR"\n");
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
	if ((int)me->query("str") < 31)
		return notify_fail("就你这身子骨还练降龙十八掌？小心弄折了胳膊。\n");

	if ((int)me->query("con") < 24)
		return notify_fail("算了吧，你先天根骨不好，别强学了。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法学习降龙十八掌。\n");

	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力这么差，怎能融会贯通降龙十八掌？\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("你的基本掌法火候不够，无法学习降龙十八掌。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dragon-strike", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int cost;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练降龙十八掌必须空手。\n");

	if ((int)me->query("qi") < 150)
		return notify_fail("你的体力太低了。\n");

	cost = me->query_skill("dragon-strike", 1) / 3 + 50;
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练降龙十八掌。\n");

	me->receive_damage("qi", 120);
	me->add("neili", -cost);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{


    if(!me->query("dragon-strike_zj")){	
	if (random(10) >= 5)
	{
		victim->receive_wound("qi", damage_bonus / 4);
		return HIR "你听到「喀啦」数声轻响，竟似骨骼碎裂的声音！"NOR"\n";
	}
	}else
	{
	
		if (random(2))
	{
		victim->receive_wound("qi", damage_bonus / 4);
		return HIR "你听到「喀啦」数声轻响，竟似骨骼碎裂的声音！"NOR"\n";
	}
	
	}
}

string perform_action_file(string action)
{
	return __DIR__"dragon-strike/" + action;
}

void skill_improved(object me)
{
	int i;
	string *sub_skillnames;

	sub_skillnames = keys(sub_skills);
	for (i = 0; i < sizeof(sub_skillnames); i++)
		me->delete_skill(sub_skillnames[i]);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
