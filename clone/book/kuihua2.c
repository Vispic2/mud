inherit ITEM;

#include <ansi.h>; 

void setup()
{}

void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}

void create()
{
	set_name(HIW "《葵花神功》" NOR, ({ "kuihua shengong", "baodian2", "book2", "kuihua2"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", HIR "这就是武林第一秘籍《葵花神功》，相传是一位宫中太监所作的手抄真迹，你可以"
				ZJURL("cmds:study kuihua shengong")+ZJSIZE(22)+"研读"NOR+HIR"看看。"NOR"\n");
		set("value", 1);
		set("material", "paper");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_give", 1);
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob, obj;
	mapping skill;
	int plvl, con, improve;
	int neili_lost;

	if (! arg || ! id(arg))
		return 0;

	if (me->is_busy())
	{
		write("你现在正忙着呢。\n");
        return 1;
	}

	if (!(me->query("family/family_name") == "日月神教"))
	{
	
		write("你不是我们日月神教的不能读此书！\n");
		return 1;
	}
	
	if (me->is_fighting())
	{
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}

	if (where->query("no_fight"))
	{
		write("你无法在这里静下心来研读宝典。\n");
		return 1;
	}

	if ((string)me->query("gender") == "女性")
	{
		write("自古没有听说女人可以读《葵花宝典2》的。\n");
		return 1;
	}

	if ((string)me->query("gender") == "男性")
	{
	       write("《葵花宝典2》的第一页写着：欲练神功，必先自宫。\n");
	       return 1;
	}

	if (me->query_skill("pixie-jian", 1))
	{
		write("你不散掉辟邪剑法没办法研读这本书。\n");
		return 1;
	}
	if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
	if (me->query_skill("kuihua-shengong", 1) >= 180)
	{
		write("这本书你已经研究得差不多了，没什么好读的了。\n");
		return 1;
	}

	if ((int)me->query("combat_exp") < 200000)
	{
			write("你的实战经验不足，再怎么读也没用。\n");
			return 1;
	}

	if ((int)me->query("max_neili") < 500)
	{
			write("你的最大内力太低，无法修炼此等神功。\n");
			return 1;
	}

	if (me->query_skill("xixing-dafa", 1) > 1 || me->query_skill("tianmo-jian", 1) > 1) {
		tell_object(me, "你已经学会吸星大法或是天魔剑法，这本书已经完全看不懂了。\n");
		return 1;
	}
	if (me->query("family/master_id") == "ren woxing") {
		tell_object(me, "你师傅任我行最讨厌的就是东方老贼，学这种武功不太合适吧？\n");
		return 1;
	}
	
	switch (random(3))
	{
		case 0:
			message("vision", me->name() + "偷偷摸摸翻出"
				"一本葵花宝典2在读。\n", environment(me), me);
			break;
		case 1:
			message("vision", me->name() + "边读书边骚首"
				"弄姿，模仿女人简直惟妙惟肖。\n", environment(me), me);
			break;
		case 2:
			message("vision", me->name() + "边读书边把腰"
				"肢扭来扭去，看得你心头荡漾不已。\n", environment(me), me);
			break;
	}

	if ((int)me->query("jing") < 60)
	{
		if (  present("huxin dan", obj) )
		{
			tell_object(me, ZJFORCECMD("use huxin dan"));
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);

			return 1;
		} else {
			write("你现在过于疲倦，等待恢复中...\n");
			remove_call_out("do_lian3");
			call_out("do_lian3", 20, me);

			return 1;
		}
	}

	plvl = me->query_skill("kuihua-shengong", 1);
	if (plvl > 165) neili_lost = 100; else
	if (plvl > 150) neili_lost = 60;  else
	if (plvl > 120) neili_lost = 40;  else
	if (plvl > 100) neili_lost = 30;  else
	if (plvl > 50)  neili_lost = 20;
		   else neili_lost = 10;

	con = me->query_con();

	if ((int)me->query("neili") < 200  || me->query("jing") < 120)
	{
		if (  present("huxin dan", obj) )
		{
			tell_object(me, ZJFORCECMD("use huxin dan"));
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);

			return 1;
		} else {
			write("你状态不佳，等待恢复中...\n");
			remove_call_out("do_lian3");
			call_out("do_lian3", 20, me);
			return 1;
		}
	}

	if (! me->can_improve_skill("kuihua-shengong", 1))
	{
		write("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	}

	if ((plvl > 10) && (con / 2 + random(con) < 50) && random(80) == 1)
	{
		// 鬼脉之人读《葵花宝典2》不容易走火
		if (me->query("special_skill/ghost") && random(3))
		{
			tell_object(me, HIR "你依照着宝典所示运转内息，突"
					"然内息逆流而上，却不觉得有任何不"
					"妥。"NOR"\n");
		}
		else
		{		
			tell_object(me, HIR "你依照着宝典所示运转内息，突"
					"然只觉内息逆流而上，四肢冰凉，心火如\n"
					"焚，惨嚎一声，晕了过去。"NOR"\n");
			message("vision", HIR + me->name() + "突然惨"
					  "嚎一声，差点晕了过去。"NOR"\n",
				environment(me), ({ me }));
	
			if ((int)me->query("max_neili") > 10)
			{
				me->add("max_neili", -10 - random(10));
			}
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);
			//me->unconcious();
			return 1;
		}
	}

	me->receive_damage("jing", 20);
	me->add("neili", -neili_lost);
	me->improve_skill("kuihua-shengong", 12 + random(30));
	
	// 鬼脉之人学习葵花神功更快
	if (me->query("special_skill/ghost"))
	{
		me->improve_skill("kuihua-shengong", 2 + random(10));
	}

//	me->start_busy(random(1) + 1);
	write("你研读《葵花宝典2》，颇有心得。\n");
	remove_call_out("do_lian3");
	call_out("do_lian3", 2, me);
	return 1;
}

void do_lian3(object me)
{
	if (! objectp(me))
		return;

	tell_object(me,ZJFORCECMD("du kuihua shengong"));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
