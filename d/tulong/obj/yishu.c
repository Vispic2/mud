// yishu.c

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void setup()
{
}

void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}
void create()
{
	set_name(CYN"武穆遗书"NOR, ({ "wumu yishu", "book", "yishu"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("material", "paper");
		set("no_sell", "这样东西不能卖。\n");
		set("long", "一本薄薄的绢帛，乃抗金大将岳飞灌注毕生心血所编撰而成。\n", );
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (! (arg == "wumu yishu" || arg == "book" || arg == "yishu"))
		return 0;

	if (! arg || ! id(arg))
		return notify_fail("你要读什么？\n");

	if (me->is_busy())
	{
		write("你现在正忙着呢。\n");
		return 1;
	}

	if (me->is_fighting())
	{
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}

	if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 1)
		return notify_fail("你的潜能不足。\n");

	message("vision", me->name() + "正专心地研读武穆遗书。\n",
		environment(me), me);
	if ((int)me->query("jing") < 200)
	{
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}

	if ((int)me->query("qi") < 80)
	{
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}

	pxlevel = me->query_skill("craft-cognize", 1);
	if ((int)me->query_skill("literate", 1) < 200)
	{
		write("你的学识不够精深，无法看懂武穆遗书中的内容。\n");
		return 1;
	}

	if (me->query_skill("craft-cognize", 1) > 199)
	{
		write("你发现对于武穆遗书上的兵法要诣已经了然于胸，完全掌握了。\n");
		return 1;
	}
	me->receive_damage("qi", 50 + random(30));
	me->receive_damage("jing", 100 + random(100));
	me->add("learned_points", 1);
	me->improve_skill("craft-cognize", 1 + random(me->query("int")/2));
	write("你仔细研读武穆遗书中兵法，颇有心得。\n");
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
