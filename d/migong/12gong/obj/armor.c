#include <ansi.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit ARMOR;

void create()
{
        set_name(HIC"圣羽战甲"NOR, ({"shengyu armor","zhanjia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件用万年天蚕丝穿连灵山翠玉制作而成的护甲。\n");
		set("no_sell", 1);
                set("no_drop", 1);
		set("no_put", 1);		
                set("material", "crimsonsteel");
                set("value", 1000);
                set("armor_prop/armor", 150);
		set("armor_prop/dodge", -5);
        }
        setup();
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
