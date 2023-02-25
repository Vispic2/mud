#include <ansi.h>
//mantian-huayu.c漫天花雨
// 19981010
inherit SKILL;

string	*msg = ({
"$N身子左侧，一式「月下踏径」，右手$w从身体下方突然甩出，直射向$n的$l",
"$w破空飞出，一式「长虹经天」，缓缓一个弧线，由左自右，绕向$n的$l，",
"$N双手连扬，一式「破云见日」，两把$w向$n撒出，笼罩$n的全身上下",
"$N向空中一撒，却是$n一招「秋日落叶」，十多枚$w由空中缓缓落下",
"$N身形急速向前滑动，一式「雪地追踪」，三枚$w向$n的胁下射去",
"$N一式「回首沧桑」，身体一转，反手掷出数枚$w，飞向$n的背部",
"$N凌空一纵，一招「雨打浮萍」，居高临下，手中$w疾射，直向$n的$l",
"$N一招「流星电闪」，手指弹出五枚$w，一点黑光射向$n的头部",
});

int valid_enable(string usage)
{
	return usage == "throwing" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("mantian-huayu",1)),
		"damage_type":"刺伤",
		"dodge":random(20)+20,
          "force":random(150)+me->query_skill("mantian-huayu",1),
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}
int practice_skill(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("jing") < 50)
               return notify_fail("你的体力不够练漫天花雨。\n");
       me->receive_damage("jing", 30);
       return 1;
}

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 100)
               return notify_fail("你的内力不够。\n");
       if ((int)me->query_skill("xuantian-wuji", 1) < 30)
               return notify_fail("你的玄天无极功火候太浅。\n");
               return 1;
}
string perform_action_file(string action)
{
       return __DIR__"mantian-huayu/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N脚踏八卦步,手捏太乙决,$N一声长啸，$n双眼一黑，吐出一口鲜血!\n"NOR;
}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
