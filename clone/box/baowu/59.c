#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW "玉箫" NOR, ({ "yu xiao", "yu", "xiao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", HIW "一支白玉做成的玉箫，看上去晶莹温润。武林中人经常以箫代剑。\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "stone");
                set("wield_msg", HIW "$N" HIW "大袖一挥，手中已多了一支晶莹温润的玉箫。\n" NOR);
                set("unwield_msg", HIW "$N" HIW "手中玉萧一转，眨眼间玉箫已然不见影踪。\n" NOR);
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
                return HIW "突然间一阵尖锐的箫声至$N" HIW "处传来，$n" HIW
                       "顿时只觉得太阳穴隐隐刺痛！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("jing", n / 3);
                victim->receive_wound("jing", n / 3);
                return HIW "$N" HIW "手中玉箫随招式激荡出阵阵箫音，$n" HIW
                       "顿时只觉气血上涌，难受之极！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
