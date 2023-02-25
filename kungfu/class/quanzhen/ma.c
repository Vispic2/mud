// ma.c 马钰
// By Lgg,1998.10

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_me();

void create()
{
	set_name("马钰", ({"ma yu", "ma"}));
	set("gender", "男性");
	set("age", 42);
	set("class", "taoist");
	set("nickname",MAG"丹阳子"NOR);
	set("long",
		"他就是王重阳的大弟子，全真七子之首，丹阳子马钰马真人。\n"
		"他慈眉善目，和蔼可亲，正笑着看着你。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 28);
	set("int", 32);
	set("con", 31);
	set("dex", 30);

	set("title","全真七子之首");

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

	set("qi", 4500);
	set("max_qi", 4500);
	set("jing", 2200);
	set("max_jing", 2200);
	set("neili", 4700);
	set("max_neili", 4700);
	set("jiali", 100);

	set("combat_exp", 1400000);

	set_skill("force", 180);
	set_skill("quanzhen-xinfa", 180);
	set_skill("sword", 170);
	set_skill("quanzhen-jian",170);
	set_skill("dodge", 180);
	set_skill("jinyan-gong", 180);
	set_skill("parry", 180);
	set_skill("literate",100);
	set_skill("strike", 180);
	set_skill("chongyang-shenzhang", 180);
	set_skill("haotian-zhang", 180);
	set_skill("finger",180);
	set_skill("zhongnan-zhi", 180);
	set_skill("taoism",150);
	set_skill("medical", 210);
	set_skill("liandan-shu", 210);

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
		"金雁功" : (: ask_me :),
		"金雁图谱" : (: ask_me :),
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("quanzhen-xinfa", 1) < 100)
	{
		command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 10000)
	{
		command("say 行侠仗义我辈学武人需铭记在心，这点你做的可不够啊！\n");
		return;
	}
	command("pat " + ob->query("id"));
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +
		"与本教毫无瓜葛，我教的武功典籍可不能交给你。";
	if (query("book_count") < 1)
		return "你来晚了，金雁图谱已经被人取走了。";
	add("book_count", -1);
	ob = new("/clone/book/jinyantu");
	ob->move(this_player());
	return "好吧，这本「金雁图谱」你拿回去好好研读。";

}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
