
#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIC "卧龙令" NOR, ({ "wolong ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIB"这是一枚式样古朴的卧龙令，上面刻着一幅地图，像是北京朝阳门外的一座庄园，不知是什么用意。\n"NOR);
		set("base_unit", "块");
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("base_value", 500000);
//set("no_get",1);
		set("yuanbao", 2000);
		set("base_weight", 1);
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
