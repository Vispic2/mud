
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
	set_name(HIG "图纸残片" NOR, ({ "tuzhi"}) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "集齐一定数量可以兑换任何图纸。。\n");
		set("unit", "张");
		set("base_unit", "张");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 100);
            
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    me->add("tuzhi",1);	
	write("恭喜你获得了一张图纸碎片，可以前往扬州黑市，找NPC青阳子购买图纸。目前图纸碎片数量："+me->query("tuzhi")+"个！！！"NOR"\n");
    add_amount(-1);
     return 1;
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
