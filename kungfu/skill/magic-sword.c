//npc武功，不开放!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
   ([   "action":
"$N手中$w向$n的$l直劈过来。",
     "force":     600,
     "dodge":     100,
     "parry":                100,
     "damage":     600,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w向$n的$l斜劈过来。",
     "force":     600,
     "dodge":     100,
     "parry":                100,
     "damage":     600,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中的$w划了一个三角，向$n的$l刺了过去。",
     "force":     600,
     "dodge":     100,
     "parry":                100,
     "damage":     600,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w划了个大圆，向$n的$l刺了过去。",
     "force":     600,
     "dodge":     100,
     "parry":                100,
     "damage":     600,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w对着$n的$l旋了过去。",
     "force":     600,
     "dodge":     100,
     "parry":                100,
     "damage":     600,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
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
        level = (int)me->query_skill("magic-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
        {
   if( (int)me->query("qi") < 300
   ||   (int)me->query("neili") < 300 )
     return notify_fail("你的内力或气不够，没有办法练习西洋剑法。\n");
   me->receive_damage("qi", 300);
   me->add("neili", -300);
   //write("你按著所学练了一遍西洋剑法。\n");
   return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("magic-sword",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(2)==1 && random(level) > 150)
	{
        if (userp(victim))
        victim->start_busy(3+random(2));
else    victim->start_busy(2);
        return HIC "「冰晶术!!」！$N突然念咒,用了一个魔法，$n被冰冻住暂时不能动了!!\n" NOR;
	}
  	if( random(2)==1 && random(level) > 150 && victim->query("qi") > 50
  	&& victim->query("eff_qi") > 50)
	{
        if (userp(victim))
{
        if (victim->query("qi")/15 > 20)
        victim->add("qi",-victim->query("qi")/15);
        if (victim->query("eff_qi")/15 > 20)
        victim->add("eff_qi",-victim->query("eff_qi")/25);
}else 
{
        victim->add("qi",-1090);
        victim->add("eff_qi",-1090);
}
        return HIB "「暗黑核融术!!」！$N突然念咒,用了一个魔法，$n被炸得飞了起来!!\n" NOR;
	}
 	if( random(2)==1 && random(level) > 150 && victim->query("jing") > 50
 	&& victim->query("eff_jing") > 50)
	{
        if (userp(victim))
{
        if (victim->query("jing")/20 > 20)
        victim->add("jing",-victim->query("jing")/20);
         if (victim->query("eff_jing")/20 > 20)
        victim->add("eff_jing",-victim->query("eff_jing")/30);
}
else {
        victim->add("jing",-500);
        victim->add("eff_jing",-500);
}
        return HIW "「流星光矢!!」！$N突然念咒,用了一个魔法，$n被打中后觉得头痛无比!!\n" NOR;
	}
if (damage_bonus < 100) damage_bonus=100;
	if( damage_bonus > 200 ) 
{
        victim->receive_wound("qi", damage_bonus );
        return HIR "突!!一阵剑影！！！一股鲜血从$n的身子喷出\n" NOR;	
}
        if( damage_bonus < 120 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        return YEL "刺!!一阵剑影！！！$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        return HIM "劈!!一阵剑影！！！你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}


}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("magic-sword", 1);

//        if( me->is_busy()) return 1;
        if( damage < 10 ) return 1;
        if (  random(level) > 50          ){
         msg = RED"$N面对$n的攻势。身形一闪，突然施放魔法!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(2) == 0 && random(level) > 160){
         msg = YEL"「 地精附身! 」。$N突然念咒,用了一个魔法，$n感觉被大地吸住不能动了!!。\n"NOR;
//             if (!ob->is_busy())
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
             ob->start_busy(3+random(2));
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("eff_qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/25);
}
else
{
             ob->start_busy(3);
             ob->add("qi",-100);
             ob->add("eff_qi",-100);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(2)==1&& random(level) > 160){
         msg = HIR"「火炎球!」。$N突然念咒,用了一个魔法，$n被一个火球打中了!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/25);
}
else {
             ob->add("qi",-200);
             ob->add("eff_qi",-200);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(2)==2&& random(level) > 150){
         msg = HIC"「霹雳闪电!」。$N突然念咒,用了一个魔法，$n被一个闪电打中了!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50 
        && ob->query("jing") > 50 && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
if (ob->query("jing")/30 > 20)
             ob->add("jing",-ob->query("jing")/30);
if (ob->query("eff_jing")/30 > 20)
             ob->add("eff_jing",-ob->query("eff_jing")/30);
}
else
{
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
             ob->add("jing",-1000);
             ob->add("eff_jing",-1000);
}
msg += damage_msg(damage, "瘀伤");
            }
else
           msg = HIG"$n抢先出招，使$N的念咒失败了!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
