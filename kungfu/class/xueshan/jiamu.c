// /kungfu/class/xueshan/jiamu.c  嘉木活佛
// by secret

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "xueshan.h"

void create()
{
	set_name("嘉木活佛", ({ "jiamu huofo", "huofo", "jiamu" }));
	set("long",@LONG
嘉木活佛是雪山寺有道的高僧，对佛法有精深的研究。
他身穿一件黄色袈裟，头带僧帽。目光如电，似乎身怀绝技。
LONG
	);
	set("title",HIY"活佛"NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1000); 
	set("max_jing", 2500); 
	set("neili", 2000); 
	set("max_neili", 2000); 
	set("jiali", 50); 
	set("combat_exp", 340000); 

	set_skill("lamaism", 120);
	set_skill("literate", 80);
	set_skill("force", 125);
	set_skill("mizong-neigong", 125);
	set_skill("dodge", 130);
	set_skill("shenkong-xing", 120);
	set_skill("cuff", 120);
	set_skill("yujiamu-quan", 100);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("mingwang-jian", 140);

	map_skill("force", "mizong-neigong");
	map_skill("dodge", "shenkong-xing");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "mingwang-jian");
	map_skill("sword", "mingwang-jian");

	prepare_skill("cuff", "yujiamu-quan");

	create_family("雪山寺", 3, "活佛");
	set("class", "bonze");

	setup();

	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();

	add_money("silver",20);
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;
 
	if ((string)ob->query("gender") != "男性")
	{
		command("say 修习密宗内功需要纯阳之体。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"还是请回吧！");
		return;
	}

	if ((string)ob->query("class") != "bonze")
	{
		command("say 我佛门的清规戒律甚多。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"还是请回吧！");
		return;
	}

	if ((string)ob->query("family/family_name") != "雪山寺")
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"既非本寺弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 60)
	{
		command("say 入我雪山寺，修习密宗心法是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"是否还应该多多钻研本门的心法？");
		return;
	}

	command("smile");
	command("nod");
	command("say 你就随我学习佛法吧！");
	command("recruit " + ob->query("id"));

	ob->set("title", HIY "大喇嘛" NOR);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
