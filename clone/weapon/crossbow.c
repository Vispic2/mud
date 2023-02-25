// crossbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
	set_name("弩", ({ "cross bow", "bow", "nu" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("icon","05055");
		set("unit", "张");
		set("long", "一张弩，打造得极为精致，具有极好的准确度。\n");
		set("value", 250000);
		set("power", 250000);   // 攻击威力
		set("accuracy", 180);   // 准确度150%
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
