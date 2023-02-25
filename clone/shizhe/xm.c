
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
	set_name(HIG "心魔战利品" NOR, ({ "xm"}) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "使用后可以突破合体镜。。\n");
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
    me->set("xm",10);	
	write("恭喜你挑战心魔成功。。"NOR"\n");
    add_amount(-1);
     return 1;
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
