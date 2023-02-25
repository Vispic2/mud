 //  rouwanduanyu.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_CLEAN_UP;
string query_name() { return "乱花"ZJBR"葬玉"; }
int perform(object me, object target, int amount)
{
        object *enemys;
        int i, skill, damage,force,extra,extra_enemy,state,base,res_kee,last_damage;
        string msg;

        if( !me->is_fighting() )
                return notify_fail("乱花葬玉只能在战斗中使用。\n");
        force = (int)me->query("neili");
        if( force < 500 )
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        if (skill<160) return notify_fail("你的明玉功尚未达到第八重，不能施展乱花葬玉。\n");


                if (amount<0) amount=0;
                if (amount)
                        force = force /amount;

        me->add("force", -force/3);

        //suppose: force: 220,mingyu-force: 180, max_force: 650+220*5=1750
        //xingxiexuanzhuan最多吸到3倍 max_force = 1750 * 3 =5250
        //dam_max = 5250 * 9= 47250
        damage = skill;
        damage = damage/2+random(damage);

        //检查敌人中有没有condition/mingyu的
        state = 0;
        enemys = me->query_enemy();
        for (i=0;i<sizeof(enemys);i++)
                        {
                                state = enemys[i]->query_temp("condition/mingyu");
                                if (state) break;
                                }

        if (state)
                {
                msg = HIW "$N双目微闭，丹田处腾起一个无比刺眼气团，真气漩涡突然消失！\n"NOR;
                msg += HIW "\n气团爆裂开来，向四周电射而出，光芒足以和日月争辉！\n\n"NOR;
                }
        else
                {
                msg = HIW "$N一声尖啸，身体猛然旋转不定！\n"NOR;
                msg += HIW "\n$N从丹田出散出无数气流，犹如千万根银针，向四面八方射去！\n\n"NOR;
                }


        message_combatd(msg, me);


        for (i=0;i<sizeof(enemys);i++)
        {
            state = enemys[i]->query_temp("condition/mingyu");
            extra_enemy = enemys[i]->query_skill("force");
            last_damage = damage*2/3;
            if (last_damage<0) last_damage = 100;
            //write("damage is :"+(string)damage+"\n");
            if (random(extra+extra_enemy)<extra_enemy)
            {
                last_damage = last_damage /2;
                message_combatd(HIR"$N只觉眼前光芒刺眼，周围空气几欲沸腾，大惊之下连忙急运内功，抵御开来。\n"NOR,enemys[i]);
            }
            else
                message_combatd(HIR"$N只觉眼前无数寒光闪过，随即全身一阵刺痛，几股血柱自身上射出。\n"NOR,enemys[i]);
            res_kee = 10+(skill-180)/3;
                        if(res_kee>40)
                                res_kee = 40;
            //write("last_damage is :"+(string)last_damage+"\n");
            //state = enemys[i]->query_temp("condition/mingyu");
            //res_kee=enemys[i]->query("resistance/kee");
            enemys[i]->add_temp("resistance/jing",-res_kee);
            enemys[i]->receive_damage("jing", last_damage, me);
            enemys[i]->add_temp("resistance/jing",res_kee);
            COMBAT_D->report_status(enemys[i]);
        }
        if (me->query_busy()<3) me->start_busy(3);
            return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
