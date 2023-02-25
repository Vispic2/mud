#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
	set_name(MAG "纤云戒" NOR, ({"qianyun finger"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", HIY"这是一枚及其稀有的纤云戒。【轻功激发加50级】\n"NOR);
		set("material", "finger");
		set("no_sell",1);
//set("no_get",1);
        set("no_give",1);
        set("no_drop",1);  
        set("armor_prop/dodge", 50);  //类型
		set("armor_prop/armor", 50);  //防御
		set("armor_prop/warm", 100);   //保暖
		set("value", 100000);  
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
