// xianglong.c

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>

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
	set_name(CYN "降龙十八掌秘笈" NOR, ({ "xianglong miji", "book", "miji"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("material", "paper");
		set("no_sell", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("long",
	"乃大侠郭靖所编写，记载了丐帮的绝学降龙十八掌。\n"
	"为武林至高无上的武学。\n", );
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (! (arg == "xianglong miji" || arg == "book" || arg == "miji"))
		return 0;

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

	if (! id(arg))
	{
		write("你要读什么？\n");
		return 1;
	}

	if ((int)me->query("str") < 31)
		return notify_fail("就你这身子骨还练降龙十八掌？小心弄折了胳膊。\n");

	if ((int)me->query("con") < 24)
		return notify_fail("算了吧，你先天根骨不好，别强学了。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法学习降龙十八掌。\n");

	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力这么差，怎能融会贯通降龙十八掌？\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("你的基本掌法火候不够，无法学习降龙十八掌。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dragon-strike", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n");

	if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("你的潜能不足。\n");

	message("vision", me->name() + "正专心地研读降龙十八掌秘笈。\n", environment(me), me);

	if ((int)me->query("neili") < 100)
	{
		write("你现在内力不足，无法专心下来研读新知。\n");
		return 1;
	}

	if ((int)me->query("jing") < 100)
	{
		write("你现在过于疲倦，无法专心下来研读新知。\n");
	      me->force_me("exert regenerate");
		return 1;
	}

	if ((int)me->query("qi") < 100)
	{
		write("你现在过于疲倦，无法专心下来研读新知。\n");
       	me->force_me("exert recover");
		return 1;
	}

	pxlevel = me->query_skill("dragon-strike", 1);

	if ((int)me->query("combat_exp") < 100000)
	{
		write("你的实战经验不足，无法看懂降龙十八掌秘笈中的内容。\n");
		return 1;
	}

	if (! me->can_improve_skill("dragon-strike"))
	{
		write("你的实战经验不足，无法看懂降龙十八掌秘笈中的内容。\n");
		return 1;
	}

	if (me->query_skill("dragon-strike", 1) > 199)
	{
		write("你研读了一会儿，但是发现秘笈中的内容对"
		      "你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}
/*
	if (me->query_skill("dragon-strike", 1) < 80)
	{
		write("你研读了一会儿，但是发现秘笈中的内容深"
		      "奥无比，没有学到任何东西。\n");
		return 1;
	}
*/
	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->add("learned_points", 10);
	me->improve_skill("dragon-strike", (1 + random(me->query("str")))*10);
	write("你仔细研读降龙十八掌秘笈，颇有心得。\n");
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
