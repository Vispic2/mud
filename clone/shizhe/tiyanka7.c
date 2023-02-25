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
	set_name(HIW"自动师门七体验卡"NOR, ({"shimen tyk"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 10);        
		set("unit", "张");		
		set("base_unit", "张");
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","这是一张师门七体验卡，使用后可以使用zdsm七天。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{

    int times=time();
    int a;
    a=86400*7;
	me->set("zdsmsss",times+a);

	write(YEL"使用自动师门体验卡成功，指令zdsm即可使用！"NOR"\n");
	add_amount(-1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
