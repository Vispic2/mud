// zhen.c 静真师太
// Modified By That Oct.1997

inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
#include "emei.h"
#include "tobebonze.h"

void create()
{
	set_name("静真师太", ({ "jingzhen shitai","jingzhen","shitai"}));
	set("long", "她是一位中年出家道姑，身穿道袍，正端坐在蒲团上，"
		    "眉目之间有一股祥和之气。\n");
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 22);
	set("int", 21);
	set("con", 23);
	set("dex", 20);

	set("max_qi", 2500);
	set("max_jing", 1200);
	set("neili", 2700);
	set("max_neili", 2700);

	set("combat_exp", 150000);
	set_skill("persuading", 80);
	set_skill("throwing", 90);
	set_skill("force", 100);
	set_skill("dodge", 70);
	set_skill("finger", 75);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 80);
	set_skill("literate", 70);
	set_skill("mahayana", 60);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 65);
	set_skill("huifeng-jian", 60);
	set_skill("zhutian-bu", 60);
	set_skill("emei-xinfa", 100);
	set_skill("linji-zhuang", 100);
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

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
