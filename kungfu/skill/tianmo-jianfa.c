//天魔剑法
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N剑走偏锋，身行如鬼魅般闪开，一招「魅影请命」刺向$n！",
    "apply_factor": 2,
    "name" : "魅影请命",
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N身行突然变了数个变化，纵身越起，一招「天魔飞舞」刺向$n的$l！",
    "apply_factor": 3,
    "name" : "天魔飞舞",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N抽身后退，画了一个圆弧，正是一招「鬼影圆舞」以守带功刺向$n的致命之处！",
    "apply_factor": 4,
    "name" : "鬼影圆舞",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身行忽坐忽右，令人琢磨不定，一招「天魔魅影」功向$n！",
    "apply_factor": 5,
    "name" : "天魔魅影",
    "damage_type":"刺伤",
  ])});   


string *parry_weapon=({

"$N抽身后退，画了一个圆弧，手中$w和$n的$v碰在一起，发出兵的一声！\n",
"$N身形快速地晃了几晃，手中$w从异想不到的角度划了过去，正好架住$n的$v！\n",
"$N一横手中的$w，拼力架住了$n的$v，只听兵的一声，火花四溅！\n",
"$N刷地一声躲闪开来，手中$w轻轻划过$v，几个起落，落在远处！\n"

});

string *parry_hand=({

"$N脸上诡异的笑容一闪而过，手中$w似是要攻击$n的$l，$n的攻势不由得停住了。\n",
"$N退后几步，手中$w遥指$n的$l，封住了$n的进攻之势。\n",
"$N手中$w一挥，随后闪开，寻找着进攻的机会。\n",
"$N手中$w一横，虽是简单的招式，却封住了$n的全部进攻之力！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 
}
mapping *query_all_action(object me)
{
return action;	
}


string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
	
		
	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")       
        return notify_fail("手中无剑，如何学习天魔剑法？\n");
	
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
int skill_damage(object me,object victim)
{
  
  return 20;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
