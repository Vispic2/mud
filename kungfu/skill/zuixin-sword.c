//zuixin-sword  by:system_2
//change by jerry@ty 
inherit SKILL;
string type() { return "zhongji"; }
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([  "action":"$N发出一招「"+(order[random(13)])+"七巧玲珑"+NOR+"」，手中$w一连划出七道剑光刺向$n的$l",
    "force" : 120,
    "lvl" : 0,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w一抖，一招「"+(order[random(13)])+"醉灌天"+NOR+"」，斜斜一剑从下往上撩向$n的$l",
    "force" : 160,
    "lvl" : 18,
    "damage_type":  "割伤"
]),
([      "action" : "$N一招「"+(order[random(13)])+"去留人间"+NOR+"」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
        "force"  : 328,
        "lvl"    : 220,
        "skill_name" : "去留人间",
        "damage_type" : "刺伤"
]),
([      "action": "$N一式「"+(order[random(13)])+"怀中抱月"+NOR+"」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
        "force" : 167,
        "lvl"   : 50,
        "skill_name" : "怀中抱月",
        "damage_type":  "刺伤"
]),
([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「"+(order[random(13)])+"情连航慈"+NOR+"」刺向$n的咽喉",
        "force" : 282,
        "lvl"   : 170,
        "skill_name" : "情连航慈",
        "damage_type":  "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「"+(order[random(13)])+"群仙聚会"+NOR+"」，右手$w带着一团剑花，逼向$n的$l",
        "force"  : 291,
        "lvl"    : 160,
        "skill_name" : "群仙聚会",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「"+(order[random(13)])+"去留人间"+NOR+"」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
        "force"  : 328,
        "lvl"    : 220,
        "skill_name" : "去留人间",
        "damage_type" : "刺伤"
]),
([  "action":"$N身形左右摇摆，手一抖间剑芒大盛，一招「"+(order[random(13)])+"柳叶剑"+NOR+"」攻向$n的$l",
        "force" : 520,
        "lvl" : 120,
    "damage_type":  "刺伤"
]),
([  "action":"$N看出$n招式中的破绽，心下一静，「"+(order[random(13)])+"凌风双飘剑"+NOR+"」已攻入$n破绽之中",
        "force" : 580,
        "lvl" : 140,
    "damage_type":  "刺伤"
]),
([  "action":HIB"$N使出一式「"+(order[random(13)])+"大雁回翔"+HIB+"」，手到剑到，$n被攻的手忙脚乱"NOR,
     "force" : this_player()->query_skill("zuixin-sword",1),
      "lvl" : 1050,
    "damage_type": "挫伤"
]),
([  "action":HIW"$N微微一笑，「"+(order[random(13)])+"天河倒泻"+HIW+"」剑招狂射而出，手中$w"HIW"直逼向$n眼前"NOR, 
     "force" : this_player()->query_skill("zuixin-sword",1),
     "lvl" : 1100,
    "damage_type": "挫伤"
]),
([  "action":HIC"$N剑法凌乱，化自狂风剑法的剑招「"+(order[random(13)])+"青翎舞"+HIC+"」，已将$n困在道道剑光之中"NOR, 
     "force" : this_player()->query_skill("zuixin-sword",1),
     "lvl" : 1200,
    "damage_type": "挫伤"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 60;  }
mapping query_action(object me,object weapon)
{

    mapping a_action;
    int i, level, medj;
    me = this_player();
    medj    = (int) me->query("jym_level/level",1);
    level   = (int) me->query_skill("zuixin-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/4;
    a_action["damage"] = level/5+medj*20+me->query("beiming-shengong",1)/100;
    return a_action;

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 //  第六等级的伤气
      if( me->query_skill("zuixin-sword",1)>4000
         && me->query_skill("beiming-shengong",1)>1200
  && (me->query("neili")*6) > victim->query_max_neili() ) {
              victim->receive_damage("qi", damage_bonus/2, me);
return HIR "$N的醉心剑法已到"BLINK HIC" 最高等级 "NOR HIR"发出一阵阵"BLINK HIW" 剑芒 "NOR HIR"摧毁了$n的"BLINK HIR" 真元 "NOR HIR"！！！\n" NOR;
  }      

 //  第五等级的伤气
      if( me->query_skill("zuixin-sword",1)>3000
         && me->query_skill("beiming-shengong",1)>1000
  && (me->query("neili")*5) > victim->query_max_neili() ) {
              victim->receive_damage("qi", damage_bonus/4 , me);
return HIR "$N催动"HIC"北冥真气"HIR"击出一股强劲剑气"HIG"$n"HIR"一分神已重伤吐血！！！\n" NOR;
  }      
 //  第四等级的伤气
      if( me->query_skill("zuixin-sword",1)>2000
         && me->query_skill("beiming-shengong",1)>900
  && (me->query("neili")*4) > victim->query_max_neili() ) {
                victim->receive_damage("qi", damage_bonus/6, me);
return HIG "$N催动"HIC"北冥真气"HIR"击出一股强劲剑气"HIG"$n"HIR"一分神已重伤吐血！！！\n" NOR;
  }      


 // 第二等级的伤气
        if ( me->query_skill("zuixin-sword",1)>400
         && me->query_skill("langzi-sword",1)<1001
         && me->query_skill("beiming-shengong",1)>300
&& (me->query("neili")*3) > victim->query_max_neili() ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 10 , me);
return HIC "$N的北冥真气凝于剑上，$n一分神就被剑上的真力所伤！！！\n" NOR;
}

 //  第三等级的伤气
      if( me->query_skill("zuixin-sword",1)>1000
         && me->query_skill("beiming-shengong",1)>600
  && me->query("jym_level/level")>=10
  && (me->query("neili")*3) > victim->query_max_neili() ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return HIR "$N将体内一股强大的"HIC"北冥真气"HIR"凝于剑尖之上，"HIG"$n"HIR"一分神已重伤吐血！！！\n" NOR;
  }      


      return 1;
}


int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练逍遥醉心剑法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你还是先找把剑来吧。\n");

        if ((int)me->query_max_neili() < 50000)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query("jym_level/level") < 10)
                return notify_fail("你的等级太低，请高于10级再学习，强行练习小心走火入魔！");
    if ((int)me->query_skill("zuixin-sword",1) > 200)
        return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");
    if (me->query_skill("sword", 1)<=me->query_skill("zuixin-sword",1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
       if ((int)me->query_skill("beiming-shengong", 1) < 40)
        return notify_fail("你的北冥神功火候太浅。\n");

     return 1;
}


string perform_action_file(string action)
{
    return __DIR__"zuixin-sword/" + action;
}

