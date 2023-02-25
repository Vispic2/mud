//piao.c 

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("瓢", ({ "piao", "hammer" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一个用老葫芦劈开做成的瓢，普通百姓的日常务农用品。\n");
                set("value", 50);
                set("material", "steel");
                set("wield_msg", "$N拿出一个$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插在腰上。\n");
        }
        init_hammer(4);
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
