// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【龙形搏击】dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)

inherit SKILL;

mapping *action = ({
   ([   "action":
"$N纵身跃起，一招「飞龙在天」，双掌以排山倒海之势击向$n的$l",
     "dodge":     -10,
     "parry":     -10,
     "force":     150,
     "damage_type":     "瘀伤",
     "weapon" :     "双掌",
     "parry_msg":   "只听见「锵」一声，被$N劈手格开",
   ]),
   ([   "action":
"$N似退反进，突然欺身向前，五指如钩，对准$n的$l一把抓了过去",
     "dodge":     10,
     "parry":     -20,
     "force":     100,
     "damage_type":     "抓伤",
     "weapon":     "右手五指",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
   ]),
   ([   "action":
"只见$N一旋身，双腿如铁棍一般扫向$n。这一招「神龙摆尾」当真是防不胜防",
     "dodge":     -10,
     "parry":     -20,
     "force":     120,
     "damage_type":     "砸伤",
     "weapon":     "双腿",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
   ]),
   ([   "action":
"$N忽发龙吟，使出一招「龙战于野」，啸声中和身而上，向$n直撞而来",
     "dodge":     10,
     "parry":     -10,
     "force":     100,
     "damage_type":     "撞伤",
     "weapon":     "全身",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
   ]),
            ([   "action":
"只见$N一个筋斗翻在半空，一招「龙腾四海」将发未发，但是全身劲气疾卷$n",
     "dodge":     0,
     "parry":     -20,
     "force":     150,
     "damage_type":     "内伤",
     "weapon":     "劲气",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
   ]),
            ([   "action":
"$N身形一长，朝$n劈面就是一拳。这招「苍龙出海」势若奔雷，锐利无比",
     "dodge":     10,
     "parry":     -30,
     "force":     180,
     "damage_type":     "瘀伤",
     "weapon":     "拳头",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
   ]),
});

int valid_learn(object me)
{
   if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
     return notify_fail("你的龙神心法还不够精湛，无法领会更深层的龙形搏击！\n");


   if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("练龙形博击必须空手。\n");
   return 1;
}

int valid_enable(string usage)
{
   return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("你的龙神心法还不够精湛，无法领会更深层的龙形搏击！\n");

   if( (int)me->query("sen") < 50)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");

   if( (int)me->query("kee") < 50 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");

   if( (int)me->query("force") < 20 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("kee", 30);
   me->add("force", -20);

   return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
