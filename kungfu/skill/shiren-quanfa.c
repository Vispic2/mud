//npc武功，不开放!!
//npc武功，不开放!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action" : "$N盘膝而坐，二手合十，一式"+(order[random(13)])+"「翔」"NOR"，双拳蓄势而发，击向$n的$l",
    "force" : 180,
    "dodge" : 55,
    "damage": 170,
    "lvl" : 0,
    "skill_name" : "翔",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式"+(order[random(13)])+"「霞」"NOR"，双掌轮流下击，拳势如焰，吡啪爆响",
    "force" : 200,
    "dodge" : 55,
    "damage": 170,
    "lvl" : 20,
    "skill_name" : "霞",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N腾空飞起，一式"+(order[random(13)])+"「息吹」"NOR"，双手双腿齐出，令$n无可躲藏",    
    "force" : 230,
    "dodge" : 55,
    "damage": 200,
    "lvl" : 40,
    "skill_name" : "息吹",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌虚含，掌缘下沉，一式"+(order[random(13)])+"「无明」"NOR"，缓缓向$n推出",
    "force" : 270,
    "dodge" : 55,
    "damage": 220,
    "lvl" : 60,
    "skill_name" : "无明",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一臂前伸，一臂后指，一式"+(order[random(13)])+"「无常」"NOR"，攻向$n的身前身后",    
    "force" : 320,
    "dodge" : 50,
    "damage": 215,
    "lvl" : 80,
    "skill_name" : "无常",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式"+(order[random(13)])+"「刹那」"NOR"，两手十指虚点$n的全身三十六道要穴",
    "force" : 380,
    "dodge" : 55,
    "damage": 225,
    "lvl" : 90,
    "skill_name" : "刹那",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N两目内视，双手内笼，一式"+(order[random(13)])+"「不动击」"NOR"，四面八方响起震人心魄的
龙吟",
    "force" : 450,
    "dodge" : 55,
    "damage": 235,
    "lvl" : 100,
    "skill_name" : "不动击",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N似笑非笑，双拳无形无定，一式"+(order[random(13)])+"「影分生」"NOR"，骤然击向$n的前胸",
    "force" : 530,
    "dodge" : 50,
    "damage": 150,
    "lvl" : 60,
    "skill_name" : "影分生",
    "damage_type" : "瘀伤"
]),
(["action" :"$N双臂一挥，第一式"+(order[random(13)])+"「影舞」"NOR"打出，以通臂之势，拳消力不消，劲风直逼$n而去",
  "force" : 150,
  "dodge" : 55,
    "damage": 215,
  "lvl" : 5,
  "skill_name" : "影舞",
  "damage_type" : "瘀伤"
]),
(["action" :"$N躬腰曲背，左臂一抡，架起一道气墙，接着右手握拳，对着$n，一招"+(order[random(13)])+"「山岗」"NOR"穿墙而出",
  "force" : 200,
  "dodge" : 110,
    "damage": 215,
  "lvl" : 15,
  "skill_name" : "山岗",
  "damage_type" : "瘀伤"
]),
(["action" :"$N一个马步式"+(order[random(13)])+"「龙椎旋」"NOR"，双拳凝力，跟着两臂相并，对准$n$l一式挥出，劲力异常",
  "force" : 220,
  "dodge" : 115,
    "damage": 115,
  "lvl" : 25,
  "skill_name" : "龙椎旋",
  "damage_type" : "瘀伤"
]),
(["action" :"$N使出一招"+(order[random(13)])+"「受流」"NOR"，双臂连连挥动，拳风伴着口中的狮子吼，如猛兽下山般袭向$n",
  "force" : 240,
  "dodge" : 120,
    "damage": 215,
  "lvl" : 45,
  "skill_name" : "受流",
  "damage_type" : "瘀伤"
]),
(["action" :"$N单臂抡起一式"+(order[random(13)])+"「直式」"NOR"打出，接着又是一拳相随，后浪推前浪，两波劲力合击$n",
  "force" : 260,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 65,
  "skill_name" : "直式",
  "damage_type" : "瘀伤"
]),
(["action" :"$N挥出数拳，正当$n质疑这花拳之势时，一股劲风爆出，正对$p胸口，是招虚实的"+(order[random(13)])+"「必至」"NOR"",
  "force" : 280,
  "dodge" : 110,
    "damage": 215,
  "lvl" : 75,
  "skill_name" : "必至",
  "damage_type" : "瘀伤"
]),
(["action" :"$N口颂佛经，打出一招"+(order[random(13)])+"「斜式」"NOR"，直轰$n前胸，拳风至刚至阳，正大光明，不带丝毫阴气",
  "force" : 300,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 85,
  "skill_name" : "斜式",
  "damage_type" : "瘀伤"
]),
(["action" :"只见$N合十而立，以这"+(order[random(13)])+"「伏式」"NOR"一招为本，以身为拳，劲力布满全身，重重压向$n",
  "force" : 450,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 105,
  "skill_name" : "伏式",
  "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="unarmed" ||usage=="parry"; }     


int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不够，没有办法练日本古武术。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 200)
   return notify_fail("你的杀意心法火候不够。\n");

 if ((int)me->query_skill("xuanhualiu-quanfa", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的喧哗流拳法火候不够，无法学。\n");

 if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的合气道火候不够，无法学。\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的五行遁火候不够，无法学。\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("日本古武术必须配合杀意心法才能练。\n");

    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("你的杀意心法火候不够。\n");

 if ((int)me->query_skill("xuanhualiu-quanfa", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的喧哗流拳法火候不够，无法学。\n");

 if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的合气道火候不够，无法学。\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("你的五行遁火候不够，无法学。\n");

        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 100 )
                return notify_fail("你的内力或气不够，没有办法练习日本古武术。\n");
        me->receive_damage("qi", 80);
        me->add("neili", -80);
        //write("你按著所学练了一遍日本古武术。\n");
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
    object ob;
    ob = me->select_opponent();
if (!ob) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
if (!me) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

    level   = (int) me->query_skill("shiren-quanfa",1)/10;
    if (!userp(me) || (int)me->query_skill("shayi-xinfa", 1) > 10)
{
if (  me->query_skill_mapped("parry") == "shiren-quanfa"
&&  !me->is_busy()
&&living(ob)
&& !me->query_temp("dsauto")
&& !me->query_temp("sc_hama")
&& random(me->query_skill("shiren-quanfa",1))> 180
)
{
	 message_vision(HIW"\n「二重劲!」$N以极快速的连击,在第一击后,$n没产生抵抗力时给予第二击! \n"NOR, me,ob);
me->set_temp("dsauto",1);
	me->add_temp("apply/attack", (level*2));
	me->add_temp("apply/damage", (level*4));
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	me->add_temp("apply/attack", -(level*2));
	me->add_temp("apply/damage", -(level*4));
me->delete_temp("dsauto");
}
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

string perform_action_file(string action)
{
    return __DIR__"shiren-quanfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shiren-quanfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"只见$n$l上鲜血狂奔，已被无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("shiren-quanfa", 1);

//        if( me->is_busy()) return 1;

        if( me->is_busy()) return 1;
        if( damage < 10 ) return 1;
    if ((int)me->query_skill("shayi-xinfa", 1) < 10 && userp(me)) return 1;
        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="shiren-quanfa"
         && me->query_skill("unarmed") > 150
         && random(me->query_skill("unarmed",1)) > 150
           ){
         msg = HIG"$N面对$n的攻势。身形一闪，突出狠招!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「 隔空击物! 」。$N将二重劲的威力传至远方攻击的$n,用以弥补远距离攻击的不足 。\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
}
else
{
ob->add("qi",-5000);
ob->add("qi",-5000);
}
msg += damage_msg(damage, "瘀伤");



            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「仙鹤飞腿!」。$N使出丑鬼直接传授的拳法之一踢向$n! 这踢法已独创一格!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
}

msg += damage_msg(damage, "瘀伤");
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「喷射火焰!」。$N胃装油袋,用火石制的假牙点火喷出火焰,$n被极大的火焰打中!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
}
else
{
ob->add("qi",-3500);
ob->add("qi",-3500);
}
msg += damage_msg(damage, "瘀伤");
            }
else
           msg = HIG"$n认得这招历害,逃了开来，还好无事!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
