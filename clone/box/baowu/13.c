#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(NOR + WHT "黑索" NOR, ({  "hei suo", "hei", "suo", "whip" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "这是一根漆黑的长鞭，毫不起眼，但是入手"
                            "沉重，且\n不失柔韧，实在是千锤百炼之物。\n" NOR);
                set("long", WHT "一支通体漆黑的长鞭，看上去倒是很坚韧。\n" NOR);
                set("unit", "根");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "一伸手，悄无声息的将黑索握在手中。\n" NOR);
                set("unwield_msg", WHT "$N" WHT "将手中的黑索卷起，放回腰间。\n" NOR);
                set("stable", 100);
        }
        init_whip(600+random(320));
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
