#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
        set_name(HIG "南海神木" NOR, ({ "nanhai shenmu", "nanhai", "shenmu", "club" }) );
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "半截蓉绿半截焦枯的木棍，看似普通，却竟如铁铸一般，坚硬无比。\n" NOR);
                set("unit", "根");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "拿出一根半截蓉绿半截焦枯的木棍握在手中。\n" NOR);
                set("unwield_msg", HIG "$N" HIG "将手中的南海神木挥舞个圈子，插回背上。\n" NOR);
                set("stable", 100);
        }
        init_club(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;



        switch (random(8))
        {
        case 0:
                n = me->query_skill("club");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "$N" HIG "跨步上前，手中南海神木转动如轮，气势如虹，接二"
                       "连三朝$n" HIG "扫去！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
