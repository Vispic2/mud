
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
	set_name(HIG"新手装备"NOR, ({"xinshou zuangbei"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "打开即可获得新手装备。\n");
		set("unit", "个");
		set("base_unit", "个");
//set("no_get",1);
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10);
       // set("no_put", 1);
        //set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
       // set("no_steal", 1);
        //set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int bo6,bo7,bo8,bo9,bo10;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
    bo6 = new("/clone/suit/new/new1");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    bo6 = new("/clone/suit/new/new2");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    bo6 = new("/clone/suit/new/new3");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    bo6 = new("/clone/suit/new/new4");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    bo6 = new("/clone/suit/new/new5");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    
	
	
	
	
	
    bo6 = new("/clone/suit/new/new6");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	bo7 = new("/clone/suit/new/new7");
	write(YEL"恭喜您：获得了"+bo7->short()+"。"NOR"\n");
	bo7->move(me);
	bo8 = new("/clone/suit/new/new8");
	write(YEL"恭喜您：获得了"+bo8->short()+"。"NOR"\n");
	bo8->move(me);
	bo9 = new("/clone/suit/new/new9");
	write(YEL"恭喜您：获得了"+bo9->short()+"。"NOR"\n");
	bo9->move(me);
	bo10 = new("/clone/suit/new/new10");
	write(YEL"恭喜您：获得了"+bo10->short()+"。"NOR"\n");
	bo10->move(me);


    bo6 = new("/clone/suit/new/new11");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	    bo6 = new("/clone/suit/new/new12");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	
	    bo6 = new("/clone/suit/new/new13");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	/*
	    bo6 = new("/clone/suit/new/new14");
	write(YEL"恭喜您：获得了"+bo6->short()+"。"NOR"\n");
	bo6->move(me);
	*/



	add_amount(-1);
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
