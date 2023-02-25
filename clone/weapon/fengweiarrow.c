// arrow.c
 
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

int is_arrow() { return 1; }
 
void create()
{
	set_name(HIC "凤尾箭" NOR, ({ "arrow", "jian" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC "一根细长的羽箭，可以连珠箭发，势道十分凶猛。\n" NOR);
		set("unit", "把");
                set("base_unit", "根");
                set("base_weight", 150);
                set("base_value", 500);
                set("wound_percent", 95);
        }

        set_amount(1);
        init_throwing(400);
        setup();

        set("no_wield", "这不是用来装备的。\n");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
