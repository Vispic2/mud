#include <ansi.h>
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
	set_name(HIY "点金盘龙弓" NOR, ({ "panlong gong", "gong", "bow" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("value", 100);
        set("long", HIY "这是一张金铜所铸，盘龙雕纹，制作非常精细的长弓。\n" NOR);
		set("power", 10000000);   // 攻击威力
		set("accuracy", 150);   // 准确度150%
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}
	setup();
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
