//anye-guimeidian.c 	暗夜鬼魅典
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//inherit FORCE;	//暗夜鬼魅典取消内功功能
inherit SKILL;

mapping *action = ({
([  "action" :HBYEL"$N身形一变，如闪电般欺到$n身前，相距不过一尺，手中$w已经刺到$n的$l",
	"attack":	400,
	"parry":	400,
	"dodge":	400,
	"damage":	400,
	"force":	400,
	"damage_type" : "割伤",
]),
([	"action" : HBBLU"但见红影闪处，$N手中的$w向$n的$l直戳而来，势如奔雷，避不可避",
	"attack":	500,
	"parry":	500,
	"dodge":	500,
	"damage":	500,
	"force":	500,
	"damage_type" : "刺伤",
]),
([	"action" : HBGRN"$N欺身而上，左手在$n的肩上一拍再横飞出去，而手中的$w却指向$n的$l",
	"attack":	600,
	"parry":	600,
	"dodge":	600,
	"damage":	600,
	"force":	600,
	"damage_type" : "割伤",
]),
([	"action" : HBGRN"$N突然跃起丈余，$n一抬头，发现空中并无$N的身影，而一股寒气却从后袭来",
	"attack":	700,
	"parry":	700,
	"dodge":	700,
	"damage":	700,
	"force":	700,
	"damage_type" : "割伤",
]),
([	"action" : HBRED"$N左一拨，右一拨，上一拨，下一拨，将$n的招数尽数拨开，右手一转，刺向$n",
	"attack":	800,
	"parry":	800,
	"dodge":	800,
	"damage":	800,
	"force":	800,
	"damage_type" : "刺伤",
]),
([	"action" : HBBLU"$N左手一圈，倒转$w，蓦地刺出，刷刷刷急攻三式，招招尽是指向$n的要害",
	"attack":	800,
	"parry":	800,
	"dodge":	800,
	"damage":	800,
	"force":	800,
	"damage_type" : "刺伤",
]),
([	"action" : HBGRN"蓦地里$N空手猱身而上，双手擒拿点拍，攻势凌厉之极，乘$n惊骇之际弹出$w刺向$n",
	"attack":	800,
	"parry":	800,
	"dodge":	800,
	"damage":	800,
	"force":	800,
	"damage_type" : "刺伤",
]),
([	"action" : HBCYN"$N身形飘忽，有如鬼魅，转了几转，移步向西，一剑刺向$n。出手之奇之快，直是匪夷所思",
	"attack":	900,
	"parry":	900,
	"dodge":	900,
	"damage":	900,
	"force":	900,
	"damage_type" : "割伤",
]),
([	"action" : HBMAG"$N一剑挺刺，极尽都雅，神态之中，竟大有华山派女弟子所学‘玉女剑十九式’的风姿，只是带着三分阴森森的邪气",
	"attack":	1000,
	"parry":	1000,
	"dodge":	1000,
	"damage":	1000,
	"force":	1000,
	"damage_type" : "割伤",
]),
});


string main_skill() { return "anye-guimeidian"; }

mapping sub_skills = ([
		"kuihua-mogong" : 500,
		"kuihua-shengong" : 500,
]);

int get_ready(object me)
{
	return 1;
}


int get_finish(object me)
{
	object ob;

	if( ! (ob = me->query_temp("weapon"))
	        || (string)ob->query("skill_type") != "sword" )
	{
		tell_object(me, "你空手舞了半天，发现不拿把剑实在难以演练。\n");
		return 0;
	}
	if (me->query("family/family_name")!="日月神教" )
	{
		tell_object(me,"你不是日月神教弟子，怎么能演练暗夜鬼魅典呢。\n");
		return 0;
	}	
	if (me->query_skill_mapped("force")!= "kuihua-shengong")
	{
		tell_object(me, "你演练完毕，只感葵花魔功和葵花神功毫无牵连，看来必须要激发葵花神功，否则无法将其合一。\n");
		return 0;
	}/*
	if ( (string)me->query("gender")=="女性" )
	{
		tell_object(me, "你舞了半天，发现阴性体质实在难以演练。\n");
		return 0;
	}

	if ( (string)me->query("gender")=="男性" )
	{
		tell_object(me, "你不把那玩意割了，恐怕会遭受真气反噬。\n");
		return 0;
	}
	if ( (string)me->query("genderbak")=="男性" )
	{
		tell_object(me, "你是个假太监，不把那玩意割了，恐怕会遭受真气反噬。\n");
		return 0;
	}*/
	if (me->query("int",1) < 29)
	{
		tell_object(me, "你演练完毕，只感葵花神功和葵花魔功毫无牵连，看"
		            "来依你的悟性，无法将其合一。\n");
	return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 350)
        {
                tell_object(me, "你演练完毕，发现自己的武学修养尚待提高"
                                "，暂且无法将二者合一。\n");
	return 0;
	}

	if (me->query("dex",1) < 32)
	{
		tell_object(me, "你演练完毕，只觉依自己的身法灵动性，根"
		            "本无法将二者合一。\n");
		return 0;
	}
	if (me->query_skill("anye-guimeidian", 1) > 100)
	{
		tell_object(me, "你已经领悟了暗夜鬼魅典，用不着再演练了。\n");
		return 0;
	}
	if ((int)me->query_skill("kuihua-mogong", 1) < 500)
		return notify_fail("你的「葵花魔功」火候太浅，没法演练高深的暗夜鬼魅典。\n");
	if ((int)me->query_skill("kuihua-shengong", 1) < 500)
		return notify_fail("你的葵花神功太低了，没法演练高深的暗夜鬼魅典。\n");
	if (me->query_skill("literate", 1) < 350)
	{
		tell_object(me, "你觉得暗夜鬼魅典极其深奥，看"
		            "来多研究一下学问可能更有帮助。\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 10000)
	{
		tell_object(me, "你觉得自己内力修为不继，无法将葵花魔功和葵花神功二者合一。\n");
		return 0;
	}

	if (random(10000) < 8000)
	{
		tell_object(me, "你觉得有所感悟，或许再演练一次就能融会贯通，将二者合一。\n");
		return 0;
	}

	tell_object(me, HIY "\n一阵凡尘往事涌上心头，你几欲放声长叹。霎"
	            "那间，葵花神功和葵花魔功交替着不断在\n你脑海里"
	            "闪现，终于融会贯通，合二为一。你终于通晓了暗夜鬼魅"
	            "典的诀窍。\n" NOR);
	message("channel:chat", HBYEL HIR"【天降奇才】"HBRED HIC + "听说"+me->query("name")+"天纵奇才，将葵花魔功与葵花神功合二为一，领悟了暗夜鬼魅典！\n"NOR,users() );
	me->set_skill("anye-guimeidian",181);
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

//取消内功功能，给予更多选择
int valid_enable(string usage)
{
	return usage == "sword" || usage =="force"|| usage =="parry"||usage == "unarmed";
}

//禁止练习
int practice_skill(object me)
{
    return notify_fail("暗夜鬼魅典只能学习研究。\n");
}




mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
	return __DIR__"anye-guimeidian/" + action;
}

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (! objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("anye-guimeidian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;
	string name;
	int ap, dp,damage2;

	weapon = me->query_temp("weapon");
	ap = (int)me->query("bodyreset",1);
	dp = (int)victim->query("bodyreset",1);
	damage2 = (int) me->query_skill("anye-guimeidian",1) + (int) me->query_skill("kuihua-shengong",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("kuihua-shengong",1) < 100 || me->query_skill("anye-guimeidian",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "kuihua-shengong") return 0;	
	if (damage2<10) damage2=10;		

	if (me->query_temp("weapon"))
		name = "手中" + weapon->name();
	else
		name = "双掌";

	// 避免在使用Pfm时讯息重复
	if ( random(ap) > dp/10 && random(6)==0 )
	{
		victim->receive_damage("qi", damage2*2+damage_bonus/2,me);
		victim->receive_wound("qi", damage2*2+damage_bonus/2,me);
		return HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
			               HIW "\n宛若流星般分从不同的方位同时刺向$n" HIW "！\n" NOR;
	}

	if( weapon && random(me->query_dex(1)) > victim->query_dex(1)/3 && random(6)==1 )
	{
		victim->receive_damage("jing", damage2*2+damage_bonus/2,me);
		victim->receive_wound("jing", damage2*2+damage_bonus/2,me);
		victim->add("neili",-damage2);
		return HIR "只听「嗤」一声，一缕血丝从"+victim->name()+"被刺的针孔处喷出！\n" NOR;
	}
}
int ob_hit(object ob, object me, int damage)
{
	object weapon;
	string msg;
	int j, level;
	string result;
	int ap, dp;
	int neili, neili1;
	int damage2;
	level = (int) me->query_skill("anye-guimeidian",1);
	weapon = me->query_temp("weapon");
	neili = me->query("neili");
	neili1 = ob->query("neili");
	damage2= (int) ob->query("neili",1)/500;
	if (damage <10)  damage=10;  
	if (damage2> 100000)	damage2=100000;
	if (damage2 < 100 ) damage2=100;
	
	if (random(8)==0 && level>=300 &&  me->query_skill_mapped("force") == "anye-guimeidian")
	{

		ob->add("neili",-damage2);
		me->add("neili",damage2);
		msg = HIC "$N" HIC "一声冷笑! 吸星大法!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;
		message_vision(msg, me, ob);
	}

	ap = (int)me->query("bodyreset");
	dp = (int)ob->query("bodyreset");

	if (random(ap) > dp/10 && me->query("neili") > 500 && random(5)==0 )
	{
		switch (random(4))
		{
		case 0:

			result = HIC "$N" HIC "眼睛一花，$n" HBBLU "已没了踪"
			         "影。突然$n" HBBLU "从身后拍了一下$N" HIC "的"
			         "头，轻轻跃开。\n" NOR;
			break;
		case 1:
			result = HIC "$N" HIC "眼前一花，似乎见到$n" HBBLU "身"
			         "形一晃，但随即又见$n" HBBLU "回到原地，却似"
			         "从未离开。\n" NOR;
			break;
		case 2:
			result =  HBBLU "$n" HBBLU "尖啸一声，忽然身子一转已不见了踪影，$N" HIC			          "只觉耳边风声不断，但随即又见$n" HBBLU "回到了原地。\n" NOR;
			break;
		case 3:
			result =  HBBLU "$n" HBBLU "尖啸一声，忽然身子一转已不见了踪影，$N" HIY			          "只觉耳边风声不断，但随即又见$n" HBBLU "回到了原地。\n" NOR;
			break;

		default:
			result = HIY "忽然间，只见$n" HBBLU "腰枝一摆，顿时出现无数个"
			         "$n" HBBLU "的影子，$N" HIY "却无法辨别出$n" HBBLU "的方位。\n" NOR;
			break;
		}
		if (!ob->is_busy()) ob->start_busy(1);
		ob->receive_damage("qi",damage2/3,me);
		ob->receive_damage("jing",damage2/3,me);
		j = -(damage+random(damage*2));
		me->add("neili", -100 );
		message_vision(result,ob,me);
		return j;
	}
	
}

/*
mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "脸上红光隐现，气象庄严。\n" ,
        "start_my_msg" : "盘膝坐下，右手食指指天，左手食指指地，口中“嘿”的一声，鼻孔中喷出了两条淡淡白气。\n",
        "start_other_msg" :  me->name() + "盘膝坐下，右手食指指天，左手食指指地，口中“嘿”的一声，鼻孔中喷出了两条淡淡白气。\n",
        "heal_my_msg" : "吐出来的白气缠住脑袋周围，缭绕不散，渐渐愈来愈浓，逐渐成为一团白雾，将你面目全都遮没了。\n",
        "heal_other_msg" :  me->name() + "吐出来的白气缠住"+ me->name() + "脑袋周围，缭绕不散，渐渐愈来愈浓，逐渐成为一团白雾，将"+ me->name() + "面目全都遮没了。\n",
        "halt_msg" :  "长出一口气，将内息急速退了回去，站了起来。\n",
        "end_my_msg" : "鼻孔中不断吸入白雾，待得白雾吸尽，你睁开双眼，缓缓站起。\n",
        "end_other_msg" : me->name()+"鼻孔中不断吸入白雾，待得白雾吸尽，"+me->name()+"睁开双眼，缓缓站起。\n",		
        "hover_my_msg" : "全身骨节格格作响，犹如爆豆。过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了。\n",
        "hover_other_msg" : "只听得"+me->name()+"全身骨节格格作响，犹如爆豆。过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了。\n",	
    ]);
}
*/