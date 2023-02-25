// bei.c 贝锦仪

#include "emei.h"

inherit NPC;
inherit F_MASTER;
int ask_for_ji();

void create()
{
	set_name("贝锦仪", ({ "bei jinyi", "bei", "jinyi"}));
	set("long", "她是峨嵋派的第四代俗家弟子。\n");
	set("gender", "女性");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);

	set("str", 21);
	set("int", 25);
	set("con", 24);
	set("dex", 20);

	set("max_qi", 2100);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("inquiry",([
		"纪晓芙"  : (: ask_for_ji :),
	]));

	set("combat_exp", 250000);
	set_skill("throwing", 30);
	set_skill("persuading", 50);
	set_skill("force", 130);
	set_skill("dodge", 90);
	set_skill("finger", 85);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 130);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 85);
	set_skill("huifeng-jian", 130);
	set_skill("zhutian-bu", 90);
	set_skill("emei-xinfa", 130);
	map_skill("force","emei-xinfa");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

int ask_for_ji()
{
	object ob;
	ob = this_player();
	tell_object(ob,"贝锦仪说道：纪晓芙在舍身崖呢。她就是想不开。嗨！\n"); 
	ob->set("marks/ji",1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
