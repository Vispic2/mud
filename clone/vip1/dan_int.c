
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
	set_name(HIY "醍醐仙丹" NOR, ({ "xian dan", "dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的仙丹，据说吃了可以增强智力。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbaos", 120);
          set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);

	if (me->query("gift/xiandan") >= 5)
	{
		message_vision("$N忽然“哇哇”，吐了一地。\n", me);
		tell_object(me, "你觉得嘴里非常的苦。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	      //me->add("gift/xiandan_fail", 1);
	} else
	{
		tell_object(me, HIG "一股火热蓦然从脑中升起，"
			    "你头痛欲裂，恰在此时一股清凉之意"
			    "油然而起，顿感舒泰无比。\n");
		me->add("int", 1);
	      me->add("gift/xiandan", 1);
	     write("\n "+HIR+"恭喜你："+NOR+HIG+"服用仙丹成功，《先天悟性》增加了！！！"NOR"\n");
	}

	add_amount(-1);
      return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
