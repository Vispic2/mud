// taisu-dodge.c
// by jeeny
 
#include <ansi.h> 
  
inherit SKILL; 
	
string *dodge_msg = ({ 
	"可是$n奔行极速，$N这一招差了尺许。\n", 
	"却见$n身形微晃，已在数尺之外。\n", 
	"$n足尖轻点，堪堪避开了$N这一招。\n", 
	"$n高高拔起，在空中连转数圈，落在了数丈开外。\n", 
	"$n蜷身急转，扬起劲风，逼得$N无法近身。\n", 
	"$N这一招眼看就要击中，可是$n略一侧身，避过$N的劲力，实属匪夷所思。\n", 
	"$n不退反进，从$N肋下钻过，恰恰避开这一招。\n", 
}); 
       
int valid_enable(string usage)  
{  
	return usage == "dodge"; 
} 
       
int valid_learn(object me) 
{ 
	





int lvl; 
       
	lvl = me->query_skill("taisu-dodge", 1); 
	if (lvl > 300) lvl = 300; 
       
	if (me->query("max_neili") < 1000 + lvl * 10) 
		return notify_fail("你的内力修为还欠火候。\n");
 

	if (me->query("dex") < 25)
		return notify_fail("你身法不佳,学不会如"
				   "此高深的轻功。\n"); 
if (me->query("family/family_name") != "古墓派" &&
	    me->query("family/family_name") != "古墓派")
return notify_fail("古月太素只有古墓弟子方可修习\n");

                if (me->query("gender") != "女性")return notify_fail("古月太素只有女性方可修习。\n");

	return 1; 
} 
       
string query_dodge_msg(string limb) 
{ 
	return dodge_msg[random(sizeof(dodge_msg))]; 
} 
       
mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp; 
       
	if ((int)me->query_skill("taisu-dodge", 1) < 100 || 
	    ! living(me)) 
		return; 
	
	ap = ob->query_skill("dodge") * 1; 
	dp = me->query_skill("dodge", 1) / 2 + 
	     me->query_skill("taisu-dodge", 1); 
       
	if (ap / 1 + random(ap) < dp) 
	{ 
		result = ([ "damage": -damage ]); 
       
		switch (random(4)) 
		{ 
		case 0: 
			result += (["msg" : HIW "但见$n" HIW "面露微笑，身体一颤，$N" 
					    HIW "只觉眼前一花，似乎出现了千百个如浮云飘在半空中的" 
					    HIW "幻影。"NOR"\n"]); 
			break; 
		case 1: 
			result += (["msg" : HIW "$N" HIW "只觉眼前一道青影，一闪一晃，"
					    HIW "$n在平地上闪掠横移，如行云流水，如鬼魅无常，瞬间失去身形。"NOR"\n"]); 
			break; 
		case 2: 
			result += (["msg" : HIW "$N" HIW "这一招迅疾无比，然而$n" 
					    HIW "没有多作犹豫，身体往前一飘，身轻如燕般便将" 
					    HIW "$N这一招躲了开去。"NOR"\n"]); 
			break; 
		default: 
			result += (["msg" : HIW "但见$n" HIW "身子一仰，向后倒飞出去，$N" 
					    HIW "见机猛攻，却又见$n" HIW "极速掠动的身影飘在" 
					    "$N身后，当真令人匪夷所思。"NOR"\n"]); 
			break; 
		} 
		return result; 
	}
 
} 
      
int query_effect_dodge(object attacker, object me) 
{ 
	int lvl; 
      
	lvl = me->query_skill("taisu-dodge", 1); 
	if (lvl < 50)  return 0; 
	if (lvl < 100) return 70; 
	if (lvl < 150) return 90; 
	if (lvl < 200) return 110; 
	if (lvl < 250) return 130; 
	if (lvl < 300) return 150; 
	if (lvl < 350) return 170; 
	return 200; 
} 
      
int practice_skill(object me) 
{ 
	int cost;

	cost = 60 + (int) me->query_skill("taisu-dodge", 1) / 3;
	if ((int)me->query("qi") < 70) 
		return notify_fail("你的体力太差了，难以练习太素玲珑步。\n"); 
     
	if ((int)me->query("neili") < cost) 
		return notify_fail("你的内力不够了，无法练习太素玲珑步。\n"); 
      
	me->receive_damage("qi", 50); 
	me->add("neili", -cost); 
	return 1; 
} 
      
string perform_action_file(string action) 
{ 
	return __DIR__"taisu-dodge/" + action; 
} 

void skill_improved(object me)
{
	int lvl;
	lvl = me->query_skill("taisu-dodge", 1);

	if (lvl < 270)
	{
		me->apply_condition("taisu-except", lvl / 2 +
				    (int)me->query_condition("taisu-except"));
	}
}	     
