// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string *action_msg = ({
        "$N轻抚手中的$w，突然间只见刀光一闪，"+(order[random(13)])+"「再闪，又一闪」"NOR"！三道刺骨的寒气已然袭上了$n的$l",
        "只见$N倒提$w，"+(order[random(13)])+"「身形急冲」"NOR"，就在与$n错身之际，突然反手一刀从$n后脑斜劈而下",
        "$N斜身飞起，带出一片匹练也似的"+(order[random(13)])+"「刀光」"NOR"卷向$n的$l",
        "$N突然一脚踢出，手中的$w划出一道"+(order[random(13)])+"「轻妙的圆弧」"NOR"，淡淡的刀光封住了$n的头脸，切断了$n的呼吸",
        "只见$N脸色一寒，一招"+(order[random(13)])+"「千里冰封」"NOR"使出，从眉捷到脚跟，\n$n周身的血液都似被这无尽的刀势冻住，而生命也仿佛要离体而去",
        "$N刀势渐慢，而$w上带出的寒气却越来越浓。就在这时，\n$n的心头一紧，"+(order[random(13)])+"「一道比针尖还要锐利的寒气」"NOR"已刺上了$n$l",
        "$N也不管三七二十一，高举$w呼！地就是一刀向$n"+(order[random(13)])+"「迎面斩下！」"NOR"\n虽然只有一刀，可怕的刀势却似万古不化的寒冰封死了$n的一切退路",
});


int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够，没有办法练冰魄寒刀，多练些内力再来吧。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("你的化功大法火候不够.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("你的抽髓掌火候不够.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("你的天山杖法火候不够.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("你的摘星功火候不够.\n");
		
	if ((int)me->query_skill("chanhun-suo", 1) < 120)
		return notify_fail("你的缠魂索火候不够.\n");


	if ((int)me->query_skill("xuantian-strike", 1) < 180)
		return notify_fail("你的玄天冰蚕掌火候不够.\n");

		
        if (! (ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        )
                return notify_fail("你必须先找一把冰做的刀才能练冰魄寒刀。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "blade" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 180 + random(230), 
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2) ? "挫伤" : "割伤", 
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 110
            ||  (int)me->query("neili") < 110)
                return notify_fail("你的内力或气不够，没有办法练习冰魄寒刀。\n");
                
        me->receive_damage("qi", 100);
        me->add("neili", -100);
        write("你按着所学练了一遍冰魄寒刀。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon = me->query_temp("weapon");     
        string msg;
        int lvl;
        int flvl;

        lvl  = me->query_skill("bingpo-blade", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "感到内力如雪花融化一样，消失了。。\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "感到肌肤便似腐烂一般，散发出一股极难"
               "闻的恶臭。。\n" NOR;
        }       


        if (((int)me->query_skill("blade", 1)/2) > random((int)victim->query_skill("force", 1)))
        {
                victim->receive_wound("qi", (300-damage_bonus)+60);
                msg = HIW "$N默运真气，将冰魄寒刀中寒气逼出，$n一个不察，已被冻伤！\n\n"NOR;
                message_combatd(msg, me, victim);
             
        }
        //if (random(2)==0) return;
        
        switch(random(3)) {
        case 0:
                victim->receive_damage("qi",damage_bonus/3*2+50);
                msg = HIW"只见一丝寒气无声无息地钻到$n体内！\n"NOR;
                break;
                                
        case 1:  
                victim->receive_damage("qi",damage_bonus/2+30);
                msg = HIW"$N暗使巧力，在$n的伤口上留下一道浅浅的白印！\n"NOR;
                break;
                                
        case 2:
                victim->receive_damage("qi",damage_bonus+20);
                msg = HIW"$n突然觉得体内奇寒难忍...\n"NOR;
                break;      
        }
               
        return msg;                    
}
string perform_action_file(string action)
{
        return __DIR__"bingpo-blade/" + action;

}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("bingpo-blade",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$N使出化功大法,$n到内力如雪花融化一样，消失了。。\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       

weapon = me->query_temp("weapon");
if (weapon)
{
        if (  level2 > 150
        && random(5)==1
        && (string)weapon->query("skill_type") == "blade"){
 
            msg = HIC"$n出招时，$N身形一闪 八方藏刀式，$n无法近身，也无法进攻!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }


}



}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
