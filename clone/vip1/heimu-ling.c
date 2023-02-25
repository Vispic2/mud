// heimu-ling.c 黑木令

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(BLK"黑木令"NOR, ({"heimu ling", "heimu", "ling"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "面");
		set("long","这是一块是块枯焦的黑色木头，长约半尺，上
面雕刻有花纹文字，看来十分诡异。\n");
        set("yuanbaos",1);
        set("value", 1);
         set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("material", "wood");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
