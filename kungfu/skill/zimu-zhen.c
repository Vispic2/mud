// zimu-zhen.c 子母针法
#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
"zmqidu_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action":		"$N双手连环挥舞，一招"+(order[random(13)])+"「穿心针」"NOR"，$w直奔$n的胸腹要害",
	"dodge":		100,
        "force":		200,
	"damage":		300,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "穿心针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N身形晃动，一招"+(order[random(13)])+"「破气针」"NOR"，手中$w如一串银线，往$n咽喉打去",
	"dodge":		20,
	"force":		200,
	"damage":		300,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "破气针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N五指微张，一招"+(order[random(13)])+"「吸血针」"NOR"，手中$w飞蚊般往$n全身叮去",
	"dodge":		40,
	"force":		200,
	"damage":		400,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "吸血针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N大喝一声，一招"+(order[random(13)])+"「摄魂针」"NOR"，$w幻化出夺目光亮，打向$n",
	"dodge":		50,
	"force":		200,
	"damage":		460,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "摄魂针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N错步一跃，一招"+(order[random(13)])+"「夺魄针」"NOR"，$w带着阵阵阴风，打向$n全身",
	"dodge":		60,
	"force":		200,
	"damage":		500,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "夺魄针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N双目精芒闪动，一招"+(order[random(13)])+"「离别针」"NOR"，手中$w全数脱手飞出，排山倒海般打向$n全身",
	"dodge":		50,
	"force":		200,
	"damage":		550,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "离别针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N纵声长啸，一招"+(order[random(13)])+"「天魔针」"NOR"，$w竟然带着一股强烈劲风，扫向$n",
	"dodge":		70,
	"force":		200,
	"damage":		600,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "天魔针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N眼中杀气突然大盛，一招"+(order[random(13)])+"「地煞针」"NOR"，$w飞蝗般打向$n全身",
	"dodge":		100,
        "force":		200,
	"damage":		700,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "地煞针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力够练子母连环针, 再多练练吧。\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 100)
		return notify_fail("你的碧云心法火候太浅。\n");
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("你的霹雳镖火候太浅。\n");
	if ((int)me->query_skill("liuxing-biao", 1) < 200)
		return notify_fail("你的流星赶月镖火候太浅。\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("你的追魂夺命镖火候太浅。\n");


	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("你手上并没有暗器，怎么练？\n");

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
	level   = (int) me->query_skill("zimu-zhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("你的霹雳镖火候太浅。\n");
	if ((int)me->query_skill("liuxing-biao", 1) < 200)
		return notify_fail("你的流星赶月镖火候太浅。\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("你的追魂夺命镖火候太浅。\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力不够练子母针法。\n");
	if ((int)me->query("jing") < 100)
		return notify_fail("你的精不够练子母针法。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练子母针法。\n");

	me->receive_damage("qi", 60);
	me->receive_damage("jing", 60);
	me->receive_damage("neili", 60);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("zimu-zhen", 1) >= 50 )
		return __DIR__"zimu-zhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;

        int lvl;
        int flvl;
	int damage,damage2;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！$n硬起头皮，以掌硬接！！结果身中巨毒！!\n";
}

	weapon = me->query_temp("weapon");
             
	if (random(5)==1 && me->query_skill("zhuihun-biao",1)>100)
	{
	victim->add("qi",-me->query_skill("zhuihun-biao",1)/2);
	me->add("qi",me->query_skill("zhuihun-biao",1)/2);
	return HIR"$n只觉伤口上鲜血随着暗器流出!喷了一地!!\n"NOR;
	}
        if(weapon->query("name")=="子母飞针" && weapon->query("id")=="zimuzhen" && me->query_temp("marks/子母针")         ){
          victim->apply_condition("zm_poison", random(me->query_skill("zimu-zhen")) + 50 +
	  victim->query_condition("zm_poison"));
	}
        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("zimu-zhen",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 10 && random(level2)>150 && random(2)==0) {
	victim->receive_wound("qi", (random(jiali)+100));
	return HIB"$n只觉$l上一阵麻痒，伤口尽流出了碧绿色的血!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("zimu-zhen", 1);
level2 = me->query_skill("pili-biao", 1);
        if( me->is_busy()) return 1;
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n出招时，突然所用的内力随着伤口流出!\n"NOR;
            ob->add("neili",-level2/2);
            me->add("neili",level2/2);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
         }
        if( damage < 50 ) return 1;
        if (  random(level) > 180
         && me->query_skill_mapped("throwing") =="zimu-zhen"
         && me->query_skill_mapped("parry") =="zimu-zhen"
         && weapon
         && weapon->query("skill_type") == "throwing"
         && me->query_skill("throwing") > 300
         && random(me->query_skill("throwing",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 900
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIB"$n刚出玩招后，觉得身上的伤口一阵麻痒！难受的在地上打起了滚。\n"NOR;
            ob->add("neili",-ob->query("neili")/15);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(3);
}
else             msg = HIG"$n刚出玩招后，觉得身上的伤口一阵麻痒！但$n咬了咬牙关挺了过去。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
               }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
