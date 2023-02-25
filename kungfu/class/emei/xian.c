// xian.c 静闲师太
// Modified By That Oct.1997

inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
#include "emei.h"
#include "tobebonze.h"

void create()
{
	set_name("静闲师太", ({ "jingxian shitai","jingxian","shitai"}));
	set("long", "她是一位中年出家道姑，身穿道袍，正端坐"
		    "在蒲团上，眉目之间有一股祥和之气。\n");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 19);
	set("int", 22);
	set("con", 20);
	set("dex", 24);

	set("max_qi", 1800);
	set("max_jing", 900);
	set("neili", 2100);
	set("max_neili", 2100);

	set("combat_exp", 120000);
	set_skill("persuading", 80);
	set_skill("throwing", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("finger", 60);
	set_skill("parry", 70);
	set_skill("strike", 65);
	set_skill("blade", 60);
	set_skill("mahayana", 60);
	set_skill("literate", 60);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 60);
	set_skill("yanxing-dao", 60);
	set_skill("zhutian-bu", 70);
	set_skill("emei-xinfa", 70);
	set_skill("linji-zhuang", 100);
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

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	setup();
	carry_object("/d/city/obj/gangdao")->wield();
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
