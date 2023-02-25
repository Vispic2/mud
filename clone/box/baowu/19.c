#include <weapon.h>
#include <ansi.h>
 
inherit THROWING;
 
void create()
{
        set_name(HIC "回龙璧" NOR, ({ "huilong bi", "huilong", "bi" }));
        set_weight(100);
        if (clonep()) 
                set_default_object(__FILE__); 
        else {
                set("long", HIC "一支温莹剔透的玉壁，上面雕纹着一条蛟龙。\n" NOR);
                set("unit", "支");
                set("value", 8000);
                set("treasure", 1);
                set("material", "stone");
                set("base_unit", "支");
                set("base_weight", 100);
                set("base_value", 1000);
        }
        set_amount(80);
        init_throwing(600+random(320));
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
