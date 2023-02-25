#include <ansi.h>
inherit FORCE;
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
   if( random(5*(me->query_skill("damo-force",1))) > (damage_bonus )) {
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                        return HIB "$N发挥出"+HIR+"达摩神功"NOR HIB"的真髓,摧毁了$n的真元！！！！\n" NOR;
        }
}

int valid_enable(string usage) 
{ 
        return      usage=="force";

}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("damo-force", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的达摩神功。\n");
     if (me->query("kar") < 27)
       return notify_fail("你的富缘不够领会不了高深的达摩神功。\n");
     if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
/*    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="damo-force") continue;
        if (sname[i]=="taiji-shengong") continue;
         if (sname[i]=="fanyun-force") continue;
         if (sname[i]=="beiming-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学达摩神功？！\n");
    }*/
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("达摩神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

int effective_level() { return 21; }



string exert_function_file(string func)
{
        return __DIR__"damo-force/" + func;
}

