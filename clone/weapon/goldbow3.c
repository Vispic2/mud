// goldbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name(HIR "射"HIY"日"HIG"弓" NOR, ({ "sheri gong", "sheri", "gong", "bow" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "张");
                set("long", HIR "这是一张神弓，威力无穷，据说连天上的太阳都能射落。\n" NOR);
                //set("no_sell", "我的天…郡王府的东西你也敢拿来卖？");
		set("value", 200000);
                set("power", 250000);   // 攻击威力
                set("accuracy", 200);   // 准确度200%
        }
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
