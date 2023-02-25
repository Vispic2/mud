// daya-jian.c
//  大雅古剑法
// by aohan 取至xo修改加入

#include <ansi.h>
#define OO YEL"大雅古剑法"NOR
inherit SKILL;

mapping *action = ({
    ([  "action": 
"只见$N手中$w舞动出一片网状，使出"OO"第一式：「盘庚式」，\n"
"将$n周围尽皆罩住。\n",
        "lian"  :
"$N念着口诀：若网在纲，有条不紊。\n"
"只见$N手中$w舞动出一片网状，使出"OO"第一式：「盘庚式」，\n"
"将自身周围尽皆罩住。\n",
        "force"   :50,
        "neili" :150,
        "dodge" :80,
        "parry" :80,
        "skill_name":"「盘庚式」",
        "damage":500,
        "damage_type":"割伤"    ]),

    ([  "action":
"只见$N手中$w挥动一股霸道的剑气，正是"OO"第二式：「毕命式」，\n"
"对着$n左右斜劈，凛然有风。",
        "lian"  :
"$N念着口诀：彰善潸恶，树之风声。\n"
"只见$N手中$w挥动一股霸道的剑气，正是"OO"第二式：「毕命式」，\n"
"左右斜劈，凛然有风。",
        "force"   :60,
        "neili" :300,
        "dodge" :100,
        "parry" :100,
        "skill_name":"「毕命式」",
        "damage":600,
        "damage_type":"割伤" ]),
    ([  "action":
"只见$N手中$w闪出点点剑光，联成一线，正是"OO"第三式：「罔命式」，\n"
"$w带动光线，在$n面前挥舞。",
        "lian"  :
"$N念着口诀：绳衍纠谬，格其非心。\n"
"只见$N手中$w闪出点点剑光，联成一线，正是"OO"第三式：「罔命式」，\n"
"光线长久不绝。",
        "force"   :150,
        "neili" :450,
        "dodge" :120,
        "parry" :120,
        "skill_name":"「罔命式」",
        "damage":700,
        "damage_type":"割伤"    ]),
    ([  "action":
"只见$N舞动手中$w，正是"OO"第四式：「大畜式」，\n"
"剑光霍霍之中，从一个意想不到的角度突然挑出一剑，向$n的下颚直刺。",
        "lian"  :
"$N念着口诀：刚健笃实辉光，日新其德。\n"
"只见$N舞动手中$w，正是"OO"第四式：「大畜式」，\n"
"剑光霍霍之中，从一个意想不到的角度不时挑出一剑。",
        "force"   :200,
        "neili" :600,
        "dodge" :140,
        "parry" :140,
        "skill_name":"「大畜式」",
        "damage":800,
        "damage_type":"割伤"    ]),
        ([      "action":
"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，正是"OO"\n"
"第五式：「瞽蒙式」，剑锋直向$n左肩刺过去。",
                "lian" :
"$N念着口诀：鼓琴瑟，以役大师。\n"
"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，正是"OO"\n"
"第五式：「瞽蒙式」，剑锋直向前刺。",
        "skill_name":"「瞽蒙式」",
        "force" :250,
        "neili":750,
        "dodge":150,
        "parry":150,
        "damage":900,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体在原地游走，脚步散而不乱，正是"OO"第六式：「述而式」，\n"
"手中$w摆动，不时向$n刺出一剑。",
                "lian" :
"$N念着口诀：志于道，据于德，依于仁，游于艺。\n"
"只见$N身体在原地游走，脚步散而不乱，正是"OO"第六式：「述而式」，\n"
"手中$w摆动，不时刺出一剑。",
        "skill_name":"「述而式」",
        "force" :500,
        "neili":900,
        "dodge":170,
        "parry":170,
        "damage":1000,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体十分稳重，正是"OO"第七式：「至诚式」，\n"
"手中$w若有若无，缓缓击出一剑，向$n的肩部搭了过去。",
                "lian" :
"$N念着口诀：盹盹其仁，渊渊其渊，浩浩其天。\n"
"只见$N身体十分稳重，正是"OO"第七式：「至诚式」，\n"
"手中$w若有若无，缓缓击出一剑。",
        "skill_name":"「至诚式」",
        "force" :350,
        "jibie":105,
        "neili":980,
        "parry":180,
        "damage":1100,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N使出的正是"OO"第八式：「止戢式」，\n"
"手中$w剑光柔和，隐隐有风雷之声，向$n扑面涌去，令人顿有退避之意。",
                "lian" :
"$N念着口诀：载戢戈，载蠹弓矢，我求懿德，肆于时夏。\n"
"只见$N使出的正是"OO"第八式：「止戢式」，\n"
"手中$w剑光柔和，隐隐有风雷之声，令人听来顿有退避之意。",
        "skill_name":"「止戢式」",
        "force" :700,
        "neili":12000,
        "dodge":190,
        "parry":190,
        "damage":1200,
        "damage_type":"割伤"
        ]),
});

string *parry_msg = ({
"$n使出「“恒”字诀」，口中念道：日月得天而能久照，四时变化而能久成。\n"
"只见$n丝毫不乱，应接不暇，将$N的招式一一截住。",
"$n使出「“遁”字诀」，口中念道：刚当位而应，与时行也。\n"
"$n见机而动，向外轻巧地跃开。",
"$n使出「“萃”字诀」，口中念道：乃乱乃萃，其志乱也。\n"
"$n似乎有些散乱，竟尔突然定住，顿时将$N的攻势化解于无形。",
"$n使出「“革”字诀」，口中念道：文明以说，大亨以正。\n"
"$n在千钧一发之际，突然不知从什么地方横出一剑，拦住了$N的这一招。",
"$n使出「“比”字诀」，口中念道：舍逆取顺。\n"
"$n低头躲过$N这一招，闪身跃开。",
"$n使出「“需”字诀」，口中念道：刚健而不陷，其义不穷困矣。\n"
"$n无偏不偏，恰恰从$N的攻势中躲了开去。",
});

string *unarmed_parry_msg = ({
"$n使出「“恒”字诀」，口中念道：日月得天而能久照，四时变化而能久成。\n"
"只见$n丝毫不乱，应接不暇，将$N的招式一一截住。",
"$n使出「“遁”字诀」，口中念道：刚当位而应，与时行也。\n"
"$n见机而动，向外轻巧地跃开。",
"$n使出「“萃”字诀」，口中念道：乃乱乃萃，其志乱也。\n"
"$n似乎有些散乱，竟尔突然定住，顿时将$N的攻势化解于无形。",
"$n使出「“革”字诀」，口中念道：文明以说，大亨以正。\n"
"$n在千钧一发之际，突然不知从什么地方横切一掌，拦住了$N的这一招。",
"$n使出「“比”字诀」，口中念道：舍逆取顺。\n"
"$n低头躲过$N这一招，闪身跃开。",
"$n使出「“需”字诀」，口中念道：刚健而不陷，其义不穷困矣。\n"
"$n无偏不偏，恰恰从$N的攻势中躲了开去。",
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

int valid_combine(string combo) { return combo=="daya-jian"; }

int valid_learn(object me)
{
    object ob;
 if( (int)me->query("max_neili") < 2500 )
        return notify_fail("你的内力不够，没有办法修习此剑法。\n");
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
        level   = (int) me->query_skill("daya-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    weapon = me->query_temp( "weapon" );
    if ( !weapon || weapon->query("weapon_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练习剑法。\n");
    if( me->query("max_neli")<3000 )
        return notify_fail("你内力不足以练习此剑法！\n");
      me->receive_damage("qi", 2000);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 1000 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
return HIG "$N面带雅意，轻叹一声：“人本有情，剑无情，君知否？”，\n
$n听罢如胸口中了一重锤，“哇”的一声吐出一小口鲜血！\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"daya-jian/" + action;
}

