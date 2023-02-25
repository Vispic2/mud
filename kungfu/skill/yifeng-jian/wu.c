#include <ansi.h>
inherit F_SSERVER;
string query_name() { return "舞字决"; }
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("yifeng-jian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「舞字决」不能在战斗中演练。\n");
 
 if ( (string)me->query("family/family_name") != "移花宫") 
     return notify_fail("只有移花宫弟子才能使用该PFM。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先去找一把剑。\n");
    if( !skill || (skill < 60))
        return notify_fail("你的移风剑法等级不够！\n");
    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够！\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("你的基本剑法不够，无法通过演练「舞字决」提高移风剑法的技巧！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神演练「舞字决」！\n");
 write(HIW "你使出移风剑法之「舞字决」，将手中" + weapon->name() + HIW "挥舞了几下，移风剑法似乎更深进了一些。\n" + NOR);

    me->add("neili", -50);
    me->add("jing", jing_cost);
    if ( skill < 60)
        me->improve_skill("yifeng-jian", 10);
    else if (skill < 90)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() - 9));
    else if (skill < 140)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 2 - 9));
    else if (skill < 200)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 4 - 9));
    else
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 8 - 9));
//write(HIG"你的「移风剑法」进步了！\n" + NOR);

      if (random(10)>8)    me->start_busy(1);
    return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
