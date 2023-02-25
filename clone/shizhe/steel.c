#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name(HIY"金镶九龙佩", ({"jinxiang steel"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "个");
		set("value", 2000);
		set("long", HIY"一枚及其稀有的金镶九龙玉佩。【内功 轻功 招架 拳法 拳脚 剑法各加10级】\n"NOR);
		set("material", "steel");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("armor_prop/unarmed", 10);
        set("armor_prop/force", 10);
        set("armor_prop/cuff", 10);
        set("armor_prop/sword", 10);
        set("armor_prop/parry", 10);
        set("armor_prop/dodge", 10);
        
		set("armor_prop/armor", 50);
		set("armor_prop/warm", 100);  
	}

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
