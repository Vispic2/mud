//Cracked by Kafei
// luoyan-jian.c 衡山派剑法“回风落雁剑”
// maco 1999.1.13

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int yunwu(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$N手上$w慢慢点出，突然间在空中一颤，一招「泉鸣芙蓉」，剑刃暗发嗡嗡之声，$w来路如鬼如魅，顷刻间竟然已绕到了$n背后",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 115,
        "lvl" : 0,
        "skill_name" : "泉鸣芙蓉",
        "damage_type":  "刺伤"
]),
([      "action":"$N全不理会对方攻势来路，使出一招「鹤翔紫盖」，变化莫测地攻向$n，剑势竟无丝毫迹象可寻",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage": 215,
        "lvl" : 10,
        "skill_name" : "鹤翔紫盖",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w晃动，「石廪书声」使将出来，剑招奇变横生，$n瞧得心惊神眩，不知$N究竟出了多少招",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 130,
        "lvl" : 20,
        "skill_name" : "石廪书声",
        "damage_type":  "割伤"
]),
([      "action":"$N$w如云雾变化，正是一招「天柱云气」，极尽诡奇之能事，动向无定，不可捉摸，$n觉一阵眼花缭乱，顿感穷於应付",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "damage": 140,
        "lvl" : 30,
        "skill_name" : "天柱云气",
        "damage_type":  "割伤"
]),
([      "action":"$N突然间身子往斜里窜出，使出「雁回祝融」，听$w陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中",
        "force" : 410,
        "dodge" : 10,
        "parry" : 10,
        "damage": 250,
        "lvl" : 50,
        "skill_name" : "雁回祝融",
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
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
        string *msg1,*msg2;
        msg1 = ({
		HIW"$N手中$w"+HIW"连连挥舞，声东击西，虚虚实实，幻人耳目，变化古怪之极，$n不禁心下骇然！"NOR,
		HIW"$N手中$w"+HIW"越使越快，一套「百变千幻衡山云雾十三式」有如云卷雾涌，$n不由得目为之眩！"NOR,
		HIW"见$N手上$w"+HIW"剑招变幻，犹如鬼魅，五花八门，层出不穷，$n觉眼前尽是一片剑光飞舞来去！"NOR,
        });
        msg2 = ({
		HIR"但见一点点鲜血从$w"+HIR"下溅了出来，$n腾挪闪跃，竭力招架，始终脱不出$N的剑光笼罩，鲜血渐渐在身周溅成了一个红圈，$N又已刺出一剑！"NOR,
		HIY"$N一剑既占先机，後着绵绵而至，一柄$w"+HIY"犹如灵蛇，颤动不绝，在$n的攻势中穿来插去，只逼得$n连连倒退！"NOR,
		HIY"$n中了一剑，大骇之下，急向後退，$N手中$w"+HIY"已如狂风骤雨般连攻，当真是兔起鹘落，变化快极！"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"刺伤"]);
        }


        level   = (int) me->query_skill("luoyan-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("luoyan-jian",1) < 199)
           return notify_fail("此项技能只能大于二百级时能学习。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}


int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n见$n伤口中一道血箭如涌泉般向上喷出，原来$p中剑后内力未消，将鲜血逼得从伤口中急喷而出，既诡异，又可怖。\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+20);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}


string perform_action_file(string action)
{
        return __DIR__"luoyan-jian/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
