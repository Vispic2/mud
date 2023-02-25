
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
	"force",
	"dodge",
	"unarmed",
	"cuff",
	"sword",
	"parry",
});

void create()
{
	set_name(HIG"新人礼包"NOR, ({"kaihuang libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIG"新人礼包，新人初期快速起步使用！\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4,num5,num6,num7,a,b,c,d,e,f,g,h,xxzb,fei,xue;
	object d1,d2,d3,d4,d5,gong,bagua,jian;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	num1=1000000;
	me->add("combat_exp",num1);
	num2=1888888;
	me->add("potential",num2);
	num3=18888;
	me->add("score",num3);
	num4=18888;
	me->add("weiwang",num4);
	num6=18888;
	me->add("gongxian",num6);
	num7=18888;
	me->add("magic_points",num7);	
	me->set("zjvip/times",86400*365);
    num5=20000;
    me->add("yuanbaos",num5);
    num6=188;
    me->add("yuanbao",num5);
	me->set("scoresss",1);
	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：获得了"+num1+"点经验。"NOR"\n");
	write(YEL"恭喜您：获得了"+num2+"点潜能。"NOR"\n");
	write(YEL"恭喜您：获得了"+num3+"点阅历。"NOR"\n");
	write(YEL"恭喜您：获得了"+num4+"点威望。"NOR"\n");
	write(YEL"恭喜您：获得了"+num6+"点贡献。"NOR"\n");
	write(YEL"恭喜您：获得了"+num7+"点灵慧。"NOR"\n");
	write(YEL"恭喜您：获得了"+num5+"个元宝票。"NOR"\n");
	write(YEL"恭喜您：获得了"+num6+"个元宝。"NOR"\n");
    write(YEL"恭喜您：获得了三百六十五天"HIR"会员时长。"NOR"\n");	
	gong = new("/clone/shizhe/gong");
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	gong = new("/clone/vip/canghai");
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	xxzb = new("/clone/shizhe/xxzb");
	write(YEL"恭喜您：获得了"+xxzb->short()+"。"NOR"\n");
	xxzb->move(me);
	jian = new("/clone/shizhe/arrow");
	jian->set_amount(100);
	write(YEL"恭喜您：获得了"+jian->short()+"。"NOR"\n");
	jian->move(me);
	d1 = new("/clone/money/gold");
	d1->set_amount(1);
	write(YEL"恭喜您：获得了"+d1->short()+"。"NOR"\n");
	// hutu=new("/clone/shizhe/dan_hutu") 
	// hutu->set_amount(1);
	d1->move(me);		
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
