 //  rouwanduanyu.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "柔腕"ZJBR"断玉"; }
int perform(object me, object target, int amount)
{
        int i, skill, damage,extra,force,max_force,state,base,res_kee;
        string msg;

        if( !me->is_fighting() )
                return notify_fail("柔腕断玉只能在战斗中使用。\n");
        force = (int)me->query("neili");
        if( force < 500 )
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        if (skill<120) return notify_fail("你的明玉功尚未达到第六重，不能施展柔腕断玉。\n");

                                if( !target || target==me) target = offensive_target(me);
                    if( !target
                    ||      !target->is_character()
                    ||      !me->is_fighting(target) )
                            return notify_fail("［柔腕断玉］只能对战斗中的对手使用。\n");


        //suppose: force: 220,mingyu-force: 180, max_force: 650+220*5=1750
        //xingxiexuanzhuan最多吸到3倍 max_force = 1750 * 3 =5250
        //dam_max = 5250 * 9= 47250
        damage = skill;
        damage = damage/2+random(damage);

        msg = HIY "$N鼓动真气,手掌迅速幻化成见骨的透明淡黄色！\n"NOR;

        //state=damage/5000;
        //if (state>3) state=3;
        state = random(4);
        switch (state) {
                case 0:
                                msg += HIC "\n$N手腕微微一转，$n竟随着$N的手势快速旋转起来，身上多了一道黑青的掌印！\n\n"NOR;
                                break;
                case 1:
                                msg += HIG "\n$N手腕微微一转，$n如受重击，稻草一般飞了出去！\n\n"NOR;
                                break;
                case 2:
                                msg += HIR "\n$N手腕微微一转，一股血箭从$n身上喷射而出！\n\n"NOR;
                                break;
                case 3:
                                msg += HIM "\n$N手腕微转，气流突生激变，$n茫然无措中，一道气剑透体而过！\n\n"NOR;
                                break;
                }

        me->add("force",-force/4);



        message_combatd(msg,me,target);

        res_kee = 10+(skill-180)/2;
        if(res_kee>40)
                res_kee = 40;
        //state = target->query_temp("condition/mingyu");
        //res_kee=target->query("resistance/kee");
        //if (state)
        target->add_temp("resistance/jing",-res_kee);
                                extra=target->receive_damage("jing", damage, me);
        //if (state)
        target->add_temp("resistance/jing",res_kee);
        //CHANNEL_D->do_sys_channel("sys","damage is "+damage+" -res is "+res_kee+" final_damage is "+extra+"\n");
        COMBAT_D->report_status(target);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
