#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIY "黄金锯齿刀" NOR, ({ "juchi dao", "juchi", "dao", "blade" }) );
        set_weight(6200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "这是一柄背宽刃薄的黄金锯齿刀，刀身发出夺"
                            "目的金光，刀刃呈锯齿状。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "抽出一柄形如锯齿的宝刀，顿时"
                                 "只觉金光夺目。\n" NOR);
                set("unwield_msg", HIC "$N" HIC "弹刀清啸，心中感慨，将黄金"
                                   "锯齿刀插回刀鞘。\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_blade(700+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;



        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 12 + 2);
                return HIC "\n$N" HIC "一声大喝，手中黄金锯齿刀一振，顿"
                       "时金光一闪，逼得$n" HIC "连连后退！\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIC "\n$N" HIC "将手中黄金锯齿刀立于胸前，猛地金"
                      "刀一横，金光晃动之处$n" HIC "只觉杀气逼人。\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
