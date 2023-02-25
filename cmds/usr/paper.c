// bao.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR +"小纸条" NOR, ({ "paper" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "上面什么也没写。\n");
                set("value", 1);
				set("unit", "张");
                
	}
        setup();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
