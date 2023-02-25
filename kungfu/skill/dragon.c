// dragon.c 龙之力量
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string *dodge_msg = ({
        "可是$n一声狂吼，$N竟愣住了，不敢放手进攻。\n",
        "但是$n身子一闪，$N这一招扑了个空。\n",
        "$n腾空跃起，躲开了$N的这一招。\n",
        "$n也不躲闪，直冲$N而去，$N一看不妙只得收招退开。\n",
});

mapping *action = ({
([  "action":"$N身子一侧，尾巴忽然从身后甩出，扫向$n",
    "dodge" : 40,
    "damage": 600,
    "damage_type":  "瘀伤"
]),
([  "action":"$N猛然接近，张嘴就咬$n",
    "dodge" : 60,
    "damage": 300,
    "damage_type":  "瘀伤"
]),
([  "action":"$N右抓撑地，左抓直击$n面部",
    "dodge" : 50,
    "damage": 400,
    "damage_type":  "瘀伤"
]),
([  "action":"$N突然一跃，从空中直扑$n",
    "dodge" : 100,
    "damage": 600,
    "damage_type":  "瘀伤"
]),
([  "action":"$N身子前倾，以全身之力撞向$n",
    "dodge" : 40,
    "damage": 1000,
    "damage_type":  "瘀伤"
]),
([  "action" : 		"$N用"+HIM+"后腿"+NOR+"往$n的$l用力一蹬",
    "damage": 500,
	"dodge":		10,
        "force":		200,
    "lvl" : 0,
    "skill_name" : "蛙鸣三起",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N反转身用"+HIG+"尾巴尖"+NOR+"对准$n的$l一刺",
    "dodge" : 10,
    "damage": 500,
	"dodge":		10,
        "force":		200,
    "lvl" : 0,
    "skill_name" : "反手点穴",
    "damage_type":	"咬伤",
]),
([  "action" : "$N扑上来"+HIC+"张嘴"+NOR+"往$n的$l狠狠地一咬",
	"dodge":		10,
        "force":		200,
    "dodge" : 15,
    "damage": 520,
    "lvl" : 0,
    "skill_name" : "前瞻后跳",
		"damage_type":	"咬伤",
]),
([  "action" : "$N用"+HIW+"爪子"+NOR+"往$n的$l一抓",
	"dodge":		10,
        "force":		200,
    "dodge" : 25,
    "damage": 580,
    "lvl" : 0,
    "skill_name" : "分身无影",
    "damage_type":	"抓伤",
]),
([  "action" : "$N抬起"+HIR+"爪子"+NOR+"往$n的$l一踹",
	"dodge":		10,
        "force":		200,
    "dodge" : 30,
    "damage": 500,
    "lvl" : 0,
    "skill_name" : "无敌蛤蟆",
    "damage_type":	"瘀伤",
])
});

int valid_enable(string usage) 
{ 
	return usage == "unarmed" ||  usage == "dodge" ||usage == "parry" ; 
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	return notify_fail("龙之力量无法通过练习来成长。\n");
}
int valid_learn(object me)
{
	 return 1; 
 }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"dragon/" + action;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("dragon",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(5)==1 && random(level) > 160)
	{
        if (userp(victim))
        victim->start_busy(2);
else    victim->start_busy(2);
        return HIC "「吐息!!」！$N突然吐息，$n被迷住暂时不能动了!!\n" NOR;
	}
  	if( random(5)==1 && random(level) > 160)
	{
        if (userp(victim) && victim->query("eff_qi") > 50
        && victim->query("qi") > 50)
{
if (victim->query("qi")/15 > 20)
        victim->add("qi",-victim->query("qi")/35);
if (victim->query("eff_qi")/15 > 20)
        victim->add("eff_qi",-victim->query("eff_qi")/35);
}else 
{
        victim->add("qi",-100);
        victim->add("eff_qi",-100);
}
        return HIR "「吐炎!!」！$N突然吐炎，$n被烧得飞了起来!!\n" NOR;
	}
 	if( random(5)==1 && random(level) > 150)
	{
        if (userp(victim) && victim->query("jing") > 50
        && victim->query("eff_jing") > 50)
{
if (victim->query("jing")/20 > 20)
        victim->add("jing",-victim->query("jing")/40);
if (victim->query("eff_jing")/20 > 20)
        victim->add("eff_jing",-victim->query("eff_jing")/40);
}
else {
        victim->add("jing",-400);
        victim->add("eff_jing",-400);
}
        return HIY "「龙吼!!」！$N突然龙吼，$n被龙吼中后觉得头痛无比!!\n" NOR;
	}
if (damage_bonus < 100) damage_bonus=100;
        if( damage_bonus > 200 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "龙爪!!一股鲜血从$n的身子喷出\n" NOR;	
}
        if( damage_bonus < 120 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "龙爪!!！！$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "龙爪!!！你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}

}
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("dragon", 1);

//        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 150  && random(3) ==1   ){
         msg = RED"$N面对$n的攻势。身形一闪，反扑上去!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(5) == 0 && random(level) > 150){
         msg = YEL"「吐息!!」！$N突然吐息，$n被迷住暂时不能动了!!\n"NOR;
//             if (!ob->is_busy())
        if (userp(ob) && ob->query("qi") > 50 && ob->query("jing") > 50
        && ob->query("eff_qi") > 50 && ob->query("eff_jing") > 50){
             ob->start_busy(2);
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/50);
}
else
{
             ob->start_busy(3);
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(5)==1&& random(level) > 150){
         msg = HIR"「吐炎!!」！$N突然吐炎，$n被烧得飞了起来!!!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50 
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/45);
}
else {
             ob->add("qi",-2000);
             ob->add("eff_qi",-2000);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(5)==2&& random(level) > 150){
         msg = HIC"「龙吼!!」！$N突然龙吼，$n被龙吼中后觉得头痛无比!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/45);
if (ob->query("jing")/30 > 20)
             ob->add("jing",-ob->query("jing")/45);
if (ob->query("eff_jing")/30 > 20)
             ob->add("eff_jing",-ob->query("eff_jing")/45);
}
else
{
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);

}
msg += damage_msg(damage, "瘀伤");
            }
else
           msg = HIG"$n抢先出招，使$N的反扑失败了!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
