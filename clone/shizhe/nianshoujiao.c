// butian.c 补天石

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "年兽角" NOR, ({"nianshou jiao", "nianshou", "jiao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",HIY"这是个年兽击杀掉落角，可以找专人兑换炮竹去扬州广场炸年兽王获得奖励。\n"NOR);
		set("unit", "个");
		set("value", 100000);
		set("nianshoujiao",1);
	}
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
