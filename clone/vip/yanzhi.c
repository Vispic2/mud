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
	set_name(HIM"胭脂"NOR, ({"yan zhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 100);         
		set("unit", "份");
		set("long","这是一份胭脂，使用之后可以提升人物容貌！\n");			
		set("base_unit", "份");
		set("base_weight", 10);
	    set("only_do_effect", 1);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}
	setup();
}

int do_effect(object me)
{
      if (me->query("per")>49) return notify_fail("你的容貌已经极美了。\n");

	me->add("per",1+random(3));

      if (me->query("per")>50) me->set("per",50);

	write(YEL"你使用了一"+ query("unit") + name() +YEL"，你的容貌增加了！"NOR"\n你现在的容貌是："+me->query("per")+"。"NOR"\n");
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"使用了一"+ query("unit") + name() +HIM"，变得更加漂亮了！");
	me->save();
	add_amount(-1);
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
