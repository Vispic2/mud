#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIR "软红蛛索" NOR,({ "ruanhong zhusuo", "ruanhong",
                                       "zhusuo", "suo", "whip" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "一支通体血红的长索，看上去很是坚韧。\n" NOR);
                set("unit", "根");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "从腰间取出一卷血红色的长索，“啪"
                                 "”地凌空抽打了一下。\n" NOR);
                set("unwield_msg", HIR "$N" HIR "一声轻哼，将手中软红蛛索盘好，"
                                 "放回腰间。\n" NOR);
                set("stable", 100);
        }
        init_whip(300+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 10 + 2);
                return HIR "$N" HIR "手中软红蛛索急速转动，挥舞出漫天鞭影，攻"
                       "得$n" HIR "眼花缭乱，措手不及！\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIR "$N" HIR "一声高喝，手中软红蛛索急速转动，登时血光"
                       "漫天，鞭影纵横，似真似幻，绞向$n" HIR "！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
