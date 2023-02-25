
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG "唐花" NOR, ({"tang hua", "hua" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR"这是一朵铁花，但美若昙花，精致玲珑，让人一看之下，就动人心魄。\n"NOR);
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
