//tianmo-gun.c 日月天魔棍
//By haiyan

inherit SKILL; 

mapping *action = ({
([      "action":"$N身形稍退，手中$w迎风一抖，一招「月黑风高」，朝着$n劈头盖脸地砸将下来。",
        "force" :20,
        "attack":20,
        "dodge" :5,
        "parry" :10,
        "damage":20,
        "lvl"   :0,
        "skill_name" :"月黑风高",
        "damage_type":"砸伤"
]),
([      "action":"$N面带戚色，手中$w以一招「凄风长号」狂风骤雨般地向$n的$l连连扫去。",
        "force" :50,
        "attack":30,
        "dodge" :10,
        "parry" :25,
        "damage":30,
        "lvl"   :20,
        "skill_name" :"凄风长号",
        "damage_type":"挫伤"
]),
([      "action":"$N身形一转，手中$w往后一拖，就在这将退未退之际，一招「峰回路转」，向$n当头砸下。",
        "force" :80,
        "attack":40,
        "dodge" :20,
        "parry" :40,
        "damage":48,
        "lvl"   :50,
        "skill_name" :"峰回路转",
        "damage_type":"砸伤"
]),
([      "action":"$N身形一转，一招「寒风起兮」$w幻出满天棍影，虚虚实实地袭向$n的$l。",
        "force" :110,
        "attack":50,
        "dodge" :40,
        "parry" :55,
        "damage":65,
        "lvl"   :80,
        "skill_name" :"寒风起兮",
        "damage_type":"瘀伤"
]),
([      "action":"$N袖舞时幻起花雨满天，$w落处化作断霞千缕，一式「生死相随」，着着抢攻，全然不顾$n进招。",
        "force" :140,
        "attack":60,
        "dodge" :60,
        "parry" :70,
        "damage":75,
        "lvl"   :120,
        "skill_name" :"生死相随",
        "damage_type":"瘀伤"
]),
([      "action":"$n忽然不见$N，猛一抬头只见$N一式「策馬長川」，急风骤雨一般径直扫向$n$l。",
        "force" :170,
        "attack":70,
        "dodge" :80,
        "parry" :85,
        "damage":80,
        "lvl"   :150,
        "skill_name" :"策馬長川",
        "damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }

int valid_learn(object me)
{

     if ((int)me->query_skill("riyue-xinfa", 1) < 80)
         return notify_fail("你的内功心法火候太浅，不能学日月天魔棍。\n");

     if ((int)me->query_skill("club", 1) < 80)
         return notify_fail("你的基本棍法火候不够。\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("你的内力太低，无法学日月天魔棍。\n");

     if ((int)me->query_skill("club", 1) < (int)me->query_skill("tianmo-gun", 1))
         return notify_fail("你的基本棍法水平有限，无法领会更高深的日月天魔棍。\n");

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
     level = (int) me->query_skill("tianmo-gun", 1);
     for(i = sizeof(action); i > 0; i--)
         if(level > action[i-1]["lvl"])
              return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
     object weapon;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "club")
            return notify_fail("你使用的武器不对。\n");

     if ((int)me->query("qi") < 70)
            return notify_fail("你的体力不够练日月天魔棍。\n");

     if ((int)me->query("neili") < 80)
            return notify_fail("你的内力不够练日月天魔棍。\n");

     me->receive_damage("qi", 65);
     me->add("neili", -68);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-gun/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
