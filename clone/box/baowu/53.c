#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIR "血刀" NOR,({ "xue dao", "dao", "xue", "blade" }) );
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "这是一把缠在腰间的宝刀，刀锋带着淡淡的"
                            "血影。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("material", "steel");
                set("treasure", 1);
                set("wield_msg", HIR "$N" HIR "一声阴笑，抽出一柄血红色"
                               "的单刀高高扬起，空气中顿时弥漫出一股杀气"
                               "。\n" NOR);
                set("unwield_msg", HIR "$N" HIR "一声轻哼，将手中血刀插"
                               "回背后。\n" NOR);
                set("stable", 100);
        }
        init_blade(500+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 10 + 2);
                return HIR "$N" HIR "一声大喝，手中血刀凌空劈斩而出，划"
                       "出一道道血色刀芒，直逼得$n" HIR "连连后退！\n"
                       NOR;
        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIR "$n" HIR "见周围血光漫天，刀影重重，不由得心"
                       "生畏惧，只能够勉强作出抵挡！\n" NOR;
        }
        return damage_bonus;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
