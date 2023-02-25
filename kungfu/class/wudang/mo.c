#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("莫声谷", ({ "mo shenggu", "mo" }));
	set("nickname", "武当七侠");
	set("long", 
		"他就是张三丰的七弟子莫声谷。\n"
		"他看起来二十多岁，显得稚气未脱。\n"
		"但也是江湖中行侠仗义，声明远播的侠客。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 24);
	set("int", 27);
	set("con", 25);
	set("dex", 22);
	
	set("max_qi", 3600);
	set("max_jing", 1800);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 60);
	set("combat_exp", 850000);
	set("score", 300000);

	set_skill("force", 150);
	set_skill("wudang-xinfa", 150);
	set_skill("taiji-shengong", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 135);
	set_skill("taiji-quan", 135);
	set_skill("strike", 150);
	set_skill("zhenshan-zhang", 150);
	set_skill("hand", 100);
	set_skill("paiyun-shou", 100);
	set_skill("wudang-zhang", 125);
	set_skill("parry", 140);
	set_skill("sword", 130);
	set_skill("wudang-jian", 130);
	set_skill("taiji-jian", 130);
	set_skill("taoism", 70);
	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("strike", "zhenshan-zhang");
	map_skill("hand", "paiyun-shou");

	prepare_skill("unarmed", "taiji-quan");

	set("no_teach", ([
		"taiji-shengong" : "要想学习太极神功请向张真人请教。",
		"taiji-jian"     : "太极剑必须张真人亲传。",
		"taiji-quan"     : "太极拳必须张真人亲传。",
	]));

	create_family("武当派", 2, "弟子");

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query("shen") < 2000 )
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_skill("wudang-xinfa", 1) < 50)
	{
		command("say 我武当派最注重内功心法" + RANK_D->query_respect(ob)+
			"是否应该在武当心法上多下点功夫啊?");
		return;
	}

	if ((int)ob->query_skill("taoism", 1) < 50)
	{
		command("say 习武是为了强身健体，一味的练武是不可取的做！");
		command("say 我看你还需要在修身养性方面多锻炼锻炼，以提高你"
			"的道德心法。");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("say 希望你能好好用功，发扬我武当精神!");
	command("recruit " + ob->query("id"));
	if ((string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
