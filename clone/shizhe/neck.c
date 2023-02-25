// zhenwu_neck.c

#include <ansi.h>
#include <armor.h>

inherit NECK;
void create()
{
	set_name(HIR "定魂链" NOR, ({"dinghun neck"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", HIY"这是一条及其稀有的定魂项链。【剑法 拳脚 拳法各激发加20级】\n"NOR);
		set("material", "neck"); 
		set("no_sell",1);
        set("no_give",1);
//set("no_get",1);
        set("no_drop",1);   //类型
		set("armor_prop/armor", 50);  //防御
		set("armor_prop/warm", 100); 
		set("armor_prop/sword", 20);
		set("armor_prop/cuff", 20); 
		set("armor_prop/unarmed", 20); //保暖
	    set("value", 100000);   //价值		        
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
