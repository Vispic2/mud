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
	    set_name(HIC"天"HIY"眼"NOR, ({"tian yan"}));
		if( clonep() )
		set_default_object(__FILE__);
	    else {
		set("value", 1);
		set("yuanbao", 1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 1);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	    set("long","这是挖宝利器，可以判断当前位置是否有宝藏！\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
int i;
object where=environment(me);
i=mapp(where->query("wabao_props"));
if(i){
write(HIY"恭喜你这里有宝藏，快点挖吧！"NOR"\n");
}else{
write(HIR"很遗憾这里没有宝藏！"NOR"\n");
}
add_amount(-1);
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
