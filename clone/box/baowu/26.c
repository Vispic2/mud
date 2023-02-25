#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "金蜈钩" NOR,({ "jinwu gou", "gou", "jinwu", "jin" }) );
        set_weight(3500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "一柄金光闪闪的钩子，很是锋利，顶端好似一只"
                            "蛇头。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "冷笑一声，从背后抽出一柄奇形"
                                 "怪状的金钩连挥数下，顿时金芒四射。\n" NOR);
                set("unwield_msg", HIY "$N" HIY "一声轻哼，将手中金蜈钩插回"
                                 "背后。\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
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
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIY "$N" HIY "将手中金蜈钩凌空劈斩而出，划出一道华丽"
                       "的金芒，直逼得$n" HIY "连连后退！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIY "$N" HIY "一声厉啸，身形冲天而起，手中金蜈钩金光"
                       "四射，连刺$n" HIY "全身各处要穴！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
