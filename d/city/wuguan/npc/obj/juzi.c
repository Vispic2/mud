//juzi.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("锯子", ({ "ju zi", "ju", "blade" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一用来锯木头的锯子，普通百姓的日常用品。\n");
                set("value", 50);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的扛在肩上。\n");
        }
        init_blade(4);
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
