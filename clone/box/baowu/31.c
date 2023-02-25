#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(HIR "葵花针" NOR, ({ "kuihua zhen", "kuihua", "zhen", "pin" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIR "一根血红色的细针，也不知道是用什么金属铸成。\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "silver");
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("sword") < 250)
                return damage_bonus / 2;


        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 16 + 2);
                return random(2) ? HIR "只见$N" HIR "腰枝猛摆，幻出无数身影，$n"
                                   HIR "招架顿时散乱，不由连退数步！\n" NOR:

                                   HIR "$N" HIR "一声冷笑，单手轻轻一弹，红光飞"
                                   "射，$n" HIR "登时如遭电击，全身酸麻！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return random(2) ? HIR "$n" HIR "只见眼前红光跃动，有若鬼魅，但"
                                   "觉胸口一阵刺痛，溅出几滴鲜血！\n" NOR:

                                   HIR "$N" HIR "身形一晃，已不见了踪影，却听$n"
                                   HIR "一声惨叫，葵花针竟已入体半分！\n" NOR;

        case 2:
                return HIR "$N" HIR "身形飘忽，化作一簇红芒急速跃动，$n"
                       HIR "霎时只觉眼花缭乱，无从招架！\n" NOR;

        case 3:
                return HIR "只见$N" HIR "蓦地里疾冲上前，瞬间已至$n" HIR
                       "跟前，阴笑两声，又随即跃开！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
