// /kungfu/class/xueshan/gelunbu.c  葛伦布
// by secret

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "xueshan.h"

void create()
{
	set_name("葛伦布", ({ "ge lunbu", "ge" }));
	set("long",@LONG
葛伦布是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
	);
	set("title", HIY "喇嘛" NOR);
	set("nickname", HIG "僧兵头领" NOR);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 20);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 1900);
	set("max_neili", 1900);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 40000);

	set_skill("lamaism", 50);
	set_skill("literate", 30);
	set_skill("force", 80);
	set_skill("mizong-neigong", 80);
	set_skill("dodge", 75);
	set_skill("shenkong-xing", 70);
	set_skill("parry", 60);
	set_skill("staff", 80);
	set_skill("xiangmo-chu", 70 );
	set_skill("hand", 60);
	set_skill("dashou-yin", 60);
	set_skill("sword", 60);
	set_skill("mingwang-jian", 60);

	map_skill("force", "mizong-neigong");
	map_skill("dodge", "shenkong-xing");
	map_skill("parry", "xiangmo-chu");
	map_skill("staff", "xiangmo-chu");
	map_skill("sword", "mingwang-jian");
	map_skill("hand",  "dashou-yin");

	prepare_skill("hand",  "dashou-yin");

	create_family("雪山寺", 5, "喇嘛");
	set("class", "bonze");

	set("coagents", ({
		([ "startroom" : "/d/xueshan/dating",
		   "id"	: "jinlun fawang", ]),
	}));

	setup();

	carry_object("/d/xueshan/obj/b-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();
	carry_object("/d/xueshan/obj/senggun")->wield();

	add_money("silver", 10);
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

	command("say 我就传你一些武功吧！");
	command("recruit " + ob->query("id"));

	if ((string)ob->query("class") != "bonze")
	{
		ob->set("title", "雪山派俗家弟子");
	} else
	{
		ob->set("title", YEL "小喇嘛" NOR);
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
