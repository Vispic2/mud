// zhuihun-biao.c 追魂夺命镖
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
});


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N手中$w一闪，一招"+(order[random(13)])+"「无常敲门」"NOR"，手腕一翻，向$n的$l打去",
	"force" : 120,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 120,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招"+(order[random(13)])+"「小鬼夜游"NOR"，往地上一滚，$w悄无声息打向$n的颈部",
	"force" : 130,
        "dodge" : 10,
        "parry" : 10,
	"damage" : 125,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N斜身进步，一招"+(order[random(13)])+"「五鬼抬轿」"NOR"，手中五枚$w,笔直飞向$n",
	"force" : 140,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 130,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招"+(order[random(13)])+"「奈何不归路」"NOR"，$w撒手飞出，竟以不可思议的角度，打向$n背面",
	"force" : 160,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 135,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招"+(order[random(13)])+"「阴雨绵绵欲断魂」"NOR"，一把$w劈头盖脸打向$n的胸口。",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 140,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N身子一踉跄，好象要跌倒，却见精芒闪动，正是一招"+(order[random(13)])+"「断肠伤心无去处」"NOR"，$w飞快罩向$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 150,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招"+(order[random(13)])+"「阎罗孤灯」"NOR"，$w闪烁不定，时快时慢，防不胜防打$n的$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 160,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N腾空跃起，一招"+(order[random(13)])+"「炼狱流火」"NOR"，数枚$w脱手而出，一枚接一枚，竟然成了一根火线向$n的全身打去",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 180,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("你的碧云心法火候不够。\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("你的碧叶随风舞火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练追魂夺命镖。\n");
	me->receive_damage("qi", 30);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
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
	
	
	weapon;weapon=me->query_temp("weapon");
              
        if(weapon && 
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmzhuihun_poison", random(me->query_skill("zhuihun-biao")) + 10 +
	  victim->query_condition("tmzhuihun_poison"));
	}
	if (random(5)==1 && me->query_skill("zhuihun-biao",1)>100 )
	{
	victim->add("qi",-me->query_skill("zhuihun-biao",1)/2);
	me->add("qi",me->query_skill("zhuihun-biao",1)/2);
	return HIR"$n只觉伤口上鲜血随着暗器流出!喷了一地!!\n"NOR;
	}
	
}
string perform_action_file(string action)
{
		return __DIR__"zhuihun-biao/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
