//tianmo-jian.c 天魔剑法
//By haiyan

inherit SKILL; 

mapping *action = ({
([      "action":"$N手中$w一抖，幻化出满天剑影，一招「日月辉煌」恰似满天风雪罩向$n。",
        "force" :210,
        "attack":50,
        "dodge" :60,
        "parry" :40,
        "damage":40,
        "lvl"   :0,
        "skill_name" :"日月辉煌",
        "damage_type":"刺伤"
]),
([      "action":"$N悄然一笑，身形急旋，仿佛飞蝶戏花一般，绕着$n游走，手中$w使出一招「碧苔芳晖」接连向$n刺出五剑。",
        "force" :230,
        "attack":70,
        "dodge" :70,
        "parry" :50,
        "damage":70,
        "lvl"   :30,
        "skill_name" :"碧苔芳晖",
        "damage_type":"刺伤"
]),
([      "action":"$N大步向前，姿势飘逸，如飞燕掠过长空，一招「海天一线」手中的$w电光一闪，刺向$n。",
        "force" :250,
        "attack":90,
        "dodge" :80,
        "parry" :60,
        "damage":100,
        "lvl"   :80,
        "skill_name" :"海天一线",
        "damage_type":"刺伤"
]),
([      "action":"$N一挽手中$w，使出一招「凤舞九天」只见$N吐声发力，$w向$n点去，一股劲气夹着「啪、啪」的声音向$n卷去。",
        "force" :280,
        "attack":110,
        "dodge" :90,
        "parry" :70,
        "damage":130,
        "lvl"   :110,
        "skill_name" :"凤舞九天",
        "damage_type":"刺伤"
]),
([      "action":"$N脚步游移不定，倒转手中$w，身行如燕直冲而起，一式「微雨燕双飞」自上而下直向$n扑来。",
        "force" :320,
        "attack":130,
        "dodge" :100,
        "parry" :80,
        "damage":160,
        "lvl"   :150,
        "skill_name" :"微雨燕双飞",
        "damage_type":"刺伤"
]),
([      "action":"$N心底空明，剑随心意，身行傲然拔起，正是「空翠落庭阴」。$n为$N气势所逼，不住倒退。",
        "force" :330,
        "attack":150,
        "dodge" :110,
        "parry" :100,
        "damage":220,
        "lvl"   :180,
        "skill_name" :"空翠落庭阴",
        "damage_type":"割伤"
]),
([      "action":"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，一招「壮气蒿莱」，剑锋直向$n左肩刺过去。",
        "force" :340,
        "attack":160,
        "dodge" :120,
        "parry" :100,
        "damage":240,
        "lvl"   :210,
        "skill_name" :"壮气蒿莱",
        "damage_type":"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
     object weapon;
        
     if (me->query("gender") == "无性")
		return notify_fail("天魔剑法根本不是你这种无根无性的人所能理解的。\n");
     
	if (me->query("family/family_name") != "日月神教" || me->query("family/master_name") != "任我行")
		return notify_fail("你不是日月神教任我行弟子，无法理解天魔剑法的要领。\n");
        
     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "sword")
         return notify_fail("你必须装备剑才能学习剑法。\n");

     if ((int)me->query_skill("xixing-dafa", 1) < 150)
         return notify_fail("你的吸星大法还未大成，不能学习天魔剑法。\n");

     if ((int)me->query_skill("sword", 1) < 130)
         return notify_fail("你的基本剑法火候不够。\n");

     if ((int)me->query_skill("sword", 1) < (int)me->query_skill("tianmo-jian", 1))
         return notify_fail("你的基本剑法水平有限，无法领会更高深的天魔剑法。\n");

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
     level = (int) me->query_skill("tianmo-jian", 1);
     for(i = sizeof(action); i > 0; i--)
         if(level > action[i-1]["lvl"])
              return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
     object weapon;
     int cost;
        
     if (me->query("gender") == "无性")
		return notify_fail("天魔剑法根本不是你这种无根无性的人所能理解的。\n");
     
	if (me->query("family/family_name") != "日月神教" || me->query("family/master_name") != "任我行")
		return notify_fail("你不是日月神教任我行弟子，无法理解天魔剑法的要领。\n");
     
     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "sword")
         return notify_fail("你必须装备剑才能练剑法。\n");

     if ((int)me->query("qi") < 160)
         return notify_fail("你的体力太低了。\n");

     cost = me->query_skill("tianmo-jian", 1) / 2 + 100;
     if ((int)me->query("neili") < cost)
         return notify_fail("你的内力不够练「天魔剑法」。\n");

     me->receive_damage("qi", 130);
     me->add("neili", -cost);
     return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (victim->query("gender") == "无性" && damage_bonus > 5) {
                victim->receive_wound("qi", damage_bonus / 5);
                return HIR "你听到「哧~哧~」数声轻响，竟是有鲜血四处飞溅！"NOR"\n";
        }
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-jian/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
