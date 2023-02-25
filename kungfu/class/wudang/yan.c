// yan.c 俞岱岩

#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("俞岱岩", ({ "yu daiyan", "yu" }));  
	set("nickname","武当三侠");
	set("long", 
		"他就是张三丰的三弟子俞岱岩。\n"
		"身穿一件干干净净的灰色道袍。\n"
		"他已年过四十，身材瘦长。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age",43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 29);
	set("int", 28);
	set("con", 31);
	set("dex", 25);
	
	set("max_qi", 4400);
	set("max_jing", 2000);
	set("neili", 5200);
	set("max_neili", 5200);
	set("jiali", 100);
	set("combat_exp", 1450000);
	set("score", 45000);

	set_skill("force", 190);
	set_skill("wudang-xinfa", 190);
	set_skill("taiji-shengong", 190);
	set_skill("dodge", 165);
	set_skill("tiyunzong", 165);
	set_skill("unarmed", 170);
	set_skill("taiji-quan", 170);
	set_skill("strike", 170);
	set_skill("wudang-zhang", 170);
	set_skill("hand", 170);
	set_skill("paiyun-shou", 170);
	set_skill("parry", 175);
	set_skill("sword", 180);
	set_skill("wudang-jian", 180);
	set_skill("taiji-jian", 180);
  	set_skill("taoism", 160);
	set_skill("literate", 100);

	set("no_teach", ([
		"taiji-shengong" : "要想学习太极神功请向张真人请教。",
		"taiji-jian"     : "太极剑必须张真人亲传。",
		"taiji-quan"     : "太极拳必须张真人亲传。",
	]));

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("strike", "wudang-zhang");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("武当派", 2, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
}

void greeting(object ob)
{
	int i;

	if (! objectp(ob) || environment(ob) != environment())
		return;

	if ((int)ob->query_skill("wudang-xinfa", 1) == 0)
	{
		message_vision(CYN "十三弟子对$N" CYN "齐声喝道：你这"
			       "个邪魔外道，敢来真武剑阵？"NOR"\n", ob);
		ob->set("qi", 30);

		if ((int)ob->query("combat_exp") < 2000)
			ob->set("combat_exp", 1);
		else    ob->add("combat_exp", -1000);

		message_vision(CYN "真武剑阵顿时启动，高台上剑气纵横，把$N" CYN "围在中央。"NOR"\n", ob);
		message_vision(CYN "十三口长剑齐出，在$N" CYN "身上划出了十三道口子，鲜血淋漓。"NOR"\n", ob);
		say(CYN "\n\n俞岱岩脸现怒容：“邪魔外道，也敢闯真武剑阵！”\n");
		message_vision("俞岱岩居高临下，起手一掌把$N劈落高台。\n"NOR"\n", ob);
		ob->move("/d/wudang/nanyangong");
		CHANNEL_D->do_channel(this_object(), "chat",
				      sprintf("%s私闯真武剑阵，念其"
					      "成长不易，暂免一死！", ob->name(1)));
	}
}

void attempt_apprentice(object me)
{
	if (! permit_recruit(me))
		return;

	if ((int)me->query_skill("wudang-xinfa", 1) < 30)
	{
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(me) +
			"是否还应该在太极神功上多下点功夫？");
		return;
	}

	if ((int)me->query("shen") < 10000)
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(me) +
			"是否还做得不够？");
		return;
	}

	if ((int)me->query_skill("wudang-xinfa", 1) < 70)
	{
		command("say 我武当派最注重内功心法" + RANK_D->query_respect(me)+
			"是否应该在武当心法上多下点功夫啊?");
		return;
	}

	if ((int)me->query_skill("taoism", 1) < 70)
	{
		command("say 习武是为了强身健体，一味的练武是不可取的！");
		command("say 我看你还需要在修身养性方面多锻炼锻炼，以提"
			"高你的道德心法。");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + me->query("id"));
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
