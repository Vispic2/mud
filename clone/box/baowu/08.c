#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(NOR + GRN "绿玉洞箫" NOR, ({"lvyu dongxiao", "lvyu", "dongxiao", "xiao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", GRN "一支绿玉做成的洞箫，看上去晶莹温润。武林"
                            "中人经常以萧代剑。\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "stone");
                set("wield_msg", GRN "$N" GRN "大袖一挥，手中已多了一支晶莹温润的绿玉洞萧。\n" NOR);
                set("unwield_msg", GRN "$N" GRN "手中绿玉洞箫一转，眨眼间已然不见影踪。\n" NOR);
                set("stable", 500+random(320));
        }
        init_sword(100);
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
