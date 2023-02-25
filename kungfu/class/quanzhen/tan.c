// tan.c 谭处端
// By Lgg,1998.10

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("谭处端", ({"tan chuduan", "tan"}));
	set("gender", "男性");
	set("age", 40);
	set("class", "taoist");
	set("nickname",HIY"长真子"NOR);
	set("long",
		"他就是全真次徒谭处端谭真人，他身材魁梧，浓眉大眼，嗓音\n"
		"洪亮，拜重阳真人为师前本是铁匠出身。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 34);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("title","全真七子之二");
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

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 4200);
	set("max_neili", 4200);
	set("jiali", 100);

	set("combat_exp", 1200000);

	set_skill("force", 150);
	set_skill("quanzhen-xinfa", 160);
	set_skill("sword", 150);
	set_skill("quanzhen-jian",160);
	set_skill("dodge", 140);
	set_skill("jinyan-gong", 140);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("chongyang-shenzhang", 150);
	set_skill("haotian-zhang", 150);
	set_skill("literate",80);
	set_skill("finger",140);
	set_skill("zhongnan-zhi", 140);
	set_skill("taoism",100);

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

	if ((int)ob->query_skill("quanzhen-xinfa", 1) < 80)
	{
		command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 8000)
	{
		command("say 我看你还是多做一些侠义之事吧。\n");
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
