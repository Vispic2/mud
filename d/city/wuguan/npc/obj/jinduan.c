//jinduan.c 

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"锦缎"NOR, ({ "jin duan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
