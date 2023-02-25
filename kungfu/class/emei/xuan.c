// xuan.c 静玄师太
//Modified by That Oct.1997

#include <command.h>
#include <ansi.h>
#include "tobebonze.h"
#include "emei.h"

inherit NPC;
inherit F_MASTER;
string ask_for_join();

void create()
{
	set_name("静玄师太", ({ "jingxuan shitai","jingxuan","shitai"}));
	set("long", "她是峨嵋派大师姐，跟随灭绝师太二十余载，"
		    "峨嵋派的功夫已尽得所传。\n");
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	set("str", 24);
	set("int", 27);
	set("con", 25);
	set("dex", 22);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 4100);
	set("max_neili", 4100);

	set("combat_exp", 750000);
	set_skill("persuading", 100);
	set_skill("throwing", 120);
	set_skill("force", 165);
	set_skill("dodge", 140);
	set_skill("finger", 150);
	set_skill("parry", 160);
	set_skill("strike", 120);
	set_skill("sword", 160);
	set_skill("literate", 100);
	set_skill("mahayana", 140);
	set_skill("jinding-zhang", 150);
	set_skill("tiangang-zhi", 120);
	set_skill("huifeng-jian", 160);
	set_skill("zhutian-bu", 140);
	set_skill("emei-xinfa", 165);
	set_skill("linji-zhuang", 165);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");

	create_family("峨嵋派", 4, "弟子");

	set("no_teach", ([
		"linji-zhuang" : "想学临济十二庄？找灭绝师太去。",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query("shen") < 5000)
	{
		command("say " + RANK_D->query_respect(ob) +
			"你行侠仗义之事还做的不够。");
		return;
	}

	if ((int)ob->query_skill("mahayana",1) < 80)
	{
		command("say 你大乘佛法的修为还要提高些。");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
