 // roar.c
#include <ansi.h>
void give_effect(object me,int extra,int level);
void take_effect(object me,object target,int level);
#include <combat.h>
inherit F_SSERVER;
inherit F_CLEAN_UP;
string query_name() { return "星屑"ZJBR"旋转"; }
int perform(object me, object target, int amount)
{
        object *ob;
        int i, skill, force,extra,level;

        if( !me->is_fighting() )
                return notify_fail("星屑旋转只能在战斗中使用。\n");
        if (me->query_temp("xingxiexuanzhuan")+10>time())
                                        return notify_fail("你不能这么快就施展下一次星屑旋转。\n");
        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        force = (int)me->query("neili");
        if (skill<180 && userp(me)) return notify_fail("你的明玉功尚未达到第九重，不能施展星屑旋转。\n");
        level = skill/20;
        if (level>11)
                        level = 11;
        if( userp(me) && level<10 && force < 1500 )
                return notify_fail("你的内力不够。\n");


        message_combatd(HIW"$N深吸一口气，催动第"+chinese_number(level)+"重的明玉功,脸上突然变得非红非白，整个人竟似透明的！\n",me);
        message_combatd("$N肌肉里的每一恨筋络，每一恨骨头都彷佛能看得清清楚楚，说不出的诡秘可怕！\n"NOR,me);

        me->set_temp("xingxiexuanzhuan",time());

        if (me->query_busy()<2) me->start_busy(2);
        me->start_call_out( (:call_other, __FILE__, "give_effect",me,extra,level:),1);
        //me->ccommand("say 可以楼！");

        return 1;
}

void give_effect(object me,int extra,int level)
{
        object* enemy;
        int i,count,extra_enemy;
        enemy = me->query_enemy();
        if (!sizeof(enemy)) return;
        message_combatd(HIW"$N内力非但不向外挥发，反而向内收缩，以丹田为中心形成真气漩涡！\n"NOR,me);
        for (i=0;i<sizeof(enemy);i++)
                {
                        extra_enemy =  enemy[i]->query_skill("force");
                        count = (extra-extra_enemy)/50;
                        //count = 5;
                        if (count<4) count = 4;
                        if (enemy[i]->query_temp("condition/mingyu")<count)
                                        enemy[i]->set_temp("condition/mingyu",count);
                        take_effect(me,enemy[i],level);

                        }

        }

void take_effect(object me,object target,int level)
{
        int i,j,k,max_force;
        string msg;
        object* inv;

        if (/*target->query("step_less") || */!target->query_temp("condition/mingyu") || !objectp(me) || !objectp(target) || !target->is_fighting(me))
            {
                msg = HIW"$N终于摆脱了明玉功的真气漩涡。\n"NOR;
                        message_combatd(msg,target);
                        target->delete_temp("condition/mingyu");
				return;
			}
		target->add_temp("condition/mingyu",-1);
		i = random(2);
                                                switch (i)
													{
                                                        case 0:
                                                                                if (level>=10)
                                                                                                msg = GRN"$N身处明玉功的真气漩涡中，突觉举步唯艰！。\n"NOR;
                                                                                else
                                                                                                msg = YEL"$N身处明玉功的真气漩涡中，突觉举步唯艰！。\n"NOR;
                                                                                message_combatd(msg,target);
                                                                                if (level>=10)
                                                                                                //true_busy(target,2+random(2));
                                                                                                target->start_advanced_busy(2+random(2),0,me);
                                                                                else {
                                                                                                target->start_busy(2+random(2),0,me);
                                                                                }
                                                                                break;
                                                        case 1:

                                                                                if (!target->query("neili") && level<11) {
                                                                                                msg = YEL"$N内力耗尽，脚步蹒跚，摇摇欲坠！\n"NOR;
                                                                                                message_combatd(msg,target);
                                                                                                if (target->query_busy()<2) target->start_busy(2);
                                                                                                break;
                                                                                }
                                                                                if (level>=11)
                                                                                                msg = RED"$N身处明玉功的真气漩涡中，全身气血如融雪般开始消失！\n"NOR;
                                                                                else
                                                                                                msg = WHT"$N身处明玉功的真气漩涡中，全身功力如融雪般开始消失！\n"NOR;
                                                                                message_combatd(msg,target);
                                                                                max_force = target->query("max_neili");
                                                                                if(level>=11 && max_force<=1200)
                                                                                                max_force = 1200;
                                                                                target->add("neili",-max_force/3);
                                                                                if (target->query("neili")<0) target->set("neili",0);
                                                                                if(userp(me) )
                                                                                        me->add("neili",1200);
                                                                                else
                                                                                        me->add("neili",1200);

                                                                                break;

                                                                default:
																	return 0;
													}
        //target->reomve_call_out((:call_other, __FILE__, "take_effect":))
        target->start_call_out( (:call_other, __FILE__, "take_effect",me,target,level:),2);

        return;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
