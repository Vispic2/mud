// shen.c 申志凡
// By Lgg,1998.10

#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("申志凡", ({"shen zhifan", "shen"}));
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long",
		"他就是全真教第三代弟子中的好手，郝大通的弟子。\n");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("int", 25);
	set("con", 25);
	set("dex", 26);

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
	set_skill("quanzhen-jian",70);
	set_skill("dodge", 70);
	set_skill("jinyan-gong", 70);
	set_skill("parry", 80);
	set_skill("finger",80);
	set_skill("unarmed",80);
	set_skill("zhongnan-zhi", 70);
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
