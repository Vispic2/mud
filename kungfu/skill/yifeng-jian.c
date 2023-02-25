inherit SKILL;

//string type() { return "zhongji"; }
//剑法不消失就是因为这行，以后有时间在研究，现注释

int tydamage = (this_player()->query("tydamage/sword")?this_player()->query("tydamage/sword"):this_player()->query_skill("yifeng-jian"))*5;

mapping *action = ({
([      "action":"$N使一式「花随风移」，手中$w嗡嗡微振，幻成一无数花瓣刺向$n的$l",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 160,
        "skill_name" : "花随风移",
        "damage_type":  "刺伤"
]),
([      "action":"$N移步上前，使出「雨花纷飞」，剑气围绕，$w淡淡地向$n的$l挥去",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 160,
        "lvl" : 10,
        "damage_type" : "刺伤"
]), 
([      "action":"$N一式「"HIM"花起剑落"NOR"」，纵身飘开数尺，运发剑气，手中$w遥遥飞向$n的$l",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 180,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([      "action":"$N纵身轻轻跃起，一式「"HIC"紫花飞舞"NOR"」，剑光化为紫色，飘向$n的$l",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 200,
        "lvl" : 130,
        "damage_type" : "刺伤"
]),
([      "action":"$N手中$w中宫直进，一式「"HIB"花开花谢"NOR"」，无声无息地对准$n的$l刺出一剑",
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 220,
        "lvl" : 140,
        "damage_type" : "刺伤"
]), 
  ([      "action":"$N手中$w斜指苍天，剑芒吞吐，一式「"HIY"飞花落叶"NOR"」，对准$n的$l斜斜击出"NOR,  
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 240,
     "lvl" : 150,  
        "damage_type" : "刺伤"
]),
  ([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「"HIG"春回大地"NOR"」刺向$n的$l"NOR, 
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 240,
     "lvl" : 160,  
        "damage_type" : "刺伤"
]),
  ([      "action":HIM"狂风大起,只见花瓣到处飞舞,突然无数花瓣割向$n,$n顿时鲜血直喷"NOR, 
        "force" : 160,
        "dodge" : 80,
        "parry" : 40,
        "damage" : 280,
     "lvl" : 160, 
     "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if (me->query_skill("yifeng-jian")< 120 && me->query("family/master_id")!="yao yue")
        return notify_fail("移风剑法是移花宫绝技，只有宫主邀月才能教你？\n");

        if ((int)me->query_skill("mingyu-shengong", 1) < 20)
                return notify_fail("你的冥雨神功火候太浅。\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yifeng-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的移风剑法。\n");

        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("yifeng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;
      if( me->query("neili") < 500   ) return 0;
      if( random(10) < 2   ) return 0;

 //  第六等级的伤气
      if( me->query_skill("yifeng-jian",1)>250  ) {
              victim->receive_damage("qi", (damage_bonus ) * 2 , me);
return WHT "$N剑带花舞，移风剑法的精髓在无形中表露无遗，登时$n全身血液顿时沸腾！！！\n" NOR;
  }      

 //  第五等级的伤气
      if( me->query_skill("yifeng-jian",1)>200  ) {
              victim->receive_damage("qi", damage_bonus  , me);
return YEL "$N的移风剑法已经达到人剑合一的境界，随手数道剑气分刺$n数处大穴！！！\n" NOR;
  }      
 //  第四等级的伤气
      if( me->query_skill("yifeng-jian",1)>180 ) {
           victim->receive_damage("qi", (damage_bonus - 100)  , me);
return MAG "$N灵台光闪，瞬间领悟到玉箫剑法髓，随手一剑妙到毫颠！！！\n" NOR;
  } 


 //  第三等级的伤气
        if( me->query_skill("yifeng-jian",1)>150  ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return CYN "$N的移风剑法已入返璞归真境界，随意一剑带出一阵剑气扑向$n！！！！！\n" NOR;
  }   
 // 第二等级的伤气
        if ( me->query_skill("yifeng-jian",1)>120 ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return RED "$N的移风剑法已初有小成,每出一剑都带着强烈"HIR"剑气"HIW"扑向$n！！\n" NOR;
}   
}

int practice_skill(object me)
{
    return notify_fail("移风剑法只能通过「"+HIC+"舞字决"+NOR+"」来演练。\n");
}

string perform_action_file(string action)
{
        return __DIR__"yifeng-jian/" + action;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
