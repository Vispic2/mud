// energy stone.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "宠物能量石" NOR, ({"energy stone", "stone"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "一块精光闪闪的能量石。"NOR"\n");
		set("unit", "块");
		set("value", 100000);
		set("weight", 50);
		set("icon","06006");
		set("only_do_effect", 1);
		set("suit_point",10);  //一个兑换点
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (! me->is_magic_beast())
	{
		write("你疯了啊，能量石也能吃吗？\n");
		return 1;
	}

	me->set("food", 10*me->max_food_capacity());
	me->set("water",10*me->max_water_capacity());
	// me->start_busy(1);
	message_vision(HIR "$N" HIR "吞下了一块能量石，顿时全身泛起红光,不由的打了个饱嗝！！！"NOR"\n",me);

	destruct(this_object());

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
