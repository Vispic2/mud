// jia.c 静迦师太
// Modified by That Oct.1997

inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
#include "emei.h"
#include "tobebonze.h"

void create()
{
	set_name("静迦师太", ({ "jingjia shitai","jingjia","shitai"}));
	set("long", "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
	set("gender", "女性");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	set("str", 23);
	set("int", 25);
	set("con", 26);
	set("dex", 21);

	set("max_qi", 2900);
	set("max_jing", 1500);
	set("neili", 3100);
	set("max_neili", 3100);

	set("combat_exp", 375000);
	set_skill("persuading", 80);
	set_skill("throwing", 70);
	set_skill("force", 140);
	set_skill("dodge", 60);
	set_skill("finger", 60);
	set_skill("parry", 140);
	set_skill("strike", 130);
	set_skill("blade", 70);
	set_skill("literate", 60);
	set_skill("mahayana", 60);
	set_skill("jinding-zhang", 130);
	set_skill("tiangang-zhi", 60);
	set_skill("yanxing-dao", 70);
	set_skill("zhutian-bu", 70);
	set_skill("emei-xinfa", 140);
	set_skill("linji-zhuang", 140);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");

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

	if ((int)ob->query("shen") < 1000)
	{
		command("say " + RANK_D->query_respect(ob) +
			"你行侠仗义之事还做的不够。");
		return;
	}

	if ((int)ob->query_skill("mahayana",1) < 50)
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
