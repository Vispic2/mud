// /NPC meijian.c

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "lingjiu.h"

void greeting(object);
void init();
void create()
{
	set_name("梅剑", ({ "mei jian", "mei"}));
	set("long",
	    "这是个容貌姣好的女子，瓜子脸蛋，眼如点漆，清秀绝俗。\n"
	    "你总觉得在哪见过她。\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 23);
	set("int", 27);
	set("con", 25);
	set("dex", 24);

	set("qi", 3300);
	set("max_qi", 3300);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 30);

	set("combat_exp", 550000);
	set("score", 3000);
	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("hand", 120);
	set_skill("strike", 120);
	set_skill("sword", 160);

	set_skill("zhemei-shou", 120);
	set_skill("liuyang-zhang", 120);
 	set_skill("tianyu-qijian", 140);
	set_skill("yueying-wubu", 160);
	set_skill("lingjiu-xinfa", 160);

	map_skill("force", "lingjiu-xinfa");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike","liuyang-zhang");

	set("coagents", ({
		([ "startroom" : "/d/lingjiu/dating",
		   "id"	: "xu zhu" ]),
	}));

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}

void init()
{
	object ob;
 
	::init();
 
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	if (ob->query("family/family_name") == query("family/family_name")) 
	{
		message_vision("梅剑冲着$N点点头，微微笑了笑。\n",ob);
		return;
	}

	if (!(string)ob->query("family/family_name"))
	{
		message_vision("梅剑冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((string)ob->query("gender")=="女性")
	{
		message_vision("梅剑垂目沉思片刻, 说道：“好"
			       "吧, 我就收下你了。”\n",ob);
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		return;
	}
	else
	{
		message_vision("梅剑瞪着你看了半天,说道：“阁"
			       "下是否该去做做手术?”\n",ob);
		return;
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
