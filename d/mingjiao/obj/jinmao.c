// jinmao.c

#include <ansi.h>

inherit ITEM;

void setup()
{}
void create()
{
        set_name(RED"金毛"NOR, ({"jin mao", "mao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "撮");
                set("value", 0);
        }
        setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
