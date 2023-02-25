
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
	set_name(HIG"LPC"NOR, ({"xue"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "巫师用来学习基础LPC的书\n");
		set("unit", "个");
		set("base_unit", "个");
		set("only_do_effect", 1);
	set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10);
	}
	setup();
}

int do_effect(object me)
{
    int s;
    s=1+random(10);
    write("结果："+s+"\n");
    
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
