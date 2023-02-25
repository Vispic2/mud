
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

string *types = ({
	"literate",
	
});

void create()
{
	set_name(HIG"开服礼包"NOR, ({"kai libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIG"内含300级读书写字，太玄勿用！\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
//set("no_get",1);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4,num5,a,b,c,d,e,f,g,h,xxzb,fei,xue;
	object d1,d2,d3,d4,d5,gong,bagua,jian;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");


	for(i=0;i<sizeof(types);i++)
	{
		if(me->query_skill(types[i],1)<300)
		{
			me->set_skill(types[i],300);
			tell_object(me,"你学会了了300级"+to_chinese(types[i])+"。\n");
		}
	}

	add_amount(-1);
	me->save();

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
