#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        object *ob;
        int i, skill, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili") < 4000 )
                return notify_fail("你内力不够雄厚不能使用大雅之古攻击。\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你现在没有足够的内力使用大雅之古。\n");

        if ((int)me->query("jing") < 1000)
                return notify_fail("你现在没有足够的精力使用大雅之古。\n");

        if( (int)me->query_skill("daya-jian", 1) < 150 )
                return notify_fail("你的大雅古剑法火侯还没到，大雅之古使不出来。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        skill = me->query_skill("daya-jian", 1);

        me->add("neili", -300);
        me->receive_damage("jing", 200);

        me->start_busy(2);
        message_vision(
   HIR "$N使出大雅古剑法密传绝技「大雅之古」，\n"
       "刹时四面八方无数剑气回荡，\n"
       "将方圆十丈之内都笼罩了起来！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                damage = (int)me->query_skill("daya-jian", 1);
                damage = (int)me->query_skill("daya-jian", 1) +damage;
                damage = random(damage)+5000;
                if( damage > 10000 ) damage = 10001;
                ob[i]->receive_damage("qi", damage , me);
                ob[i]->receive_damage("jing", damage / 2 , me);
                tell_object(ob[i], "你觉得浑身剧痛，已经被不少剑气划伤。\n");   
                if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

        return 1;
}


