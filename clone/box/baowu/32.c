#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIC "冷月宝刀" NOR, ({ "lengyue baodao", "lengyue", "baodao", "dao", "blade" }) );
        set_weight(6200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "这是一柄形如冷月的宝刀，整个刀身冷气森森，锐利无比。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIC "$N" HIC "抽出柄形如冷月的长刀，顿时只觉寒气逼"
                                 "人，刀光如水，流转不定。\n" NOR);
                set("unwield_msg", HIC "$N" HIC "弹刀清啸，心中感慨，将冷月宝刀插回"
                                 "刀鞘。\n" NOR);
                set("stable", 100);
        }
        init_blade(600+random(320));
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
                return HIC "$N" HIC "一声大喝，手中冷月宝刀一振，顿时漾起一层波澜，逼"
                       "得$n" HIC "连连后退！\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIC "$N" HIC "将手中冷月宝刀破空划出，霎时竟掀起千层刀芒，寒气"
                       "逼人，$n" HIC "全身不由得一颤！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
