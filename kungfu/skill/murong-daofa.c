// murong-daofa.c 慕容刀法

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N大喝一声「看招」，一招「劈天盖地满壮志」，刀锋自上而下向$n的$l挥去",
        "force" : 160,
        "dodge" : 10,
        "damage": 230,
        "lvl" : 0,
        "skill_name" : "劈天盖地满壮志",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「弯刀逆转倒乾坤」，手中$w在空中急速转动数圈，划向$n的$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 260,
        "lvl" : 30,
        "skill_name" : "弯刀逆转倒乾坤",
        "damage_type" : "割伤"
]),
([      "action" : "$N猛一挫身，一招「遥看万疆千里雪」,$w直向$n的颈中斩去",
        "force" : 260,
        "dodge" : 5,
        "damage": 290,
        "lvl" : 70,
        "skill_name" : "遥看万疆千里雪",
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「壮志豪气满江湖」，无数刀尖化作点点繁星，向$n的$l挑去",
        "force" : 300,
        "dodge" : 5,
        "damage": 220,
        "lvl" : 100,
        "skill_name" : "壮志豪气满江湖",
        "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 10)
                return notify_fail("你的神元功火候太浅。\n");
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
        level   = (int) me->query_skill("murong-daofa",1);
        
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                if(random(level) >= 145){
return ([
                "action":GRN+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":level+random(250),
                "damage_type": "割伤",
                "dodge": level/3+random(50),
                "force": level+300+random(100),
                ]);
        } else {
                        return action[NewRandom(i, 20, level/5)];
}
}
}
}
/*
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("murong-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 40)
                return notify_fail("你的体力不够练慕容刀法。\n");
		if ((int)me->query("neili") < 15)
                return notify_fail("你的内力不够练慕容刀法。\n");
        me->receive_damage("jing", 25);
		me->add("neili",-8);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-daofa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");
	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 ) 
{
        victim->receive_wound("qi", damage_bonus/2 );
        return HIR "只听一声惨嚎，一股鲜血从$n被砍中的伤口喷出！\n" NOR;	
}
   if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
      && me->query_skill_prepared("finger") == "canhe-zhi"
      && me->query_skill_mapped("finger") == "canhe-zhi"
      && objectp(weapon)) {
        me->set_temp("lianhuan_hit", 1);
        weapon->unequip();
        if (random(2)==0) victim->start_busy(2);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
        weapon->wield();
        me->add("neili", -30);
        me->delete_temp("lianhuan_hit");
        me->add_temp("lianhuan", -1);
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行！\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"使出星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
