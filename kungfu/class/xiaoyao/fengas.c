// shilling 97.2

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "xiaoyao.h"

string ask_me();

void create()
{
	set_name("冯阿三", ({ "feng asan", "feng" }));
	set("long", 
		"据说他就是鲁班的后人，当代的第一巧匠，设计机关的能手。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("class", "alchemist");
	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);

	set("inquiry", ([
		"机关":(:ask_me:),
	]) );

	set("max_qi", 1500);
	set("max_jing", 700);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 30);
	set("combat_exp", 60000);
	set("score", 20000);

	set_skill("blade",50);
	set_skill("ruyi-dao",50);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("feiyan-zoubi", 50);
	set_skill("xiaoyao-xinfa",50);
	set_skill("liuyang-zhang", 50);

	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("force", "xiaoyao-xinfa");
	map_skill("blade", "ruyi-dao");

	prepare_skill("strike", "liuyang-zhang");

	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","巧匠");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}

string ask_me()
{
	object me,ob;
	ob = this_player(); 

	if (random(100)<70)
		return "我在设计机关方面是有点特长，让大家见笑了。";   
	command("laugh");
	return "别吵着我，我在看书呢。哈哈，芝麻开门。。。。这书真好笑\n";
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 26)
	{
		command("say 你那猪脑，还... 笑死我了。");
		return;
	}

	command("say 好吧，我就收下你了，多干活，少说话！");
	command("recruit " + ob->query("id"));
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
