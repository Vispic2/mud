// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(CYN"海参"NOR, ({"yu7"}));
    set_weight(30000);
    set("long", "一个很大的海参！\n");
        set( "unit", "条" );

		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

        set( "value", 700 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
