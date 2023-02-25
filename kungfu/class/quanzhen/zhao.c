// zhao.c 赵志敬
// By Lgg,1998.10

#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("赵志敬", ({"zhao zhijing", "zhao"}));
	set("gender", "男性");
	set("age", 26);
	set("class", "taoist");
	set("long",
		"他就是全真教第三代弟子中的好手，王处一的大弟子赵志敬。 \n"
		"他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
		"他是一个长须道人，看起来却有些煞气。\n");
	set("attitude", "friendly");
	set("shen_type",-1);
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 25);

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

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);

	set("combat_exp", 160000);

	set_skill("force", 80);
	set_skill("quanzhen-xinfa", 80);
	set_skill("sword", 80);
	set_skill("quanzhen-jian",80);
	set_skill("dodge", 70);
	set_skill("jinyan-gong", 70);
	set_skill("parry", 80);
	set_skill("unarmed",80);
	set_skill("finger",80);
	set_skill("zhongnan-zhi", 80);
	set_skill("literate",60);
	set_skill("taoism",60);

	map_skill("force", "quanzhen-xinfa");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger", "zhongnan-zhi");
	prepare_skill("finger", "zhongnan-zhi");

	create_family("全真教", 3, "弟子");

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

	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
