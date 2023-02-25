// afeecard.c 高级免费卡
//
// 使用免费卡建房不需要花费任何银两

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "免费卡" NOR, ({ "card", "fee free card" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("material", "paper");
		set("fee free", 10000000);
		set("value", 1);
		set("no_sell", 1);
	}
}

string long()
{
	string msg;

	msg = "这是一张高级住房免费卡，凭这张卡可以免费购买一套价格";
	msg += MONEY_D->price_str(query("fee free"));
	msg += "以下的住房一套。\n";
	return msg;
}

int query_autoload() { return 1; }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
