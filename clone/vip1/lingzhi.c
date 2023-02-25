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
		set_name(HIC"千年灵芝"NOR, ({"ling zhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("yuanbaos", 30);
              set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1);    
		set("unit", "株");
		
		set("base_value", 20000);
     	set("long","这是一株千年灵芝，服用灵芝能增加100点内力修为！注：每天只能服用一次。\n");
	    set("base_unit", "株");
		set("base_weight", 10);
	    set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      //	object me=this_player();
	object ob1;
      int times;
      mixed *local,*last;

      local = localtime(time() * 60);

//	if (arg!="ling zhi")
//      		return notify_fail("你要服用什么?\n");  

	if (me->query("day_item/lingzhi/last_time"))
		{
			last = localtime(me->query("day_item/lingzhi/last_time"));
			times = me->query("day_item/lingzhi/times");

			if(last[7]!=localtime(time())[7])
				me->set("day_item/lingzhi/times",0);
			else if(last[7]==localtime(time())[7]&&times>=1)
			{
                                //tell_object(me,me->query("name")+"今日已经使用过"+this_object()->query("name")+"了。\n");
                                message_vision(me->query("name")+"今日已经使用过"+this_object()->query("name")+"了。"NOR"\n",me);
				return 1;
			}
                 }

	me->set("day_item/lingzhi/last_time",time());
	me->add("day_item/lingzhi/times",1);

      me->add("zjvip/lingzhi_num",1);
	me->add("max_neili", 100);
      message_vision(YEL+me->query("name")+"服下一株"HIC"千年灵芝"YEL"，顿觉内力大增！"NOR"\n",me);

	add_amount(-1);
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
