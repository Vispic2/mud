// liu.c 刘处玄
// By Lgg,1998.10

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("刘处玄", ({"liu chuxuan", "liu"}));
	set("gender", "男性");
	set("age", 38);
	set("class", "taoist");
	set("nickname",WHT"长生子"NOR);
	set("long",
		"他就是全真三徒刘处玄刘真人，他身材瘦小，但顾盼间自有一\n"
		"种威严气概。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 30);
	set("con", 28);
	set("dex", 30);

	set("title","全真七子之三");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("qi", 4400);
	set("max_qi", 4400);
	set("jing", 2200);
	set("max_jing", 2200);
	set("neili", 4600);
	set("max_neili", 4600);
	set("jiali", 100);

	set("combat_exp", 850000);

	set_skill("force", 160);
	set_skill("quanzhen-xinfa", 160);
	set_skill("sword", 160);
	set_skill("quanzhen-jian",160);
	set_skill("dodge", 140);
	set_skill("jinyan-gong", 140);
	set_skill("parry", 150);
	set_skill("finger",150);
	set_skill("zhongnan-zhi", 150);
	set_skill("literate", 100);
	set_skill("strike", 150);
	set_skill("chongyang-shenzhang", 150);
	set_skill("haotian-zhang", 150);
	set_skill("finger",150);
	set_skill("taoism",120);

	map_skill("force", "quanzhen-xinfa");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger", "zhongnan-zhi");
	map_skill("strike", "haotian-zhang");
	prepare_skill("finger", "zhongnan-zhi");
	prepare_skill("strike","haotian-zhang");

	create_family("全真教", 2, "弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("quanzhen-xinfa", 1) < 70)
	{
		command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 6000)
	{
		command("say 多做一些行侠仗义的事情再说吧！。\n");
		return;
	}
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
