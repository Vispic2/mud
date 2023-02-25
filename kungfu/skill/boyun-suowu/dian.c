#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>
string query_name() { return "云雾"ZJBR"暗点"; }
int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        
        if (! target) 
        {
                me->clean_up_enemy(); 
                target = me->select_opponent(); 
        }

        if (userp(me) && ! me->query("can_perform/boyun-suowu/dian")) 
                return notify_fail("你还没有受过高人指点，无法施展「云雾暗点」。\n"); 
                    
        if( me->query_temp("weapon") )
                return notify_fail("你手上不能装备任何东西。\n");

        if (! me->is_fighting(target)) 
                return notify_fail("只能对战斗中的对手使用。\n"); 

        if( (int)me->query_skill("boyun-suowu", 1) < 100 )
                return notify_fail("你的「拨云锁雾」不够娴熟，不能使用「云雾暗点」。\n");

        if( (int)me->query_skill("biyun-xinfa",1) < 100)
                return notify_fail("你的心法不够熟练！\n");

        if( (int)me->query("neili") < 400 ) 
                return notify_fail("你的内力不够。\n");

        ap =  me->query_dex();
        dp =  target->query_dex();

        msg = HIG "$N手腕一翻，信手一个拈花诀，内力暗吐，“嗤”的一声，破空而去!\n"NOR;

        message_vision(msg, me, target);

        me->add("neili", -80);
        
        if (ap / 2 + random(ap) > dp)        
        {
                if (! target->is_busy())
                        target->start_busy( 2 + (int)me->query("hand")/50);
                msg = HIC "$n全身顿觉一麻，似乎不能动弹。\n"NOR;
        }  
        else 
                msg = HIM "只见$n侧身一让，一阵风声，破空而过！\n"NOR;  
        message_vision(msg, me, target);
        
        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
