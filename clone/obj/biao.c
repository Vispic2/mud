#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG "七子刚镖" NOR, ({"qizi gangbiao"}));
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "这是一枚四川唐门秘制的刚镖，威力无比。\n");
                set("unit", "些");
                set("base_value", 2100);
                set("material", "steel");
                set("base_unit", "枚");
                set("base_weight", 10);
        }
        //set_amount(1);
        init_sword(100);
        setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
