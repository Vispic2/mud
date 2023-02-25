#include <combat.h>
inherit SKILL;
string type() { return "zhongji"; }
int tydamage = (this_player()->query("tydamage/sword")?this_player()->query("tydamage/sword"):this_player()->query_skill("langzi-sword"))*5;

mapping *action = ({
([  "action":"$N将手中$w握紧，暴喝一声，不顾$n的凌厉攻击，刺向$n的头顶",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 0,  
    "damage_type" : "刺伤"
     ]),
([  "action":"$N手中$w一抖将"HIR"$n"NOR"的攻势化去，紧跟着反身一剑刺向"HIR"$n"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 140,
    "damage_type" : "刺伤"
    ]),
([  "action":HIB"$n使出"BLINK HIY"最后杀着"NOR HIB"，怎知$N也使出了最后绝技手中$w"HIB"向$n对刺过去"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1000,
      "damage_type":"刺伤",
  ]),
});
int valid_enable(string usage) { return usage == "sword"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
      if (me->query_skill("sword",1) <= me->query_skill("langzi-sword",1))
      return notify_fail("你的基础不够，无法领会更高深的技巧！\n");
        if (me->query_skill("langzi-sword")< 250 && me->query("family/master_id")!="yang xiaoxie")
        return notify_fail("浪子三剑是通吃帮杨小邪绝技，其他师傅参悟还来不及，怎能教你？\n");
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
    level   = (int) me->query_skill("langzi-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 35 )
        return notify_fail("你的内力或气不够，没有办法练习浪子三招。\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("你装备的武器不对。\n");
    me->receive_damage("qi", 30);
    me->add("force", -20);
    me->add_temp("pratice_sword",1);
   if (me->query_temp("pratice_sword") > me->query_skill("langzi-sword",1)/20 ){
           if( (int)ob->query_amount()==1 ) {
                   ob->unequip();
                   tell_object(me, BOLD "\n你的" + ob->query("name") + "用完了！\n\n"+NOR);
           }
           ob->add_amount(-1);
           me->delete_temp("pratice_sword");
    }
   write("你按著所学练了一遍浪子三招。\n");
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 // 第二等级的伤气
        if ( me->query_skill("langzi-sword",1)>400
         && me->query_skill("damo-force",1)>300
         && me->query_skill("langzi-sword",1)<1001
&& (me->query("neili")*3) > victim->query("max_neili") ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return HIB "$N手中"BLINK HIW" 剑器 "NOR HIR"发出一阵阵"BLINK HIW" 剑气 "NOR HIR"摧毁了$n的"BLINK HIR" 真元 "NOR HIR"！！！\n" NOR;
}

 //  第三等级的伤气
        if( me->query_skill("langzi-sword",1)>1000
       && me->query("jym_level/level")>=5
    && me->query_skill("damo-force",1)>500
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return HIR "$N手中"BLINK HIC" 利刃 "NOR HIR"发出一阵阵"BLINK HIW" 剑芒 "NOR HIR"摧毁了$n的"BLINK HIR" 真元 "NOR HIR"！！！\n" NOR;
  }      
}

string perform_action_file(string action){      return __DIR__"langzi-sword/" + action;}


