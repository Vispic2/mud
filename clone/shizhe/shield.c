#include <ansi.h>
#include <armor.h>
inherit SHIELD;
void create()
{
	set_name(MAG "飞星盾" NOR, ({"feixing shield"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "面");
		set("long", HIY"这是一面及其稀有的飞星盾。【招架 内功各激发加20级】/\n"NOR);
		set("material", "shield");  
		set("no_sell",1);
        set("no_give",1);
//set("no_get",1);
        set("no_drop",1);  //类型
		set("armor_prop/armor", 80);  //防御
		set("armor_prop/warm", 100);
		set("armor_prop/parry", 20); 
		set("armor_prop/force", 20);  //保暖
		set("value", 1000);
		
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
