inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"白羽令"NOR, ({"baiyu ling"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);         
		set("unit", "块");
		set("no_sell", 1);
        set("no_drop",1);
set("no_get",1);
        set("no_give",1);
		set("long","这是一块白羽令，使用之后重新招募随从！\n");
		set("only_do_effect", 1);
	}
}


int do_effect(object me)
{

    if(me->query("scs") >= 1)
    {
    me->force_me("sc gone");
    me->set("scs",0);    
	write(YEL"你使用了一"+ query("unit") + name() +YEL"，可以重新招募随从了！"NOR"\n");
	me->save();
	destruct(this_object());
	}else	
	{	
	write("你连随从都没有你用这玩意干啥？\n");
	}
	return 1;
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
