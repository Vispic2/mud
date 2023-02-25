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
	set_name(HIW"随从经验丹"NOR, ({"exp dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 5000);
		set("base_value", 5000);	
		set("sc_exp",1);	
		set("yuanbao", 99);        
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);		
	    set("long","这是一个随从经验丹，可以为随从提升5000点经验值\n");	
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
