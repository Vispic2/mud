#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "万剑"ZJBR"归宗"; }

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        object *ob;
        int i, skill, damage;

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("非蜀山不能用「万剑归宗」！\n");

        if( (int)me->query("neili") < 300 )        
             return notify_fail("你现在没有足够的法力使用「万剑归宗」。\n");        
        if( (int)me->query("max_neili") < 2000 )
             return notify_fail("你法力不够雄厚不能使用「万剑归宗」。\n");       

        if ((int)me->query("jing") < 1000)
                return notify_fail("你现在没有足够的精力使用「万剑归宗」。\n");

        if( (int)me->query_skill("xianfeng-spells", 1) < 500 )
                return notify_fail("你的仙风云体术火侯还没到，「万剑归宗」使不出来。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        skill = me->query_skill("xianfeng-spells", 1);

        me->add("neili", -300);
        me->add("max_neili", -5);
        me->receive_damage("jing", 200);

        me->start_busy(2);
        message_vision(
   HIR "$N使出仙风云体术密传绝技「万剑归宗」，\n"
       "刹时四面八方无数剑气回荡，\n"
       "将方圆十丈之内都笼罩了起来！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                damage = (int)me->query("max_neili")*3;
                ob[i]->receive_damage("qi", damage);
                ob[i]->receive_damage("jing", damage / 2);
                tell_object(ob[i], "你觉得浑身剧痛，已经被不少剑气划伤。\n");
                if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

        me->start_busy(2+random(2));
        return 1;
}


