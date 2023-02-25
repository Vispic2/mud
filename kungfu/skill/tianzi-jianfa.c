#include <ansi.h> 
inherit SKILL;

mapping *action = ({
([      "action" : "$N指南打北，剑势如虹，$w忽隐忽现，忽左忽右向$n攻去",
        "force" : 510,
        "attack": 180,
        "dodge" : 115,
        "parry" : 125,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w龙吟不定，犹如长江滚滚而来，将$n笼罩在一片剑影之下",
        "force" : 510,
        "attack": 188,
        "dodge" : 112,
        "parry" : 115,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N面带九仪天尊之相，卷起手中的$w，向$n直刺过去",
        "force" : 532,
        "attack": 225,
        "dodge" : 120,
        "parry" : 102,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N舞动手中$w，幻出的一个个光环化作条条金龙，顿时将$n围得水泄不通",
        "force" : 565,
        "attack": 210,
        "dodge" : 115,
        "parry" : 105,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N飞身而起，人剑合一，犹如神龙般向$n直射而去",
        "force" : 550,
        "attack": 248,
        "dodge" : 110,
        "parry" : 120,
        "damage": 420,
        "damage_type": "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("tianzi-jianfa", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  
        object m_weapon;

        if ((int) me->query_skill("tianzi-jianfa", 1) < 150 ||
            ! (m_weapon = me->query_temp("weapon")) ||
            ! living(me) || m_weapon->query("skill_type") != "sword")
                return;


        cost = damage / 2;

        if (cost > 100) cost = 100;

        ap = ob->query_skill("force");
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("tianzi-jianfa", 1);

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIY "$n" HIY "面露九仪天尊之相，镇定自若"
                                            "，$N" HIY "只觉$n浑身毫无破绽可寻，" HIY 
                                            "一时间根本无从攻击。\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIY "$N" HIY "一招击中$n" HIY "上身"
                                            "，可却被$n帝王霸气所慑，招式顿显无力。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "但见$n" HIR "动作潇洒致极。"
                                            "随手接下了$N" HIR "这一招，却没有受到"
                                            "半点伤害。\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("tianzi-jianfa", 1);


        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300 )         
      	    return 0;


             if (objectp(weapon) && weapon->query("skill_type") != "sword")                
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "tianzi-jianfa")
                         return 0;

        if (random(2) == 1)return 0;

        if (damage_bonus / 5 > victim->query_con())
        {
                me->add("neili", -100);
                victim->receive_wound("qi", (damage_bonus - 76) / 2, me);
                victim->add("neili", -((damage_bonus - random(70)) / 2), me);
         
                return random(2) ? HIY "$N" HIY "一剑挥出，竟似招来千万条护架金龙，"
                                   "尽数射入$n" HIY "体内！\n" NOR:
                                   HIM "$N" HIM "突然连出数剑，$n" HIM "只感全身一"
                                   "震，登时被刺出数个伤口！\n" NOR;
        }
}

int practice_skill(object me)
{
        int cost;
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        
        if ( me->query_skill("tianzi-jianfa",1) < 200 )
        return notify_fail("你对天子剑法理解不够纯熟，尚不足以自行锻炼。\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 75)
                return notify_fail("你的内力不够练天子剑法。\n");

        cost = me->query_skill("tianzi-jianfa", 1) / 2 + 250;

        if ((int)me->query("neili") < cost)
                return notify_fail("你的内力不够练天子剑法。\n");

        me->receive_damage("qi", 150);
        me->add("neili", -cost);
        return 1;

}

int valid_learn(object me)
{
        int level;
        
        if( !me->query("zhuanshi",1))
 
                return notify_fail("你不曾转世如何修炼此等绝世剑法？\n");

        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以修习堂堂正正的天子剑法。\n");
     
        level = me->query_skill("tianzi-jianfa", 1);

        if (me->query_skill("sword", 1) < level)
                return notify_fail("你对基本剑法的理解还不够，无法继续领会更"
                                   "高深的天子剑法。\n");
       

        return ::valid_learn(me);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
       if ( this_player()->query_skill("tianzi-jianfa", 1) > 300)
       return 1500;
       else   return 1000;
}

string perform_action_file(string action)
{
        object me = this_player();

        if( !me->query("zhuanshi",1))
               return "未曾转世无法使用天子剑法。";

        return __DIR__"tianzi-jianfa/" + action;
}



