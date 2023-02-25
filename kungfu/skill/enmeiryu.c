 //enmeiryu.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
                "$n一把刁住$N的手腕，用力向后一捌，将$N用力甩了出去，「狼牙」！！\n",
                "$n乘$N攻击时闪出的一处破绽，突然使出一招「浮狱」，一头撞向$N的额部。\n",
        "$N眼看就要攻击到$n的一瞬间，$n一招「浮身」向后一跃，闪过了这一招。 \n",
        "$n趁着$N攻击的间隙，突然欺近。一拳击向$N的面门，用「蔓落」化解了这一招。 \n",
        "$n突然伸指截向$N的双眼，$N慌乱之际只能停止进攻，正是一招「指穿」。 \n",
        "$n一口唾液吐向$N的眼睛，一招「讣霞」躲过了$N的攻击。 \n",
});
string *unarmed_parry_msg = ({
                "$n一把刁住$N的手腕，用力向后一捌，将$N用力甩了出去，「狼牙」！！\n",
                "$n乘$N攻击时闪出的一处破绽，突然使出一招「浮狱」，一头撞向$N的额部。\n",
        "$N眼看就要攻击到$n的一瞬间，$n一招「浮身」向后一跃，闪过了这一招。 \n",
        "$n趁着$N攻击的间隙，突然欺近。一拳击向$N的面门，用「蔓落」化解了这一招。 \n",
        "$n突然伸指截向$N的双眼，$N慌乱之际只能停止进攻，正是一招「指穿」。 \n",
        "$n一口唾液吐向$N的眼睛，一招「讣霞」躲过了$N的攻击。 \n",
});
        mapping *action = ({
        ([      "action":
"$N一招「牙斩」切向$n的$l。 ",
                "dodge":                90,
                "parry":                70,
                "damage":                150,
                "damage_type":  "瘀伤",
                "name":         "牙斩",
        ]),
        ([      "action":
"$N悠地欺近$n，双拳贴在$n的衣服上，发出了一招「虎砲」。 ",
                "dodge":                50,
                "parry":                70,
                "damage":                300,
                "damage_type":  "瘀伤",
                "name":         "虎砲",

        ]),
        ([      "action":
"$N一招「破蛇」击向$n的肘内侧，紧接着踏前一步，肘部跟进击打$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤",
                "name":         "破蛇",
        ]),
        ([      "action":
"$N一招「朔光」，右拳将$n的右拳架开，右肘突然击向$n的$l。 ",
                "dodge":                10,
                "parry":                50,
                "damage":                120,
                "damage_type":  "瘀伤",
                "name":         "朔光",
        ]),
        ([      "action":
"$N大吼一声「弧月」，身子突然向后一倒，单手支地，$n正在犹豫之间，
$N的右腿已到，踢向$n的$l。 ",
                "dodge":                20,
                "parry":                100,
                "damage":                80,
                "damage_type":  "瘀伤",
                "name":         "弧月",
        ]),
        ([      "action":
"$N使出了一招「神威」，双手揪住$n的衣襟，单膝磕向$n的$l。 ",
                "dodge":                80,
                "parry":                10,
                "damage":                270,
                "damage_type":  "瘀伤",
                "name":         "神威",
        ]),
        ([      "action":
"$N向后一翻使出一招「龙破」，突然冲向$n，紧接着一个倒翻，单手支地，
双腿似剪刀般绞向$n的颈部。 ",
                "dodge":                20,
                "parry":                30,
                "damage":                470,
                "damage_type":  "瘀伤",
                "name":         "龙破",
        ]),
        ([      "action":
"$N一个转身，单腿踢向$n的面门，$n正欲招架，$N突然变招「紫电」踢
向$n的小腹。 ",
                "dodge":                150,
                "parry":                10,
                "damage":                100,
                "damage_type":  "瘀伤",
                "name":         "紫电",
        ]),

        });

int valid_enable(string usage) { return usage == "hand" ||  usage == "parry" ; }
int valid_combine(string combo) { return combo=="xuanhualiu-quanfa"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"enmeiryu/" + action;
}
int valid_learn(object me)
{

    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练陆奥圆明流拳术必须空手。\n");
    if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("enmeiryu", 1))
   return notify_fail("你的空手道火候不够，无法学。\n");

    if ((int)me->query_skill("xuanhualiu-quanfa", 1) < 10)
   return notify_fail("你的喧哗流拳法火候不够，无法学。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("你的杀意心法火候不够，无法学。\n");
    if ((int)me->query_skill("ninjitsu", 1) < 100)
   return notify_fail("你的忍术火候不够，无法学。\n");

    if ((int)me->query("max_neili") < 50)
   return notify_fail("你的内力太弱，无法练陆奥圆明流拳术。\n");

        return 1;
}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");

    if ((int)me->query("qi") < 70)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("你的内力不够练陆奥圆明流拳术。\n");
    me->receive_damage("qi", 60);
    me->add("neili", -60);
    return 1;

}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
string msg;
	int level, jiali, time,level2;
	object weapon;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*3+150;
                  msg = HIR"「三重劲!」$N以极快速的连击,在第一击后,$n没产生抵抗力时给予第二击! \n"NOR;
if (random(3)==0) msg = HIR"「隔空击物!」。$N将二重劲的威力传至远方攻击的$n,用以弥补远距离攻击的不足 。\n"NOR;
if (random(3)==1) msg = HIR"「喷射火焰!」。$N胃装油袋,用火石制的假牙点火喷出火焰,$n被极大的火焰打中!! \n"NOR;
if (random(3)==2) msg = HIR"「仙鹤飞腿!」。$N使出丑鬼直接传授的拳法之一踢向$n! 这踢法已独创一格!!\n"NOR;

if (victim->query("qi") > flvl)
{
victim->start_busy(2+random(3));
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
        }

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shayi-xinfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"只见$n$l上鲜血直流，已被无形拳劲切了开来!\n"NOR;
        }

}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
