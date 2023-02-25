// 无名剑法

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"\n$N默念 ≈幽≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 160,
        "lvl" : 0,
"skill_name" : "★幽★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIR"\n$N默念 ≈恨≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 240,
        "lvl" : 50,
"skill_name" : "★恨★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIY"\n$N默念 ≈怨≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 280,
        "lvl" : 75,
"skill_name" : "★怨★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIM"\n$N默念 ≈爱≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 320,
        "lvl" : 120,
"skill_name" : "★爱★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIC"\n$N默念 ≈思≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 380,
        "lvl" : 230,
"skill_name" : "★思★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIG"\n$N默念 ≈情≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 420,
        "lvl" : 250,
"skill_name" : "★情★字诀",
        "damage_type":        "刺伤"
]),
([      "action":CYN"\n$N默念 ≈恩≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 450,
        "lvl" : 330,
"skill_name" : "★恩★字诀",
        "damage_type":        "刺伤"
]),
([      "action":HIR"\n$N默念 ≈仇≈,剑气纵横直直指向$n的$l"NOR,
        "force" : 480,
        "lvl" : 380,
"skill_name" : "★仇★字诀",
        "damage_type":        "内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if( me->query("max_neili")<100 )
                return notify_fail("你的内力不够。\n");
//           if ((int)me->query_skill("wudu-shengong", 1) < 20)
//                  return notify_fail("你的五毒神功火候太浅。\n");
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候太浅。\n");
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
        mapping a_action;
        int i, level;
level   = (int) me->query_skill("yandang-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}


int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon=me->query_temp("weapon") )
         || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");
        if( me->query("qi")<40 )
                return notify_fail("你的体力不够练雁荡剑法。\n");
        me->receive_damage("qi", 20);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
  if( random(damage_bonus/2) > victim->query_con() ) {
                victim->receive_wound("qi", damage_bonus/ 3 );
        }
   }
string perform_action_file(string action)
{
        return __DIR__"yandang-jianfa/" + action;
}

void skill_improved(object me)
{
        int lvl, i;

        i=me->query("int")/3;
        lvl = me->query_skill("yandang-jianfa", 1);

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
