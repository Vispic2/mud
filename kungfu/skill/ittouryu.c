 //mimicat@fy4
//ittouryu.c
//一刀流剑术
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
                "$n一招「切返」以守为攻，化解了$N的攻势。\n",
                "$n突然从怀中掏出一把短刀，「二刀」当”地一声挡住了$N的攻击。\n",
});
string *unarmed_parry_msg = ({
                "$n一招「切返」以守为攻，化解了$N的攻势。\n",
                "$n突然从怀中掏出一把短刀，「二刀」当”地一声挡住了$N的攻击。\n",
});
        mapping *action = ({
                ([      "action" : 
                "$N双手持刀，高举过顶，突然向$n攻出一招「南无三」，$w以破竹之势直奔$n的要害而去",
                        "dodge" : 10,
                        "parry" : 20,
                        "damage" : 320,
                        "damage_type" : "割伤",
                ]),
                ([      "action" : 
                "$N一招「地狱」猛地挥动$w向$n当头击下，$n退了一步，但$w的刀气不依不饶地袭向$n",
                        "dodge" : 17,
                        "parry" : 14,
                        "damage" : 320,
                        "damage_type" : "瘀伤",
                ]),
                ([      "action" : 
                "$N手中的$w刀光暴长，「岚」！不可一世地撞向$n",
                        "dodge" : 12,
                        "parry" : 11,
                   "damage" :310,
                        "damage_type" : "砍伤",
                ]),
                ([      "action" : 
                "$N挥动$w，一招「叶切合」如蛆附骨，点点不离$n",
                        "dodge" : 80,
                        "parry" : 80,
                        "damage" : 340,
                        "damage_type" : "刺伤",
                ]),
                ([      "action" : 
                "$N手中的$w在$n攻击的间隙中抢攻了进去，$N手中的$w有如梦一般罩了下去",
                        "dodge" : 70,
                        "parry" : 70,
                        "damage" : 390,
                        "damage_type" : "刺伤",
                ]),
                ([      "action" : 
                "$N低头躲过$n的一击，接着想也不想，反手一招「浮舟」$w带着三分惆怅，斩向$n的胸口",
                        "dodge" : 120,
                        "parry" : 120,
                        "damage" : 320,
                        "damage_type" : "割伤",
                ]),
        });


int valid_enable(string usage) { return usage == "blade" ||  usage == "parry" ; }



mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("ittouryu",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(2)==1 && random(level) > 180)
	{
		return ([
		"action": RED""+(order[random(13)])+"「  牙突一式! 」"NOR""+HIY"$N突然加速！刺出后水平横扫,追击躲闪的$n!"NOR,
		"force" : 650+random(200),
                "attack" : 50,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(2)==1 && random(level) > 190)
	{
		return ([
		"action": HIR""+(order[random(13)])+"「  牙突二式! 」"NOR""+HIY"$N突然加速！刀举头上,刺出后向$n运动劈下! "NOR,
		"force" : 650+random(200),
                "attack" : 50,
		"dodge" : 70,
		"damage": 650+random(200),
	        "skill_name" : "牙突二式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(2)==1 && random(level) > 200)
	{
		return ([
		"action": HIM""+(order[random(13)])+"「  牙突三式! 」"NOR""+HIY"$N突然加速！由下刺上,对跃起的$n使出牙突,这是是对空的招式！"NOR,
		"force" : 650+random(200),
                "attack" : 90,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(2)==1 && random(level) > 240)
	{
		return ([
		"action": HIW""+(order[random(13)])+"「  牙突零式! 」"NOR""+HIY"$N在离$n极近距离猛的将刀刺出,威力巨大,这乃是一招必杀技 ！"NOR,
		"force" : 650+random(200),
                "attack" : 120,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
 
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

string perform_action_file(string action)
{
        return __DIR__"ittouryu/" + action;
}
int valid_learn(object me)
{
    if ((int)me->query_skill("aikido", 1) < 100)
   return notify_fail("你的空手道火候不够，无法学。\n");

    if ((int)me->query_skill("xuanhualiu-quanfa", 1) < 100)
   return notify_fail("你的喧哗流拳法火候不够，无法学。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("你的杀意心法火候不够，无法学。\n");
    if ((int)me->query_skill("ninjitsu", 1) < 100)
   return notify_fail("你的忍术火候不够，无法学。\n");

    if ((int)me->query_skill("enmeiryu", 1) < 100)
   return notify_fail("你的陆奥圆明流拳术火候不够，无法学。\n");

    if ((int)me->query("max_neili") < 50)
   return notify_fail("你的内力太弱，无法练一刀流剑术。\n");
   
        return 1;
}  
 
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");

    if ((int)me->query("qi") < 70)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("你的内力不够练一刀流剑术。\n");
    me->receive_damage("qi", 60);
    me->add("neili", -60);
    return 1;

}   
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*2+150;
                  msg = HIR"「百鬼袭！！ 」"+HIM"$N御技如神，杀气冲天！\n"NOR;
if (random(5)==0) msg = HIC"「百鬼冲！！」"+HIY"$N御技如神，杀气冲天！。\n"NOR;
if (random(5)==1) msg = HIM"「百鬼碎！！」"+HIY"$N御技如神，杀气冲天！ \n"NOR;
if (random(5)==2) msg = HIC"「百鬼突！！」"+HIW"$N御技如神，杀气冲天！\n"NOR;
if (random(5)==3) msg = HIG"「百鬼坠！！」"+HIW"$N御技如神，杀气冲天！\n"NOR;
if (random(5)==4) msg = HIW"「百鬼斩！！」"+HIY"$N御技如神，杀气冲天！ \n"NOR;	
if (victim->query("qi") > flvl)
{
victim->start_busy(2);
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
